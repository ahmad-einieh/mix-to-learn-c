#include <stdio.h>
/*#include "ll2.h"*/
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct stack
{
    struct node *top;
};

struct stack stack1;

void push(char info)
{
    struct node *nn = (struct node *)calloc(1, sizeof(struct node));
    nn->data = info;
    if (!nn)
        return;
    nn->next = stack1.top;
    stack1.top = nn;
}
char pop()
{
    char result;
    if (!stack1.top)
        return 0;
    result = stack1.top->data;
    struct node *p = stack1.top;
    stack1.top = stack1.top->next;
    free(p);
    return result;
}
int isEmpty()
{
    return !stack1.top;
}

int main(int argc, char const *argv[])
{
    stack1.top = 0;
    char *a = (char *)calloc(1, sizeof(char));
    char ch;
    printf("enter your word: ");
    gets(a);

    /*printf("%i\n", isEmpty());*/
    while ((ch = *a++))
        push(ch);
    while ((ch = pop()))
        printf("%c", ch);

    return 0;
}
