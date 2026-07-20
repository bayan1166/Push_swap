# push_swap

A sorting algorithm project from the 42 School curriculum.

## Description

`push_swap` sorts a list of integers in ascending order using two stacks (`A` and `B`) and a limited set of operations. The goal is to generate the smallest possible sequence of instructions while respecting the project constraints.

## Features

- Input parsing and validation
- Duplicate detection
- Integer overflow handling
- Stack normalization
- Optimized sorting for 2–5 numbers
- Radix Sort for larger datasets
- Memory-safe implementation

## Project Structure

```
.
├── Makefile
├── main.c
├── push_swap.c
├── push_swap.h
├── init.c
├── parse.c
├── parse_utils.c
├── ft_split.c
├── normalize.c
├── sort_small.c
├── sort_radix.c
├── ops_swap.c
├── ops_push.c
├── ops_rotate.c
├── ops_rev_rotate.c
├── stack_utils.c
└── stack_utils2.c
```

## Compilation

```bash
make
```

Clean object files:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Recompile:

```bash
make re
```

## Usage

```bash
./push_swap 3 2 5 1 4
```

Example output:

```text
pb
ra
sa
pa
ra
```

## Allowed Operations

- `sa` – swap A
- `sb` – swap B
- `ss` – swap both
- `pa` – push to A
- `pb` – push to B
- `ra` – rotate A
- `rb` – rotate B
- `rr` – rotate both
- `rra` – reverse rotate A
- `rrb` – reverse rotate B
- `rrr` – reverse rotate both

## Algorithm

- **2–5 numbers:** optimized sorting with predefined strategies.
- **More than 5 numbers:** normalized values are sorted using the **Radix Sort** algorithm to minimize the number of operations.

## Error Handling

The program prints:

```text
Error
```

when:
- Invalid input
- Duplicate numbers
- Integer overflow
- Non-numeric arguments
- Empty arguments

## Technologies

- C
- Make
- GCC
- 42 Norm

## Author

Bayan Marashdeh
