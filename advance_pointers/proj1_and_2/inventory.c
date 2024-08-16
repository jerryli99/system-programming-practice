/*
Most of the code was copied from the book. 
I am required to dynamically allocate the inventory array and later reallocate
when it fills up.

Use malloc to initially to allocate enough space for an array of 10 
part structures. When the array has no more room for new parts, use
realloc to double its size. Repeat the doubling step each time the
array becomes full.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

struct part *inventory = NULL;

int inventory_size = 10; 
int num_parts = 0;  //number of parts currently stored

//-------------------------My Update---------------------------------------
void swap(void *item1, void *item2, size_t size);

int partition(void *base, size_t size, int low, int high,
              int (*compare)(const void *, const void *));

void qsort_aux(void *base, size_t size, int low, int high,
              int (*compare)(const void *, const void *));

void qsort(void *base, size_t nmemb, size_t size, 
           int (*compare)(const void *, const void *));
//-------------------------------------------------------------------------

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int compare_parts(const void *p, const void *q);

/*
 * main: Prompts the user to enter an operation code,    
 *       then calls a function to perform the requested   
 *       action. Repeats until the user enters the        
 *       command 'q'. Prints an error message if the user 
 *       enters an illegal code.                         
 */
int main(void)
{
    char code;
    int running = 1;  // Flag to control the loop

    // Allocate memory for the inventory
    inventory = malloc(sizeof(struct part) * inventory_size);
    if (inventory == NULL) {
        printf("Error, malloc failed\n");
        exit(EXIT_FAILURE);
    }

    while (running) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');  // Skip to end of line

        switch (code) {
            case 'i': 
                insert();
                break;
            case 's': 
                search();
                break;
            case 'u': 
                update();
                break;
            case 'p': 
                print();
                break;
            case 'q': 
                running = 0;  // Set flag to terminate the loop
                break;
            default:  
                printf("Illegal code\n");
                break;
        }

        printf("\n");
    }

    // Free the allocated memory before exiting
    free(inventory);
    inventory = NULL;
    
    return 0;
}

//-----------------My Update---------------------------------------------
//code was copied from the b1_advance_pointers_ex17.c
void swap(void *item1, void *item2, size_t size) 
{
    void *temp = malloc(size);
    if (temp == NULL) 
    {
        exit(EXIT_FAILURE);
    }

    memcpy(temp, item1, size);
    memcpy(item1, item2, size);
    memcpy(item2, temp, size);

    free(temp);
}

//get the index of the pivot after partitioning
int partition(void *base, size_t size, int low, int high,
              int (*compare)(const void *, const void *))
{
    char *pivot = (char *)base + high * size;
    int index = low - 1;

    for (int count = low; count < high; count++)
    {
        char *curr = (char *)base + count * size;
        if (compare(curr, pivot) < 0)
        {
            index++;
            swap((char *)base + index * size, curr, size); 
        }      
    }
    swap((char *)base + (index + 1) * size, (char *)base + high * size, size);
    return (index + 1);
}

void qsort_aux(void *base, size_t size, int low, int high,
               int (*compare)(const void *, const void *))
{
    if (low < high)
    {
        int partition_index = partition(base, size, low, high, compare);
        qsort_aux(base, size, low, partition_index - 1, compare);
        qsort_aux(base, size, partition_index + 1, high, compare);
    }
    return;
}


void qsort(void *base, size_t nmemb, size_t size,
           int (*compare)(const void *, const void *))
{
    qsort_aux(base, size, 0, nmemb - 1, compare);
}
//--------------------------------------------------------------------


/*
 * find_part: Looks up a part number in the inventory     
 *            array. Returns the array index if the part  
 *            number is found; otherwise, returns -1.     
 */
int find_part(int number)
{
  int index;

  for (index = 0; index < num_parts; index++)
    if (inventory[index].number == number)
      return (index);
  return (-1);
}

/*
 * insert: Prompts the user for information about a new  
 *         part and then inserts the part into the       
 *         database. Prints an error message and returns 
 *         prematurely if the part already exists or the 
 *         database is full.                         
 */
void insert(void)
{
    int part_number;

    //----My updat: If inventory is full, double its size via realloc-------
    if (num_parts == inventory_size) 
    {
        inventory_size = inventory_size * 2;
        inventory = realloc(inventory, 
                            sizeof(struct part) * inventory_size);

        if (inventory == NULL) 
        {
            printf("Error, realloc failed\n");
            exit(EXIT_FAILURE);
        }
    }
    //------------------------------------------------------------------------
    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);

    num_parts++;
}

/*
 * search: Prompts the user to enter a part number, then 
 *         looks up the part in the database. If the part
 *         exists, prints the name and quantity on hand; 
 *         if not, prints an error message.           
*/
void search(void)
{
    int index, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    index = find_part(number);
    if (index >= 0) 
    {
        printf("Part name: %s\n", inventory[index].name);
        printf("Quantity on hand: %d\n", inventory[index].on_hand);
    } 
    else
    {
        printf("Part not found.\n");
    }
}

/*
 * update: Prompts the user to enter a part number.     
 *         Prints an error message if the part doesn't   
 *         exist; otherwise, prompts the user to enter    
 *         change in quantity on hand and updates the     
 *         database.                                      
 */
void update(void)
{
    int index, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    index = find_part(number);
    if (index >= 0) 
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[index].on_hand += change;
    } 
    else
    {
        printf("Part not found.\n");
    }
}

/*
 * print: Prints a listing of all parts in the database,  
 *        showing the part number, part name, and         
 *        quantity on hand. Parts are printed in the      
 *        order in which they were entered into the       
 *        database.                                       
 */
void print(void)
{
    //-------------------------My update--------------------------------
    qsort(inventory, num_parts, sizeof(struct part), compare_parts);

    printf("Part Number   Part Name                  "
            "Quantity on Hand\n");
    for (int index = 0; index < num_parts; index++)
    {
        printf("%7d       %-25s%11d\n", inventory[index].number,
            inventory[index].name, inventory[index].on_hand);
    }
    //-------------------------------------------------------------------
}

/* 
 * Comparison function for qsort to sorts the parts in 
 * ascending order of part numbers 
 */
int compare_parts(const void *p, const void *q)
{
    return ((struct part *)p)->number - ((struct part *)q)->number;
}