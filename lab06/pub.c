#include "pub.h"
#include <stdio.h>
#include <stdlib.h>

struct publication readpub()
{
    struct publication result;
    printf("enter the publication type (B:book),(M:magazain): ");
    char c = getchar();
    result.ctype = c == 'b' ? Book : Magazien;
    printf("enter the title: ");
    gets(result.title);
    printf("enter number of pages: ");
    scanf("%d", &(result.nPages));
    printf("enter cover type(h:hardcover) , (p:paperback): ");
    c = getchar();
    result.ctype = c == 'h' ? HAARDCOVER : PAPERBACK;
    printf("enter the price: ");
    scanf("%f", &(result.price));
    if (result.pType == Book)
    {
        printf("enter the issn of book: ");
        scanf("%d", &(result.id.issn));
    }
    else
    {
        printf("enter the issn: ");
        scanf("%d", &(result.id.magid.issn));
        printf("enter the volum: ");
        scanf("%d", &(result.id.magid.vol));
        printf("enter the issue");
        scanf("%d", &(result.id.magid.issue));
    }

    return result;
}

int findpub(struct publication *p, struct pubList pl)
{
    int i;
    for (i = 0; i < pl.count; i++)
    {
        if (
            (p->pType == Book && pl.list[i].pType == Book && p->id.issn == pl.list[i].id.issn) ||
            (p->pType == Magazien && pl.list[i].pType == Magazien && p->id.issn == pl.list[i].id.magid.issn &&
             p->id.magid.vol == pl.list[i].id.magid.vol && p->id.magid.issue == pl.list[i].id.magid.issue

             ))
            return i;
    }
    return -1;
}

struct pubList getallbooks(struct pubList pl)
{
    struct pubList result;
    result.count = 0;
    int i, j;
    for (i = 0; i < pl.count; i++)
    {
        if (pl.list[i].pType == Book)
        {
            result.count++;
        }
    }
    result.list = (struct publication *)malloc(result.count * sizeof(struct publication));
    if (pl.list)
    {
        for (i = 0, j = 0; i < pl.count; i++)
        {
            if (pl.list[i].pType == Book)
            {
                result.list[j++] = pl.list[i];
            }
        }
    }

    return result;
}
