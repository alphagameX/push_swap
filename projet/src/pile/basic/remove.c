#include "../../global.h"


void remove_to_start(t_pile **current,int *size) {
    t_pile *f;

    if(*size > 0 || *current != NULL) {
        f = *current;

        if(*size > 1) {
            *current = (*current)->next;
            free(f);
            (*current)->prev = NULL;
        } else {
            free(*current);
            *current = NULL;
        }
        *size -= 1;
    }
        
}

void remove_to_end(t_pile **current,int *size) {
    int i = 0;
    t_pile *ptr;

    if(*size > 0 || *current != NULL) {
        ptr = *current;
        while(i < *size - 1) {
            i++;
            ptr = ptr->next;
        }
        free(ptr);
        ptr = NULL;
        *size -= 1;
    }
}
