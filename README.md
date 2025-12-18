# Push_swap

## Description

### Algo choices

#### Simple sort
Initially a bubble sort was chosen to make this project but after implementing it testing it out, we figured pretty fast that bubble sorting our stacks was highly inefficient and a better sorting algorithm ought to be chosen. Especially since our sorting or at least the logic of it is also used in our medium algorithm.

After reading some docs on the differents O(n²) algorithms proposed, the insertion sort algorithm appeared to be the better choice.
Here's an illustration of a basic operation in an insertion sort :
![alt text](image-1.png)

The insertion sort has 3 different triage :
- if top of stack_a is a new_min of stack_b, we place the old min_b at the bottom of stack_b and pb the new_min.
- if top of stack_a is a new_max of stack_b, we place the old max_b at the top of stack_b and pb the new_min.
- if top of stack_a is neither max or min of stack_b, we need to find the good spot for it.

#### Medium sort


#### Complex sort

### Usage examples

### Feature list

### Technical choices

## Instructions

## Resources
