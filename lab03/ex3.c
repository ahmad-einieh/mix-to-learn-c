#include <stdio.h>
int main()
{
    int n;
    printf("enter how many star: ");
    scanf("%i", &n);
    int i;
    int j;
    for (i = n; i > 0; i--)
    {
        for (j = i; j >= 1; j--)
            printf("%c", '*');
        printf("\n");
    }

    for (i = 2; i <= n; i++)
    {
        for (j = i; j >= 1; j--)
            printf("%c", '*');
        printf("\n");
    }

    return 0;
}