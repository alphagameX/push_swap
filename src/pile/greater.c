#include "../global.h"

void not_sorted_pile(t_pile *current, int size, t_garbage *new) {

    int i = 0;
    int value = current->value;

    if(new->size_garb > 0)
        free_pile(&new->garb, new->size_garb);

    new->garb = init_pile();
    new->size_garb = 0;
    while(i < size) {
        if(current->value <= value)
             value = current->value;
        else
            add_to_end(&new->garb, &new->size_garb, current->value);
        i++;
        current = current->prev;
    }
}

void init_garbage(t_garbage *new) {
    new->garb = init_pile();
    new->size_garb = 0;
}

void greater_than(t_pile *current, int size, t_garbage *best) {

    t_garbage new;
    t_pile *ptr;
    int i;
    int best_size;
    int best_index;


    i = 0;
    init_garbage(&new);
    best_size = size;
    best_index = 0;
    ptr = current;
    while(i < size) {
        not_sorted_pile(ptr, size, &new);
        if(new.size_garb < best_size) {
            best_size = new.size_garb;
            best_index = i;
        }
        ptr = ptr->next;
        i++;
    }
    i = 0;
    while(i != best_index) {
        current = current->next;
        i++;
    }
    not_sorted_pile(current, size, &new);
    best->garb = new.garb;
    best->size_garb = new.size_garb;
}