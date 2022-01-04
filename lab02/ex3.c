#include <stdio.h>
#include <math.h>
int main()
{
    const float PI = 3.14;
    printf("enter the circle radius > ");
    float radius;
    scanf("%f", &radius);
    printf("enter the circle color> ");
    char color[20];
    scanf("%s", color);
    /*gets(color) for safe string but need some review*/
    float area = radius * radius * M_PI /* OR PI with-ansi*/;
    printf("the %s circle area = %.2f", color, area);
    return 0;
}