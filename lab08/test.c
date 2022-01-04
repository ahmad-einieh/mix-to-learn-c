#include <stdlib.h>
#include "mybmp.h"
#include <stdio.h>
Pixel **copy_pixels(Pixel **px, int h, int w)
{
    int i, j;
    Pixel **result = (Pixel **)malloc(h * sizeof(Pixel *));
    for (i = 0; i < h; i++)
    {
        result[i] = (Pixel *)malloc(w * sizeof(Pixel));
        for (j = 0; j < w; j++)
            result[i][j] = px[i][j];
    }
    return result;
}
int main()
{

    FileHead fh;
    ImageHead ih;
    Pixel **pixels, **grey, **red, **mirror;
    pixels = load_image("image.bmp", &fh, &ih);
    grey = copy_pixels(pixels, ih.image_height, ih.image_width);
    make_grey(grey, ih.image_height, ih.image_width, cGREEN);
    save_image("image-grey.bmp", &fh, &ih, grey);
    red = copy_pixels(pixels, ih.image_height, ih.image_width);
    redify(red, ih.image_height, ih.image_width);
    save_image("image-red.bmp", &fh, &ih, red);
    mirror = copy_pixels(pixels, ih.image_height, ih.image_width);
    hmirror(mirror, ih.image_height, ih.image_width);
    save_image("image-mirror.bmp", &fh, &ih, mirror);
    return 0;
}