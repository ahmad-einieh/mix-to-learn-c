#include "mybmp.h"
#include <stdio.h>
#include <stdlib.h>

Pixel **load_image(char *fname, FileHead *fh, ImageHead *ih)
{
    Pixel **result = 0;
    int i, pda;
    FILE *f = fopen(fname, "rb");
    if (f)
    {
        fread(fh, sizeof(FileHead), 1, f);
        fread(ih, sizeof(ImageHead), 1, f);
        result = (Pixel **)malloc(sizeof(Pixel *) * ih->image_height);
        pda = (4 - ((ih->image_width * sizeof(Pixel)) % 4)) % 4;
        for (i = ih->image_height - 1; i >= 0; i--)
        {
            result[i] = (Pixel *)malloc(sizeof(Pixel) * ih->image_width);
            fread(result[i], sizeof(Pixel), ih->image_width, f);
            fseek(f, pda, SEEK_CUR);
        }
        fclose(f);
    }
    return result;
}
void make_grey(Pixel **image, int h, int w, Channel c)
{
    int i, j;
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            if (c == cRED)
                image[i][j].blue = image[i][j].green = image[i][j].red;
            else if (c == cGREEN)
                image[i][j].blue = image[i][j].red = image[i][j].green;
            else
                image[i][j].red = image[i][j].green = image[i][j].blue;
}

void redify(Pixel **image, int h, int w)
{
    int i, j;
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
        {
            image[i][j].green /= 2;
            image[i][j].blue /= 2;
            image[i][j].red += (255 - image[i][j].red) / 2;
        }
}

int save_image(char *fname, FileHead *fh, ImageHead *ih, Pixel **image)
{
    int pda = (4 - ((ih->image_width * sizeof(Pixel)) % 4)) % 4;
    int i;
    FILE *f = fopen(fname, "wb");
    fwrite(fh, sizeof(FileHead), 1, f);
    fwrite(ih, sizeof(ImageHead), 1, f);
    for (i = ih->image_height - 1; i >= 0; i--)
    {
        fwrite(image[i], sizeof(Pixel), ih->image_width, f);
        fseek(f, pda, SEEK_CUR);
    }
    fclose(f);
    return 1;
}

void hmirror(Pixel **image, int h, int w)
{
    int i, j;
    Pixel temp;
    for (i = 0; i < h; i++)
        for (j = 0; j < w / 2; j++)
        {
            int swaper = w - 1 - j;
            temp = image[i][j];
            image[i][j] = image[i][swaper];
            image[i][swaper] = temp;
        }
}