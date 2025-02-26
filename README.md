# C-Program-for-Statistical-Analysis-and-Sorting-of-Integer-Sequences

## Description
This C program reads a set of numbers from a file (`dados.txt`), performs various statistical analyses, and generates different output files:

- `estatisticas.txt`: Contains the count of positive, negative, zero, even, and odd numbers.
- `distintos.txt`: Stores the unique numbers from the input file.
- `ordenado.txt`: Saves all numbers sorted in ascending order.
- `distintos_ordenado.txt`: Stores only unique numbers sorted in ascending order.

## Features
- Reads an input file and processes a maximum of 108 numbers.
- Checks if the input file contains at least 30 numbers.
- Performs statistical analysis on the numbers.
- Implements a bubble sort algorithm to sort the numbers.
- Saves the processed data in separate output files.

## Compilation and Execution
1. Compile the program using GCC:
   ```sh
   gcc program.c -o program
   ```
2. Run the compiled program:
   ```sh
   ./program
   ```

## Input File Format (`dados.txt`)
The input file should start with an integer indicating the number of values, followed by the list of integers:
```
30
12 -5 0 8 3 ...
```

## Error Handling
- If the input file cannot be opened, an error message is displayed.
- If the number of values exceeds 108, the program exits with an error.
- If fewer than 30 numbers are provided, the program exits with an error.
- Errors while creating output files result in an error message and program termination.

## Sorting Algorithm
The program uses the Bubble Sort algorithm to sort the numbers in ascending order.

## Output Example
After execution, the program generates the following files:
- `estatisticas.txt`:
  ```
  Number of positive numbers: X
  Number of negative numbers: Y
  Number of zeros: Z
  Number of even numbers: A
  Number of odd numbers: B
  ```
- `distintos.txt`: `Unique numbers separated by spaces`
- `ordenado.txt`: `Sorted numbers separated by spaces`
- `distintos_ordenado.txt`: `Sorted unique numbers separated by spaces`

## Notes
Ensure the input file follows the correct format before execution to avoid errors.

