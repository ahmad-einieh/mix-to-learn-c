#include <stdio.h>
#include "mat.h"

int main()
{
    int m[d][d];
    fill_matrix(m);
    print_matrix(m);

    int tm[d][d];
    transpose(tm, m);
    print_matrix(tm);

    return 0;
}