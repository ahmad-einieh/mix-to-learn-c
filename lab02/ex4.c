#include <stdio.h>

int main()
{
    printf("%f\n", 22.0 / 7);
    printf("%.10f\n", 22.0 / 7);
    printf("%20.10f\n", 22.0 / 7);
    printf("%020.10f\n", 22.0 / 7);
    printf("%+.10f\n", 22.0 / 7);
    printf("%.10f%%\n", 22.0 / 7);
    printf("%e\n", 22.0 / 7);
    printf("%e\n", 2200.0 / 7);
    printf("%x\n", 31567);
    printf("%.4s\n", "Good Morning");
    printf("%10.4s\n", "Good Morning");

    return 0;
}