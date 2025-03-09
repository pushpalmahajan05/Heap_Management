# Heap Memory Allocator

## Overview
This project implements a simple heap memory allocator in C. It includes functions for memory allocation, deallocation, and heap management. The allocator manages a fixed-size memory bank using a linked list of memory blocks, supporting dynamic memory allocation similar to `malloc` and `free`.

## Features
- **Custom memory allocation** (`allocate`) – Allocates memory dynamically from a predefined memory pool.
- **Memory deallocation** (`release_memory`) – Frees allocated memory and merges adjacent free blocks to optimize space.
- **Heap initialization** (`initialize_heap`) – Prepares the memory bank for usage.
- **Heap visualization** (`print_heap`) – Displays the current structure of the memory heap.

## File Structure
heap_malloc.c   # Main implementation of the heap memory allocator


## How It Works
1. The `initialize_heap` function sets up the heap with a predefined size (`HEAP_SIZE`).
2. The `allocate` function searches for a free block of sufficient size and splits it if necessary.
3. The `release_memory` function marks a block as free and merges adjacent free blocks to reduce fragmentation.
4. The `print_heap` function outputs the current heap structure for debugging purposes.

## Compilation and Execution
### Compilation
To compile the program, use a C compiler like `gcc`:
gcc heap_malloc.c -o heap_allocator


### Running the Program
./heap_allocator

## Future Improvements
- Implementing a more efficient search algorithm for allocation.
- Adding support for memory reallocation (`realloc`).
- Enhancing fragmentation handling strategies.
