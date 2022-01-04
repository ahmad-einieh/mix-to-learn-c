#include <stdio.h>

struct student
{
    int id;
    char name[1000];
    float gpa;
};

int main()
{
    int n, i;
    printf("enter numers of students: ");
    scanf("%d", &n);
    struct student students[n];

    for (i = 0; i < n; i++)
    {
        printf("enter ID of student %d: ", i + 1);
        scanf("%d", &students[i].id);
        printf("enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("enter GPA of student %d: ", i + 1);
        scanf("%f", &students[i].gpa);
    }

    struct student s1 = students[0];

    for (i = 1; i < n; i++)
    {

        if (students[i].gpa > s1.gpa)
            s1 = students[i];
    }
    printf("%s\n", s1.name);

    for (i = 0; i < n; i++)
    {
        if (students[i].id == s1.id)
        {
        }
        else
            printf("%s\n", students[i].name);
    }

    return 0;
}