#include <stdio.h>
int main()
{
    char str[1000];
    int c = 0;
    printf("enter string: ");
    gets(str);
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    while (str[c])
    {

        if (str[c] == 'a' || str[c] == 'A')
        {
            a++;
        }
        else if (str[c] == 'e' || str[c] == 'E')
        {
            e++;
        }
        else if (str[c] == 'i' || str[c] == 'I')
        {
            i++;
        }
        else if (str[c] == 'o' || str[c] == 'O')
        {
            o++;
        }
        else if (str[c] == 'u' || str[c] == 'U')
        {
            u++;
        }
        c++;
        /*
        or we can use switch
        */
    }
    printf("A/a:%i\tE/e:%i\tI/i:%i\tO/o:%i\tU/u:%i", a, e, i, o, u);
    return 0;
}