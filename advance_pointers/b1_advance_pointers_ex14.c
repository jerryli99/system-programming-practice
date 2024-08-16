#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

//delete a node with the target value from the list
/*
Notes:
doing something like (*list_ptr) in this case is like 
accessing the current node directly when list_ptr is just 
a pointer to a struct node.

So naturally, I can do (*list_ptr)->value and (*list_ptr)->next.
But, but, (*list_ptr)->next will not directly update list_ptr if I
simply do list_ptr = (*list_ptr)->next. I will no longer have a pointer 
to the previous node's next pointer.

By doing the address of (*list_ptr)->next, which is &(*list_ptr)->next,
I will then get the next node's address.

I think this code is cleaner than the one in b1_advance_pointers_ex6.c
*/
void delete_from_list(struct node **list, int target)
{
    struct node **list_ptr = list; //Pointer to pointer to the list 
    struct node *temp; //Temp pointer to hold the node to be deleted

    while (*list_ptr != NULL)
    {
        if ((*list_ptr)->value == target)
        {
            temp = *list_ptr; //Store the node to be deleted
            *list_ptr = (*list_ptr)->next; //Remove the node from the list
            free(temp); //Free the memory of the deleted node
            return;
        }
        list_ptr = &(*list_ptr)->next;
    }
    // If the target is not found, simply return
    return;
}

struct node *create_node(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

void print_list(struct node *list)
{
    struct node *curr = list;
    while (curr != NULL)
    {
        printf("Node value: %d at address: %p, next: %p\n", 
                curr->value, (void *)curr, (void *)curr->next);
        curr = curr->next;
    }
    return;
}

// free the entire linked list
void free_list(struct node *list)
{
    struct node *temp;
    while (list != NULL) 
    {
        temp = list;         // Store the current node
        list = list->next;   // Move to the next node
        free(temp);          // Free the current node
    }
    return;
}

int main()
{
    // Create a simple ordered list
    struct node *list = create_node(10);
    list->next = create_node(20);
    list->next->next = create_node(30);

    // Print the original list
    printf("Original list:\n");
    print_list(list);

    // Delete a node with value 20
    printf("\nDeleting node with value 20\n");
    delete_from_list(&list, 20);

    // Print the modified list
    printf("\nModified list:\n");
    print_list(list);

    // Free the remaining list
    free_list(list);

    return (0);
}

/*
OUTPUT:

Original list:
Node value: 10 at address: 0x557f33c0a2a0, next: 0x557f33c0a2c0
Node value: 20 at address: 0x557f33c0a2c0, next: 0x557f33c0a2e0
Node value: 30 at address: 0x557f33c0a2e0, next: (nil)

Deleting node with value 20

Modified list:
Node value: 10 at address: 0x557f33c0a2a0, next: 0x557f33c0a2e0
Node value: 30 at address: 0x557f33c0a2e0, next: (nil)


*/