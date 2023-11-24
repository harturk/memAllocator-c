#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "mymemory.h"
#include "list.c"
#include "mymemory.c"

int main() {
    int size = 200;
    mymemory_t *pool = mymemory_init(size);
    allocation_t *block = mymemory_alloc(pool, 2 * sizeof(int));
    allocation_t *block2 = mymemory_alloc(pool, 2 * sizeof(int));
    allocation_t *block3 = mymemory_alloc(pool, 2 * sizeof(char));
    printf("Operacao aleatoria %d\n", block->start - block2->start);


    printf("------------------- Informacoes sobre a memoria -------------------\n");
    mymemory_display(pool);
    printf("\n");
    mymemory_stats(pool);
    free_block_display();
    printf("Apos limpeza\n");
    mymemory_free(pool, block2);
    mymemory_display(pool);
    free_block_display();

    return 0;
}