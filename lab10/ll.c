#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void add_node(struct linked_list *list, char val)
{
    Node *nn = (Node *)calloc(1, sizeof(Node));
    nn->data = val;
    if (nn)
    {
        if (list->head == 0)
            list->head = nn;
        else
        {
            Node *p = list->head;
            while (p->next)
            {
                p = p->next;
            }
            p->next = nn;
        }
        printf("value %c has added\n", val);
    }
    else
        printf("value %c has not added\n", val);
}

void concat1(struct linked_list *list1, struct linked_list *list2)
{
    Node *p = list2->head;
    while (p)
    {
        add_node(list1, p->data);
        p = p->next;
    }
}
void concat2(struct linked_list *list1, struct linked_list *list2)
{
    if (list1->head == NULL)
        list1->head = list2->head;
    else
    {
        Node *p = list1->head;
        while (p->next)
            p = p->next;
        p->next = list2->head;
    }
}

void print_list(struct linked_list *list)
{
    Node *p = list->head;
    while (p)
    {
        printf("%c", p->data);
        p = p->next;
        if (p)
            printf("->");
    }
    printf("-|\n");
}