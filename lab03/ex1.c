#include <stdio.h>
int main()
{
    char s[1000];
    int i = 0;
    printf("enter string: ");
    gets(s);
    //scanf("%s", s);
    while (s[i] /*or s[i] != '\0'*/)
    {
        if (i == 0 || s[i - 1] == ' ')
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] -= 'a' - 'A';
            }
        }
        else
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 'a' - 'A';
            }
        }
        i++;
    }
    printf("%s\n", s);
    return 0;
}