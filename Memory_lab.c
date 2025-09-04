#include <stdio.h>
#include <stdlib.h>

// Stack Overflow
void stack_overflow(int depth, int max_depth) {
    char buffer[1024];
    printf("Stack depth: %d\n", depth);
    if (depth < max_depth)
        stack_overflow(depth + 1, max_depth);
}

// Memory Leak
void memory_leak(int iterations) {
    printf("Memory Leak Test\n");
    for (int i = 0; i < iterations; i++) {
        void *ptr = malloc(1024 * 1024); 
        if (!ptr) {
            printf("Malloc failed at iteration %d\n", i + 1);
            break;
        }
        printf("Allocated 1MB, iteration %d\n", i + 1);
        
    }
}

// Out of Memory
void out_of_memory(size_t block_size, int max_blocks) {
    printf("Out of Memory Test\n");
    void **blocks = malloc(sizeof(void*) * max_blocks);
    if (!blocks) {
        printf("Failed to allocate pointer array\n");
        return;
    }
    size_t count = 0;
    for (count = 0; count < max_blocks; count++) {
        blocks[count] = malloc(block_size);
        if (!blocks[count]) {
            printf("Out of memory after %zu allocations\n", count);
            break;
        }
        printf("Allocated %zu bytes, total: %zu\n", block_size, count + 1);
    }
    for (size_t i = 0; i < count; i++) free(blocks[i]);
    free(blocks);
}

int main(void) {
    char option;
    printf("=== Memory Lab ===\n");
    printf("1. Stack Overflow\n");
    printf("2. Out of Memory\n");
    printf("3. Memory Leak\n");
    printf("X. Exit\n");
    printf("Enter choice (1,2,3,X): ");

    scanf(" %c", &option);

    if (option == 'X' || option == 'x') {
        printf("Program exited.\n");
        return 0;
    }

    if (option == '1') {
        stack_overflow(1, 20);
    } else if (option == '2') {
        out_of_memory(50 * 1024 * 1024, 50); 
    } else if (option == '3') {
        memory_leak(50);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

