#include <stdio.h>

float findLowest(float a, float b, float c, float d)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    if (d < min)
        min = d;

    return min;
}
void Avg(float a, float b, float c, float d)
{
    float avrage = (a + b + c + d - findLowest(a, b, c, d)) / 3.0;
    printf("the avrage is: %f", avrage);
}

int main()
{
    float g1, g2, g3, g4;
    printf("enter grade 1: ");
    scanf("%f", &g1);
    printf("enter grade 2: ");
    scanf("%f", &g2);
    printf("enter grade 3: ");
    scanf("%f", &g3);
    printf("enter grade 4: ");
    scanf("%f", &g4);

    Avg(g1, g2, g3, g4);
    return 0;
}
