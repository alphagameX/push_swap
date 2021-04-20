#include "../global.h"

void free_pile(t_pile **current, int size) {
    int i = 0;
    t_pile *ptr;

    while(i < size) {
        i++;
        ptr = (*current);
        (*current) = (*current)->next;
        if(ptr != NULL)
            free(ptr);
    }

    *current = init_pile();
}

void free_garbage(t_garbage *garbage) {
    free_pile(&garbage->garb, garbage->size_garb);
    free(garbage);
}

