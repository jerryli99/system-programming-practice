#!/bin/bash

# Number of test cases to generate
num_tests=5
max_value=100

# Generate input and expected output files
generate_test_case() {
    local test_num=$1
    local input_file="input${test_num}.txt"
    local expected_file="expected${test_num}.txt"
    
    # Generate random array of length 10
    shuf -i 1-$max_value -n 10 > $input_file

    # Sort the array and format it into a single line to create the expected output
    sort -n $input_file > $expected_file

    # Ensure there's a newline at the end of the expected file
    echo "" >> $expected_file
}

# Generate test cases
for case_count in $(seq 1 $num_tests); do
    generate_test_case $case_count
done

# Compile the C program
gcc -o quicksort b1_pointers_and_arrays_proj6.c

# Run the tests
for index in $(seq 1 $num_tests); do
    input_file="input${index}.txt"
    output_file="output${index}.txt"
    expected_file="expected${index}.txt"

    # Run the quicksort program
    ./quicksort $input_file $output_file

    # Compare the output with the expected output
    # if diff exit status is 0, then test passed
    if diff $output_file $expected_file; then
        echo "Test $index passed"
    else
        echo "Test $index failed"
        diff $output_file $expected_file
    fi
done

# Clean up
rm input*.txt output*.txt expected*.txt quicksort
