# Push Swap

## Overview

**Push Swap** is a sorting algorithm project developed as part of the 42 School curriculum. The main objective is to sort a stack of integers using a minimal number of operations, constrained to a specific set of commands. This project emphasizes the implementation of efficient sorting algorithms and mastering stack operations.

## Features

- **Efficient Sorting:** Sort a stack of integers using the fewest number of operations.
- **Minimal Operation Set:** Utilize a predefined set of stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
- **Algorithm Design:** Implement sorting algorithms tailored for stack-based data structures.
- **Error Handling:** Validate input and handle errors gracefully.

## Usage

### Compilation

To compile the Push Swap program, use the provided Makefile:

```bash
make && make clean
```
Execute the program
```bash
./push_swap [list_of_integers]
```
example
```bash
./push_swap 35 10 41 254 21 58 56 36 95 74 25 1 52 0 545 8
```
The program will output a series of operations that, when applied, will sort the stack.

### Operations

- sa: Swap the top two elements of stack A.
- sb: Swap the top two elements of stack B.
- ss: Swap the top two elements of both stacks A and B.
- pa: Push the top element of stack B to stack A.
- pb: Push the top element of stack A to stack B.
- ra: Rotate stack A upwards (shift all elements up by one).
- rb: Rotate stack B upwards.
- rr: Rotate both stacks A and B upwards.
- rra: Rotate stack A downwards (shift all elements down by one).
- rrb: Rotate stack B downwards.
- rrr: Rotate both stacks A and B downwards.
