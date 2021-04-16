#include "../global.h"

int better_garbage(t_pile **pile, int size, t_garbage **new) {
    t_garbage tmp;
    s(pile, size);
    create_loop(pile, size);
    greater_than(*pile, size, &tmp);
    if(tmp.size_garb < (*new)->size_garb) {
        (*new)->garb = tmp.garb;
        (*new)->size_garb = tmp.size_garb;
        return (1);
    }
    s(pile, size);
    return (0); 
}

int inside_garbage(int value, t_garbage *new) {
    int i;
    t_pile *ptr;
    i = 0;

    ptr = new->garb;
    while(i < new->size_garb) {
        if(value == ptr->value)
            return (1);
        i++;
        ptr = ptr->next;
    }
    return (0);
}

void remove_garbage_value_at(int value, t_pile **pile, int *size) {
    while((*pile)->value != value)
        r(pile, *size);
    remove_to_start(pile, size);
    
} 

void clear_pile_a(t_ps *app, t_garbage *new) {    

    while(new->size_garb != 0) {
        if(better_garbage(&app->a, app->size_a, &new)) {
            ft_putstr("sa\n");
        } else if(inside_garbage(app->a->value, new)) {
            remove_garbage_value_at(app->a->value, &new->garb, &new->size_garb);
            p(&app->b, &app->a, &app->size_b, &app->size_a);
            ft_putstr("pb\n");
        } else {
            r(&app->a, app->size_a);
            ft_putstr("ra\n");
        }
    }

   // free_pile(&tmp.garb, tmp.size_garb);

}