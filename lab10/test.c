#include <stdio.h>
#include "ll.h"

int main()
{
    struct linked_list list1;
    struct linked_list list2;
    list1.head = list2.head = NULL;
    add_node(&list1, 'A');
    add_node(&list1, 'B');
    add_node(&list1, 'C');
    add_node(&list2, 'D');
    add_node(&list2, 'E');
    add_node(&list2, 'F');
    print_list(&list1);
    print_list(&list2);
    concat1(&list1, &list2);
    print_list(&list1);
    add_node(&list1, 'G');
    print_list(&list1);
    return 0;
}