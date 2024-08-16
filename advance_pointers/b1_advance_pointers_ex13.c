#include <stdio.h>
#include <stdlib.h>


struct node 
{
    int value;
    struct node *next;
};

// Function to insert into an ordered list
struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
    struct node **list_ptr = &list; // Pointer to pointer to the list

    // Printing the initial address of list and list_ptr
    printf("Initial list address: %p\n", (void *)list);
    printf("Initial list_ptr address: %p\n", (void *)list_ptr);

    // Traverse the list to find the right place to insert the new node
    while (*list_ptr != NULL) 
    {
        printf("list_ptr now points to node with value: %d, at address: %p\n", 
                (*list_ptr)->value, (void *)(*list_ptr));

        if ((*list_ptr)->value >= new_node->value)
        {
            break;
        }

        // Moving list_ptr to the next node
        list_ptr = &(*list_ptr)->next;
        printf("list_ptr changed to point to next node, address now: %p\n", 
                (void *)list_ptr);
    }

    // Inserting the new node
    new_node->next = *list_ptr;
    *list_ptr = new_node;

    // Print the address of the newly inserted node
    printf("New node with value: %d inserted at address: %p\n", 
            new_node->value, (void *)new_node);
    
    return (list); // Return the updated head of the list
}

//create a new node
struct node *create_node(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

// Helper function to print the list
void print_list(struct node *list)
{
    struct node *curr = list;
    if (curr == NULL)
    {
        printf("Empty List\n");
        return;
    }

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

int main(void)
{
    // Create a simple ordered list
    struct node *list = create_node(10);
    list->next = create_node(20);
    list->next->next = create_node(30);

    // Print the original list
    printf("Original list:\n");
    print_list(list);

    // Create a new node to insert
    struct node *new_node = create_node(25);

    // Insert the new node and print debug information
    printf("\nInserting new node with value %d\n", new_node->value);
    list = insert_into_ordered_list(list, new_node);

    // Print the modified list
    printf("\nModified list:\n");
    print_list(list);


    return (0);
}

/*
==========================================================================
Original list:
Node value: 10 at address: 0x55fc227eb2a0, next: 0x55fc227eb2c0
Node value: 20 at address: 0x55fc227eb2c0, next: 0x55fc227eb2e0
Node value: 30 at address: 0x55fc227eb2e0, next: (nil)

Inserting new node with value 25
Initial list address: 0x55fc227eb2a0
Initial list_ptr address: 0x7ffc17530c58
list_ptr now points to node with value: 10, at address: 0x55fc227eb2a0
list_ptr changed to point to next node, address now: 0x55fc227eb2a8
list_ptr now points to node with value: 20, at address: 0x55fc227eb2c0
list_ptr changed to point to next node, address now: 0x55fc227eb2c8
list_ptr now points to node with value: 30, at address: 0x55fc227eb2e0
New node with value: 25 inserted at address: 0x55fc227eb710

Modified list:
Node value: 10 at address: 0x55fc227eb2a0, next: 0x55fc227eb2c0
Node value: 20 at address: 0x55fc227eb2c0, next: 0x55fc227eb710
Node value: 25 at address: 0x55fc227eb710, next: 0x55fc227eb2e0
Node value: 30 at address: 0x55fc227eb2e0, next: (nil)

===========================================================================
Original list:
Empty List

Inserting new node with value 25
Initial list address: (nil)
Initial list_ptr address: 0x7fff23e659c8
New node with value: 25 inserted at address: 0x55f877e1a6b0

Modified list:
Node value: 25 at address: 0x55f877e1a6b0, next: (nil)
===========================================================================

*/