#include <stdio.h>

#define MAX_INPUT_N 30


void max_min(const int *const array, const int array_size, int *max_ptr, 
             int *min_ptr);

int main(int argc, char *argv[]) {
    int size = 0;
    int array[MAX_INPUT_N] = {0};
    int max_num = 0, min_num = 0;

    FILE *file_input = fopen(argv[1], "r");
    FILE *file_output = fopen(argv[2], "w");

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    if (file_input == NULL || file_output == NULL) {
        perror("Error opening files");
        return 1;
    }

    fscanf(file_input, "%d", &size); // Read the size of the array
    for (int index = 0; index < size; index++) {
        fscanf(file_input, "%d", &array[index]); // Read the array elements
    }

    max_min(array, size, &max_num, &min_num);
    fprintf(file_output, "%d %d\n", max_num, min_num); // Write max and min to the output file

    fclose(file_input);
    fclose(file_output);
    return 0;
}

/**
 * @brief This function is about file_input
 ding the max and min integers in a constant array of integers.
 * 
 * @param array A constant pointer to constant int 
 * @param array_size The size of the array.
 * @param max_ptr A pointer to the max element in the array.
 * @param min_ptr A pointer to the min element in the array.
 * 
 * @return Return void.
 */
void max_min(const int *const array, const int array_size, int *max_ptr, 
             int *min_ptr) {
    
    const int *array_ptr = NULL;
    *max_ptr = array[0];
    *min_ptr = array[0];

    for (array_ptr = array + 1; array_ptr < array + array_size; array_ptr++) {
        if (*array_ptr > *max_ptr) {
            *max_ptr = *array_ptr;
        } 
        
        if (*array_ptr < *min_ptr) {
            *min_ptr = *array_ptr;
        }
    }
    return;
}
