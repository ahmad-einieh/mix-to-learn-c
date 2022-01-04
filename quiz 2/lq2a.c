#include <stdio.h>
#include <stdlib.h>

/* Implement the two functions below */
#include <stdio.h>
/* Takes a str that made up of words separated by a single space.
   Returns a pointer to the first word in str.
   Sets n to the length of the returned word.*/
int k;
char *get_word(char *str, int *n)
{
    static char s[1000];
    int i = 0;
    char ch;
    static int j = 0;
    while ((ch = str[i++]) != ' ')
    {
        s[j++] = ch;
    }
    n = &j;
    k = j;
    return s;
}

int count(char *str)
{
    char ch;
    char *s;
    int j = 0;
    int i = 0;
    int count = 1;
    while ((ch = str[j++]) != '\0')
    {
        if (ch == ' ' || ch == '\0')
            count++;
    }
    return count;
}

/* Takes a str that made up of words separated by a single space.
   Returns 1 if all words are unique (i.e. appears one time)
   and 0 otherwise */

int all_unique(char *str)
{
    int ss = count(str);
    char ch;
    char *s[ss];
    int j = 0;
    int i = 0;
    char *st;

    while ((ch = str[j++]) != '\0')
    {
        if (j == 0)
            st = get_word(str + j, 0);
        if (ch == ' ' || ch == '\0')
        {
            st = get_word(str + j + 1, 0);
        }
        s[i++] = st;
    }
    char *ssss = s[0];
    for (i = 1; i < ss; i++)
    {

        if (ssss == s[i])
        {
            return 0;
        }
        ssss = s[i];
    }

    return 1;
}

int main()
{
    printf("%d\n", all_unique("this example returns one"));
    printf("%d\n", all_unique("but this one does not return one"));
    return 0;
}