#include "../../global.h"

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

int is_sorted(t_pile *current, int size) {
    t_pile *ptr;

    ptr = current->next;
    while(ptr != current) {
        if(ptr > ptr->next)
            return (0);
        ptr = ptr->next;
    }
    return (1);
}