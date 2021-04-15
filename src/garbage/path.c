#include "../global.h"

t_garbage *not_sorted_pile(t_pile *current, int size, int dir) {
    
    t_garbage *tmp;
    int i = 0;
    int value = current->value;

    if((tmp = malloc(sizeof(t_garbage))) == NULL)
        return (NULL);
    
    tmp->garb = init_pile();
    tmp->size_garb = 0;

    while(i < size) {
        if(current->value <= value)
             value = current->value;
        else
            add_to_end(&tmp->garb, &tmp->size_garb, current->value);
        i++;
        current = current->prev;
    }
    return (tmp);
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
 

t_garbage *greater_than(t_pile *current, int size) {

    t_garbage **new;
    t_pile *tmp;
    int e = 0;
    int low; 
    int index;

    if((new = malloc(sizeof(t_garbage*) * size)) == NULL)
        return(NULL);
    
    int i = 0;

    while(i < size) {
        new[i] = not_sorted_pile(current, size, -1);
        current = current->next;
        i++;
    }

    i = 0;
    low = new[i]->size_garb;
    index = i;

    while(i < size) {
        e = 0;
        tmp = new[i]->garb;
        while(e < new[i]->size_garb) {
            if(new[i]->size_garb < low) {
                index = i;
                low = new[i]->size_garb;
            }
            tmp = tmp->next;
            e++;
        }
        i++;
    }
    return (new[index]);
}