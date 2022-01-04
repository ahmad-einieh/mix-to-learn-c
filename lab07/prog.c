#include <stdio.h>
#include <stdlib.h>
#include "prog.h"
int main()
{

    FileStats *fsp;
    char **lines;
    fsp = process_file("wcs.txt");

    printf("File size = %d\n", fsp->total_chars);
    printf("Number of letters = %d\n", fsp->letters_count);
    printf("Number of Words = %d\n", fsp->words_count);
    printf("Number of lines = %d\n", fsp->lines_count);
    printf("Length of longest line = %d\n", fsp->max_line_length);

    lines = get_lines("wcs.txt");

    write_rev("wcs-rev.txt", lines, fsp->lines_count);

    return 0;
}

int is_letter(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

FileStats *process_file(char *fn)
{
    FileStats *fs = 0;
    FILE *f = fopen(fn, "r");
    if (f)
    {
        fs = (FileStats *)calloc(1, sizeof(FileStats));
        if (fs)
        {
            char c;
            int inword = 0, len = 0;
            do
            {
                c = fgetc(f);
                if (c != EOF)
                {
                    fs->total_chars++;
                    len++;
                }
                if (is_letter(c))
                {
                    fs->letters_count++;
                    inword = 1;
                }
                else
                {
                    if (inword)
                        fs->words_count++;
                    inword = 0;
                }
                if (c == '\n' || c == EOF)
                {
                    fs->lines_count++;
                    if (len > fs->max_line_length)
                        fs->max_line_length = len;
                    len = 0;
                }

            } while (c != EOF);
        }
        fclose(f);
    }
    else
        printf("connot to open file %s \n", fn);
    return fs;
}

char **get_lines(char *fn)
{
    char **result = 0;
    FILE *f = fopen(fn, "r");
    if (f)
    {
        FileStats *fs = process_file(fn);
        result = (char **)malloc(fs->lines_count * sizeof(char *));
        if (result)
        {
            int i;
            for (i = 0; i < fs->lines_count; i++)
            {
                result[i] = (char *)calloc(fs->max_line_length + 1, 1);
                fgets(result[i], fs->max_line_length + 1, f);
            }
        }
        fclose(f);
    }

    return result;
}
void write_rev(char *fn, char **lines, int count)
{
    int i;
    FILE *f = fopen(fn, "w");
    for (i = count - 1; i >= 0; i--)
    {
        fputs(lines[i], f);
        if (i)
            fprintf(f, "\n");
    }
    fclose(f);
}