#include "../../global.h"


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