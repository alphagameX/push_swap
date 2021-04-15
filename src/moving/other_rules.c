#include "../global.h"

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

int fast_r(t_pile **current, int size, int search) {
    int i = 0;
    int dir;

    //ft_printf("%d\n", r_r(cpy_pile(*current, size), search, -1));
    //ft_printf("%d\n", r_r(cpy_pile(*current, size), search, 1));

    i = r_r(cpy_pile(*current, size), search, -1);
    dir = -1;
    
    if(r_r(cpy_pile(*current, size), search, 1) < i) {
        i = r_r(cpy_pile(*current, size), search, 1);
        dir = 1;
    }


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