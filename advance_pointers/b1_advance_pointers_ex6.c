/*

This program is mostly copied from the b1_advance_pointers_notes3.c file.

The exercise requires me to modify the delect_from_list function so that it
uses only one pointer variable instead of two (curr and prev).


*/

#include <stdio.h>
#include <stdlib.h>

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

//modified from book
struct node *delete_from_list(struct node **list, int target)
{
    struct node *list_ptr = *list;

    // If the target is in the first node
    if ((list_ptr != NULL) && (list_ptr->value == target))
    {
        *list = list_ptr->next; // Update the head pointer
        free(list_ptr);         // Free the node
        return *list;           // Return the new head
    }

    // Traverse the list to find the target node
    while ((list_ptr != NULL) && (list_ptr->next != NULL))
    {
        if (list_ptr->next->value == target)
        {
            struct node *temp = list_ptr->next;
            list_ptr->next = temp->next; // Bypass the node to be deleted
            free(temp);                  // Free the node
            return *list;                // Return the (possibly updated) head
        }
        list_ptr = list_ptr->next;
    }

    // Target not found, return the unchanged list
    return *list;
}

//just quick test.
int main(void) 
{
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

    // Delete node with value 3
    list = delete_from_list(&list, 3);

    // Print the list after deletion
    printf("List after deleting 3:\n");

    struct node *list_ptr = list;
    while (list_ptr != NULL)
    {
        printf("%d->", list_ptr->value);
        list_ptr = list_ptr->next;
    }

    printf("\n");
    free(list);
    
    list = NULL;
    result = NULL;
    
    return (0);
}