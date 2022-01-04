#include <stdio.h>
#include "mat.h"

void fill_matrix(int m[d][d])
{
    int i;
    int j;
    for (i = 0; i < d; i++)
    {
        for (j = 0; i < d; j++)
        {
            printf("\nEnter element [%d,%d]:", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    printf("\n");
}

void transpose(int t[d][d], int s[d][d])
{
    int i;
    int j;
    for (i = 0; i < d; i++)
    {
        for (j = 0; i < d; j++)
        {
            t[i][j] = s[j][i];
        }
    }
}

void print_matrix(int m[d][d])
{
    int i;
    int j;
    for (i = 0; i < d; i++)
    {
        for (j = 0; i < d; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}