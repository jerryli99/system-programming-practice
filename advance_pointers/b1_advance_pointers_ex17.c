#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 100

void swap(void *item1, void *item2, size_t size);

int partition(void *base, size_t size, int low, int high,
              int (*compare)(const void *, const void *));

void qsort_aux(void *base, size_t size, int low, int high,
              int (*compare)(const void *, const void *));

void qsort(void *base, size_t nmemb, size_t size, 
           int (*compare)(const void *, const void *));

int compare_integer(const void *num1, const void *num2);


int main(void)
{
    int array[ARRAY_SIZE];
    size_t array_size = sizeof(array) / sizeof(array[0]);

    // Populate the array with some values (for simplicity, we use a pattern here)
    for (int index = 0; index < array_size; index++) 
    {
        array[index] = rand() % array_size;  // Fill with random integers between 0 and 99
    }

    // Print the array before sorting
    printf("Before sorting (last 50 elements):\n");
    for (int index = 0; index < array_size; index++) 
    {
        printf("%d ", array[index]);
        if (index % 10 == 9) 
        {
            printf("\n");  // New line after every 10 elements for readability
        }
    }

    // Call qsort to sort only the last 50 elements (from index 50 to 99)
    qsort(&array[50], 50, sizeof(int), compare_integer);

    // Print the array after sorting the last 50 elements
    printf("\nAfter sorting (last 50 elements):\n");
    for (int index = 0; index < 100; index++) 
    {
        printf("%d ", array[index]);
        if (index % 10 == 9) 
        {
            printf("\n");  // New line after every 10 elements for readability
        }
    }

    return (0);
}

/**
 * @brief swap two items in different heap memories.
 * 
 * @param item1 a pointer to void type.
 * @param item2 a pointer to void type.
 * @param size size_t representing the size of the item to swap
 * 
 * @return void.
 */
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

/**
 * @brief Partition the array to be sorted.
 * 
 * @param base a pointer to void representing pointer to an array.
 * @param size size_t represeting the size of each elements in the array.
 * @param low an integer represeting the low index of the array.
 * @param high an integer represting the high index of the array.
 * @param compare a function pointer with 2 args for comparison. Both
 *                args take in a pointer constant void. 
 * 
 * @return returns the partition index 
 */
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
            swap((char *)base + (index * size), 
                 curr, 
                 size); 
        }      
    }
    swap((char *)base + ((index + 1) * size), 
         (char *)base + (high * size), 
         size);

    return (index + 1);
}

/**
 * @brief a helper function for recursively doing the array partitions and 
 *        then the sorting.
 * 
 * @param base a pointer to void representing pointer to an array.
 * @param size size_t represeting the size of each elements in the array.
 * @param low an integer represeting the low index of the array.
 * @param high an integer represting the high index of the array.
 * @param compare a function pointer with 2 args for comparison. Both
 *                args take in a pointer constant void.
 * 
 * @return void.
 */
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

/**
 * @brief the quick sort function
 * 
 * @param base a pointer to void representing pointer to an array.
 * @param nmemb a size_t type representing the number of elements to be sorted
 * @param size a size_t type representing the size of each array element.
 * @param compare a function pointer with 2 args for comparison. Both
 *                args take in a pointer constant void.
 * 
 * @return void.
 */
void qsort(void *base, size_t nmemb, size_t size,
           int (*compare)(const void *, const void *))
{
    qsort_aux(base, size, 0, nmemb - 1, compare);
}

/**
 * @brief A function to compare integers
 * 
 * @param num1 a pointer to constant void type
 * @param num2 a pointer to constant void type
 * 
 * @return An integer less than, equal to, or greater than zero if the first 
 *         integer is found, respectively, to be less than, equal to, or 
 *         greater than the second integer.
 */
int compare_integer(const void *num1, const void *num2)
{
    return (*(int*)num1 - *(int*)num2);
}


/*
OUTPUT:
Before sorting (last 50 elements):
83 86 77 15 93 35 86 92 49 21 
62 27 90 59 63 26 40 26 72 36 
11 68 67 29 82 30 62 23 67 35 
29 2 22 58 69 67 93 56 11 42 
29 73 21 19 84 37 98 24 15 70 
13 26 91 80 56 73 62 70 96 81 
5 25 84 27 36 5 46 29 13 57 
24 95 82 45 14 67 34 64 43 50 
87 8 76 78 88 84 3 51 54 99 
32 60 76 68 39 12 26 86 94 39 

After sorting (last 50 elements):
83 86 77 15 93 35 86 92 49 21 
62 27 90 59 63 26 40 26 72 36 
11 68 67 29 82 30 62 23 67 35 
29 2 22 58 69 67 93 56 11 42 
29 73 21 19 84 37 98 24 15 70 
3 5 5 8 12 13 13 14 24 25 
26 26 27 29 32 34 36 39 39 43 
45 46 50 51 54 56 57 60 62 64 
67 68 70 73 76 76 78 80 81 82 
84 84 86 87 88 91 94 95 96 99


*/