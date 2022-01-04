#include <stdio.h>
#define TAB '\t'

const int CODE = 215;
int main()
{
    const char STR[] = "CSC";
    printf("course: %s%c%d", STR, TAB, CODE);
    return 0;
}