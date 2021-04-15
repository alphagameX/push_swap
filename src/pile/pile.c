#include "../global.h"

t_pile *init_pile() {
    return (NULL);
}

t_pile *create_link(int value) {
    t_pile *new;

    if((new = malloc(sizeof(t_pile))) == NULL)
        return (NULL);
    new->value = value;
    new->prev = NULL;
    new->next = NULL;
    return (new);
}

void add_to_start(t_pile **current, int *size, int value) {
    t_pile *tmp;
    
    if(*current == NULL || *size == 0)
        *current = create_link(value);
    else {
        tmp = create_link(value);
        tmp->next = *current;
        tmp->prev = NULL;

        (*current)->prev = tmp;
        *current = tmp;
    }
    *size += 1;
}


void add_to_end(t_pile **current,int *size, int value) {
    t_pile *tmp;
    t_pile *ptr;
    int i;

    if(*current == NULL || *size == 0)
        *current = create_link(value);
    else {
        tmp = create_link(value);
        ptr = *current;
        i = 0;
        while(i < *size - 1) {
            i++;
            ptr = ptr->next;
        }
        tmp->prev = ptr;
        ptr->next = tmp;
    }
    *size += 1;
}

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


void create_loop(t_pile **current, int size) {
    int i = 0;
    t_pile *start;

    start = *current;
    while(i < size - 1) {
        *current = (*current)->next;
        i++;
    }

    start->prev = *current;
    (*current)->next = start;

    *current = start;
}