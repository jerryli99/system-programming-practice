#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int value;
    struct node *next;
};


struct node *find_last(const struct node *list, int value)
{
    const struct node *list_ptr = NULL;
    const struct node *last = NULL;

    list_ptr = list;


    while (list_ptr != NULL)
    {
        if (list_ptr->value == value) 
        {
            last = list_ptr;
        }
        list_ptr = list_ptr->next;
    }

    return ((struct node *)(last));
}


int main(void)
{
    // Creating nodes
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));

    // Assigning values and setting up the linked list
    head->value = 1;
    head->next = second;

    second->value = 2;
    second->next = third;

    third->value = 1;
    third->next = fourth;

    fourth->value = 3;
    fourth->next = NULL;

    // Testing the find_last function
    struct node *result = find_last(head, 1);
    if (result != NULL)
    {
        printf("Last occurrence of 1 is at node with value: %d\n", result->value); // Should print 1
    }
    else
    {
        printf("Value 1 not found\n");
    }

    result = find_last(head, 2);
    if (result != NULL)
    {
        printf("Last occurrence of 2 is at node with value: %d\n", result->value); // Should print 2
    }
    else
    {
        printf("Value 2 not found\n");
    }

    result = find_last(head, 3);
    if (result != NULL)
    {
        printf("Last occurrence of 3 is at node with value: %d\n", result->value); // Should print 3
    }
    else
    {
        printf("Value 3 not found\n");
    }

    result = find_last(head, 4);
    if (result != NULL)
    {
        printf("Last occurrence of 4 is at node with value: %d\n", result->value);
    }
    else
    {
        printf("Value 4 not found\n");  // Should print "Value 4 not found"
    }

    // Freeing the allocated memory
    free(head);
    free(second);
    free(third);
    free(fourth);


    return (0);
}