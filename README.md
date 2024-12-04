# Push Swap

A program that sorts integers using two stacks and a specific set of operations.

## Description

I learned to sort numbers efficiently using only two stacks (a and b) and a limited set of moves. The program outputs the sequence of operations needed to sort the numbers in ascending order.

## Operations
- `sa/sb`: Swap first 2 elements of stack a/b
- `pa/pb`: Push top element from one stack to other
- `ra/rb`: Rotate stack up (first becomes last)
- `rra/rrb`: Rotate stack down (last becomes first)
- `ss/rr/rrr`: Perform both operations simultaneously

## Usage
```bash
make
./push_swap 5 4 6 7 2 1 3
```

## Performance Targets
- 5 numbers: Max 12 moves
- 100 numbers: Max 700 moves
- 500 numbers: Max 5500 moves

## Example Output
```
pb
ra
pb
sa
pa
pa
```

This output shows the exact moves needed to sort your numbers.
