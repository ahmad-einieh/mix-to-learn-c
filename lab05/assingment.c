/* 
ahmad einieh
احمد عينية
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int *allNum, *r, *y;
    float sum = 0, avg;

    printf("Enter the number of courses:");
    scanf("%d", &num);
    y = r = allNum = (int *)malloc(num * sizeof(int));

    int temp;

    int i;
    for (i = 0; i < num; i++)
    {
        printf("Enter the grade of Course# %d:", (i + 1));
        scanf("%d", &temp);
        /*
        int q;
        for (q = 0; q < num; q++)
        {
            if (temp == allNum[q])
            {
                printf("Enter the grade of Course# %d:", (i + 1));
                scanf("%d", &temp);
            }
        }*/
        while (y <= r)
        {
            if (temp == *y)
            {
                printf("You have entered %d already\n", temp);
                printf("Enter the grade of Course# %d:", (i + 1));
                scanf("%d", &temp);
            }
            y++;
        }
        y = allNum;
        *r = temp;
        sum += temp;
        r++;
    }
    avg = sum / num;
    printf("The average of array elements :%.2f", avg);

    /*
    int loop;
    for (loop = 0; loop < num; loop++)
        printf("%d ", allNum[loop]);*/

    return 0;
}

/* 
ahmad einieh
احمد عينية
*/