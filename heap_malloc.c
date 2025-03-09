#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define HEAP_SIZE 32768

char memory_bank[HEAP_SIZE];

typedef struct MemoryBlock 
{
    size_t size;
    struct MemoryBlock* next;
    bool free;
} MemoryBlock;

MemoryBlock* heap_start = NULL;  

void initialize_heap() 
{
    heap_start = (MemoryBlock*)&memory_bank;
    heap_start->size = HEAP_SIZE - sizeof(MemoryBlock);
    heap_start->free = true;
    heap_start->next = NULL;
}

char* allocate(size_t size) 
{
    int flag = 0;
    char *retptr = NULL;
    MemoryBlock* current = heap_start;
    
    while (current && !flag) 
    {
        if (current->free && current->size >= size) 
        {
            if (current->size > size + sizeof(MemoryBlock)) 
            {
                MemoryBlock* chunks = (MemoryBlock*)((char*)current + sizeof(MemoryBlock) + size);
                chunks->size = current->size - size - sizeof(MemoryBlock);
                chunks->free = true;
                chunks->next = current->next;
                current->next = chunks;
            }
            current->size = size;
            current->free = false;
            flag = 1;
            retptr = (char*)current + sizeof(MemoryBlock);
        }
        current = current->next;
    }
    if (current == NULL || flag == 0)
    {
      printf("Memory cant be allocated\n");
    }
    return retptr;
}

void merge_free_blocks() 
{
    MemoryBlock* current = heap_start;
    while (current && current->next) 
    {
        if (current->free && current->next->free) 
        {
            current->size += sizeof(MemoryBlock) + current->next->size;
            current->next = current->next->next;
        } else 
        {
            current = current->next;
        }
    }
}

void release_memory(char* ptr)
{
    if (!ptr)
    {
      return;
    }
    
    MemoryBlock* block = (MemoryBlock*)((char*)ptr - sizeof(MemoryBlock));
    block->free = true;
    
    merge_free_blocks();  
}

void print_heap() 
{
    MemoryBlock* current = heap_start;
    printf("\nHeap Structure:\n");
    while (current) 
    {
        printf("[Size: %lu, Free: %d, Address: %p] -> ", current->size, current->free,current);
        current = current->next;
    }
    printf("NULL\n");
}

int main() 
{
    initialize_heap();
    print_heap();
    char* ptr1 = allocate(100);
    char* ptr2 = allocate(200);
    print_heap();
    release_memory(ptr2);
    print_heap();
    char* ptr3 = allocate(80);
    print_heap();
    release_memory(ptr1);
    release_memory(ptr3);
    print_heap();

    return 0;
}
