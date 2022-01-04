#include "pub.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    printf("enter the number of publications: ");
    scanf("%d", &n);
    struct pubList pl;
    pl.count = 0;

    pl.list = (struct publication *)malloc(n * sizeof(struct publication));
    if (pl.list)
    {
        for (i = 0; i < n; i++)
        {
            struct publication p = readpub();
            if (findpub(&p, pl) == -1)
            {
                pl.list[pl.count++] = p;
            }
            else
                i--;
        }
        struct pubList bl = getallbooks(pl);
        float totalPrice = 0;
        for (i = 0; i < bl.count; i++)
            totalPrice += bl.list[i].price;
        printf("the total price of all books = SR %.2f\n", totalPrice);
    }

    return 0;
}