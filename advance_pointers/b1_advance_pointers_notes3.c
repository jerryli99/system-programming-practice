#include <stdio.h>
#include <stdlib.h>

//This does not work because when a structure has a
//member that points to the same kind of structure, 
//as node does, we are required to use a structure tag.
//Without the node tag, we'd have no way to declare 
//the type of next.

// typedef struct node {
//     int value;
//     Node *next;
// } Node;


//This will work
struct node 
{
    int value;
    struct node *next;
};

struct node *add_to_list(struct node *list, int value) 
{
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) 
    {
        printf("Errpr: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->next = list;
    return (new_node);
}

struct node *read_numbers(void) 
{
    struct node *first = NULL;
    int value;
    printf("Enter a series of integers (0 to terminate): ");
    for (;;) 
    {
        scanf("%d\n", &value);
        if (value == 0) 
        {
            return (first);
        }
        first = add_to_list(first, value);
    }
}

//even though list is a copy of the original list pointer,
//there is no harm to add a const
struct node *search_list(const struct node *list, int target) 
{   
    const struct node *node_ptr;

    for (node_ptr = list; node_ptr != NULL; node_ptr = node_ptr->next) 
    {
        if (node_ptr->value == target) 
        {
            return ((struct node*) node_ptr);
        }
    }

    return (NULL);
}


//another version of search_list copied from textbook.
// struct node *search_list(struct node *list, int target) 
// {
//     while (list != NULL && list->value != target)
//     {
//         list = list->next;
//     }
//     return list;
// }

struct node *delete_from_list(struct node *list, int target)
{
    struct node *curr = NULL;
    struct node *prev = NULL;

    for (curr = list; 
        (curr != NULL) && (curr->value != target); 
         prev = curr, curr = curr->next);

    //target not found
    if (curr == NULL) 
    {
        return (list);
    }

    //target is in the first node
    if (prev == NULL) 
    {
        list = list->next;
    } 
    else  //target is in some other node
    {
        prev->next = curr->next;
    }

    free(curr);
    return (list);
}


int main(void) 
{
    // struct node *first = NULL;
    // struct node *new_node = NULL;
    // new_node = malloc(sizeof(struct node));

    // (*new_node).value = 10;
    // printf("%d\n", new_node->value); //syntax sugar
    // new_node->next = first;
    // first = new_node;
    //now first and new_node both point to the same heap address.

    //add another node
    //since first is pointing to the same heap address as new_node,
    //we can reassign new_node pointing to a new heap allocated address
    // new_node = malloc(sizeof(struct node));
    // new_node->value = 20;

    //now new_node is then "linked" to first
    // new_node->next = first;
    // //
    // first = new_node;

    //make a function to generalize this behavior
    struct node *list = NULL;
    struct node *result = NULL;
    list = read_numbers();

    if (list == NULL) {
        printf("nothing added to list");
    }

    result = search_list(list, 40);
    
    if (result == NULL) {
        printf("target not in list");
    }

    printf("found it: %d!\n", result->value);

    free(list);
    
    list = NULL;
    result = NULL;
    
    return (0);
}