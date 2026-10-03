*This project has been created as part of the 42 curriculum by talkhati.*
# Push_swap

## Description

Push_swap is an algorithmic project that challenges you to sort a stack of integers using a limited set of operations with the minimum number of moves possible. The project involves implementing an efficient sorting algorithm that works with two stacks (a and b) and a specific set of instructions to manipulate them.

The goal is to sort stack `a` in ascending order (smallest number at the top) while optimizing for the lowest possible number of operations. This project introduces fundamental concepts of algorithm complexity and efficiency, requiring careful consideration of different sorting strategies based on the input data.

## Instructions

### Compilation

To compile the project, run:

```bash
make
```

This will generate the `push_swap` executable.

For the bonus part (checker program):

```bash
make bonus
```

### Usage

#### push_swap

The `push_swap` program takes a list of integers as arguments and outputs the sequence of operations needed to sort them:

```bash
./push_swap 2 1 3 6 5 8
```

Output example:
```
sa
pb
pb
pb
sa
pa
pa
pa
```

#### checker (bonus)

The `checker` program validates whether a sequence of operations correctly sorts the stack:

```bash
./push_swap 3 2 1 0 | ./checker 3 2 1 0
```

Output: `OK` if sorted correctly, `KO` otherwise.

### Available Operations

- `sa` / `sb` / `ss`: Swap the first two elements
- `pa` / `pb`: Push top element from one stack to another
- `ra` / `rb` / `rr`: Rotate stack upward
- `rra` / `rrb` / `rrr`: Reverse rotate stack downward

### Error Handling

The program displays `Error` on stderr for:
- Non-integer arguments
- Numbers exceeding integer limits
- Duplicate values
- Invalid input format

### Performance Benchmarks

To achieve full validation (100%):
- Sort 100 random numbers in < 700 operations
- Sort 500 random numbers in < 5500 operations

Minimum validation (80%):
- 100 numbers in < 1100-1300 operations
- 500 numbers in < 5500-11500 operations (depending on the other benchmark)

## Features

- **Optimized sorting algorithm** tailored for different input sizes
- **Error handling** for invalid inputs
- **Checker program** (bonus) to validate sorting sequences
- **Efficient memory management** with no memory leaks

## Technical Choices

### Algorithm Strategy

The implementation uses different sorting approaches depending on stack size:

- **Small stacks (≤3 elements)**: Hardcoded optimal solutions
- **Medium stacks (4-5 elements)**: Simple optimized sorting
- **Large stacks (100-500+ elements)**: Advanced algorithms such as:
  - Chunk-based sorting
  - Radix sort variations
  - Quicksort-inspired partitioning approaches

### Implementation Details

- Stack data structure using linked lists or arrays
- Careful operation counting to minimize moves
- Pre-indexing or normalization of values for certain algorithms

## Resources

### Documentation & Tutorials

- [Sorting Algorithms Visualization](https://visualgo.net/en/sorting) - Interactive visualization of various sorting algorithms
- [Big O Notation Guide](https://www.bigocheatsheet.com/) - Algorithm complexity reference
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) - Understanding the fundamental data structure
- [42 Docs - Push_swap](https://harm-smits.github.io/42docs/projects/push_swap) - Community guide and tips
- Various algorithm complexity articles and sorting strategy discussions

### AI Usage

AI tools were used in the following ways during this project:

- **Debugging assistance**: Helping identify edge cases and logical errors in sorting logic
- **Documentation**: Structuring this README and explaining technical concepts clearly

All AI-generated content was thoroughly reviewed, tested, and validated to ensure correctness and understanding. 
