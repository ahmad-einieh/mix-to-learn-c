#include <stdio.h>
int main()
{
    int i;
    float term;
    float sum = 0.0;

    for (i = 0; i <= 2867; i++)
    {
        int sign = (i + 1) % 2 == 0 ? 1 : -1;
        int sq = i * i;
        int down = (i + 5) * (i + 5);
        term = (float)sign * sq / down;
        sum += term;
    }
    printf("%f\n", sum);
    i = 1;
    sum = 0;
    while ((sum < 0 ? -sum : sum) < 0.5)
    {
        int sign = (i + 1) % 2 == 0 ? 1 : -1;
        int sq = i * i;
        int down = (i + 5) * (i + 5);
        term = (float)sign * sq / down;
        sum += term;
        i++;
    }
    sum -= term;
    printf("%d\t%f\n", i - 2, sum);

    return 0;
}