#!/bin/bash

# Compile the C program
gcc -o max_min_test b1_pointers_and_arrays_proj7.c

# Number of test cases
num_tests=10
array_size=30

# Generate test cases and expected outcomes
for index in $(seq 1 $num_tests); do
    # Generate test case file
    echo $array_size > "input${index}.txt"  

    count=$array_size
    while [ $count -gt 0 ]; do
        # Generate a random number between -100 and 100, append it to file
        echo $((RANDOM % 201 - 100)) >> "input${index}.txt"
        ((count--))
    done

    # Run the program to generate outputs
    ./max_min_test "input${index}.txt" "output${index}.txt"

    # Generate expected outcomes
    sort -n "input${index}.txt" | awk 'NR == 1 {min=$1} {max=$1} END {print max, min}' > "expected${index}.txt"
done

# Check results
for index in $(seq 1 $num_tests); do
    if diff "output${index}.txt" "expected${index}.txt"; then
        echo "Test $index passed."
    else
        echo "Test $index failed."
        diff "output${index}.txt" "expected${index}.txt"
    fi
done

# Clean up
rm input*.txt output*.txt expected*.txt max_min_test
