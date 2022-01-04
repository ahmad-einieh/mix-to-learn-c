#if !defined LL
#define LL

struct node
{
    char data;
    struct node *next;
};
typedef struct node Node;

struct linked_list
{
    struct node *head;
};

/*typedef struct linked_list LL;*/

void add_node(struct linked_list *list, char val);
void concat1(struct linked_list *list1, struct linked_list *list2);
void concat2(struct linked_list *list1, struct linked_list *list2);
void print_list(struct linked_list *list);
#endif