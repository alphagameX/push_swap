#include "../../global.h"

int r_r(t_garbage *cpy, int search, int dir) {
    int i = 0;

    while(cpy->garb->value != search) {
        if(dir == -1)
            r(&cpy->garb, cpy->size_garb);
        else if(dir == 1)
            rr(&cpy->garb, cpy->size_garb);
        i++;
    }

    return (i);
}

int best_rotate(t_pile **current, int size, int *dir, int search) {
    t_garbage *neg;
    t_garbage *pos;
    t_garbage *tmp;
    int i;

    neg = cpy_pile(*current, size);
    pos = cpy_pile(*current, size);
    tmp = cpy_pile(*current, size);

    i = r_r(neg, search, -1);
    *dir = -1;
    if(r_r(tmp, search, 1) < i) {
        i = r_r(pos, search, 1);
        *dir = 1;
    }
    free_garbage(neg);
    free_garbage(pos);
    free_garbage(tmp);
    return (i);
}

int fast_r(t_pile **current, int size, int search) {
    int i = 0;
    int dir;

    i = best_rotate(current, size, &dir, search);
    if(dir == -1) {
        while(i != 0) {
            r(current, size);
            ft_printf("ra\n");
            i--;
        }
    } else {
        while(i != 0) {
            rr(current, size);
            ft_printf("rra\n");
            i--;
        }
    }
    return (i);
}