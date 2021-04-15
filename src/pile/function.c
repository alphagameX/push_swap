#include "../global.h"

int show_pile(t_pile *pile, int size) {
    int i;

    i = 0;
    while(i < size) {
        ft_printf("%d\n", pile->value);
        pile = pile->next;
        i++;
    }

    return (i);
}

t_garbage *cpy_pile(t_pile *current, int size) {
    int i = 0;
    t_garbage *cpy;

    if((cpy = malloc(sizeof(t_garbage))) == NULL)
        return (NULL);

    cpy->garb = init_pile();
    cpy->size_garb = 0;
    while(i < size) {
        add_to_end(&cpy->garb, &cpy->size_garb, current->value);
        i++;
        current = current->next;
    }

    return(cpy);
}

bool has_duplicate(t_pile *pile, int size) {
    int i;
    int e;
    t_pile *ptr;

    i = 0;
    while(i < size) {
        ptr = pile->next;
        e = 0;
        while(e + i < size && ptr != NULL) {
            if(pile->value == ptr->value)
                return (true);
            e++;
            ptr = ptr->next;
        }
        i++;
        pile = pile->next;
    }
    return (false);
}

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

int max_value(t_pile *current, int size) {
    int i = 0;
    int res = 0;

    while(i < size) {
        if(current->value >= res)
            res = current->value;
        i++;
        current= current->next;
    }

    return (res);
}

int min_value(t_pile *current, int size) {
    int i = 0;
    int res = current->value;
    while(i < size) {
        if(current->value < res)
            res = current->value;
        i++;
        current = current->next;
    }
    return (res);
}

int is_sorted(t_pile *current, int size) {
    int i;
    t_pile *ptr;

    i = 0;
    ptr = current;
    while(i < size) {
        if(ptr > ptr->next)
            return (0);
        ptr = ptr->next;
        i++;
    }
    return (1);
}