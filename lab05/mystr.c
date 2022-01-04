#include "mystr.h"
#include <stdio.h>
#include <stdlib.h>

int slen(const char *s)
{
    int count = 0;
    while (*s)
    {
        count++;
    }
    return count;
}
char *scat(const char *s1, char *s2)
{
    char *result;
    int len1 = slen(s1), len2 = slen(s2);
    result = (char *)malloc(len1 + len2 + 1);
    if (result)
    {
        while (*s1)
        {
            *result = *s1;
            result++;
            s1++;
        }
        while (*s2)
        {
            *result = *s2;
            result++;
            s2++;
        }
        *result = 0;
    }
    return result;
}
int scmp(const char *s1, const char *s2)
{
    while (*s1 == *s2 && *s1)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
char *sdup(const char *str)
{
    char *result, *r;
    r = result = (char *)malloc(slen(str) + 1);
    if (result)
    {
        while (*str)
        {
            *r = *str;
            r++;
            str++;
        }
        *r = 0;
    }
    return result;
}
char *srev(const char *str)
{
    char *reslut, *r;
    reslut = (char *)malloc(slen(str) + 1);
    if (reslut)
    {
        r = reslut + slen(str);
        *r-- = 0;
        while (*str)
        {
            *r = *str;
            r--;
            str++;
        }
    }
    return reslut;
}