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

int to_the_top(t_pile *pile, int size, int search, int dir) {
    int i;
    t_pile *ptr;

    i = 0;
    ptr = pile;
    while(i < size && ptr->value != search) {
        if(dir == -1)
            ptr = ptr->prev;
        else if(dir == 1)
            ptr = ptr->next;
        i++;
    }
    return (i);
}


void best_in_a(t_pile *pile, int size, t_dir *best) {
    t_pile *ptr;
    t_dir tmp;
    int i;

    i = 0;
    ptr = pile;

    tmp.move_nb_a = 0;

    if(max_value(pile, size) < best->value) {
        while(ptr->value != max_value(pile, size)) {
            tmp.move_nb_a++;
            ptr = ptr->next;
        }
        best->dir_a = 1;
    } else {
        while(ptr->value > best->value) {
            ptr = ptr->next;
            tmp.move_nb_a++;
        }

        while(ptr->value < best->value) {
            tmp.move_nb_a++;
            ptr = ptr->next;
        }
        best->dir_a = 1;
    }

    best->move_nb_a = tmp.move_nb_a;
}


void execute_move(t_dir best,t_pile **pile_a,t_pile **pile_b,int *size_a, int *size_b) {

    // ft_printf("---PILE A---\n");
    // ft_printf("len : %d\n", show_pile(*pile_a, *size_a));

    // ft_printf("---PILE B---\n");
    // ft_printf("len : %d\n\n\n\n", show_pile(*pile_b, *size_b));


    // ft_printf("%d, %d\n", best.move_nb_b, best.dir_b);
    // ft_printf("%d, %d\n", best.move_nb_a, best.dir_a);

    if(best.move_nb_a > 0 && best.move_nb_b > 0 && best.dir_b == best.dir_a) {
        while(best.move_nb_b != 0 && best.move_nb_a != 0) {
            if(best.dir_a == 1) {
                rs(pile_a, pile_b, size_a, size_b);
                ft_printf("rr\n");
            }
            else if(best.dir_a == -1) {
                rrs(pile_a, pile_b, size_a, size_b);
                ft_printf("rrr\n");
            }
            best.move_nb_a--;
            best.move_nb_b--;
        }
    }

    while(best.move_nb_a != 0) {
        if(best.dir_a == 1) {
            r(pile_a, *size_a);
            ft_printf("ra\n");
        }
        else if(best.dir_a == -1) {
            rr(pile_a, *size_a);
            ft_printf("rra\n");
        }
        best.move_nb_a--;
    }

    while(best.move_nb_b != 0) {
        if(best.dir_b == 1) {
            r(pile_b, *size_b);
            ft_printf("rb\n");
        }
        else if(best.dir_b == -1) {
            rr(pile_b, *size_b);
            ft_printf("rrb\n");
        }
        best.move_nb_b--;
    }

    p(pile_a, pile_b, size_a, size_b);
    ft_printf("pa\n");

    if((*pile_a)->value > (*pile_a)->next->value) {
        s(pile_a, *size_a);
        ft_printf("sa\n");
    }

	// ft_printf("\n\n\n---PILE A---\n");
	// ft_printf("len : %d\n", show_pile(*pile_a, *size_a));

	// ft_printf("---PILE B---\n");
	// ft_printf("len : %d\n", show_pile(*pile_b, *size_b));

}

void init_best(t_dir *dir, int a, int b) {
    dir->move_nb_a = a;
    dir->move_nb_b = b;
    dir->value = 0;
    dir->dir_a = 0;
    dir->dir_b = 0;
}

void estimate_rotate(t_pile **pile_a, t_pile **pile_b, int *size_a, int *size_b) {
    t_dir best;
    t_dir tmp;
    t_pile *ptr;
    int i;

    i = 0;

    init_best(&best, *size_a, *size_b);

    ptr = *pile_b;
    // ft_printf("b -> %d, %d ,%d\n", best.move_nb_b, best.dir_b, best.value);
    // ft_printf("a -> %d, %d \n\n", best.move_nb_a, best.dir_a);
    while(i < *size_b) {
        if(to_the_top(*pile_b, *size_b, ptr->value, -1) < to_the_top(*pile_b, *size_b, ptr->value, 1)) {
            tmp.move_nb_b = to_the_top(*pile_b, *size_b, ptr->value, -1);
            tmp.dir_b = -1;
        } else {
            tmp.move_nb_b = to_the_top(*pile_b, *size_b, ptr->value, 1);
            tmp.dir_b = 1;
        }
        tmp.value = ptr->value;
        
        best_in_a(*pile_a, *size_a, &tmp);

        if(tmp.dir_a != tmp.dir_b) {
            if(best.move_nb_a + best.move_nb_b > tmp.move_nb_b + tmp.move_nb_a) {
                best.value = tmp.value;
                best.move_nb_b = tmp.move_nb_b;
                best.move_nb_a = tmp.move_nb_a;
                best.dir_b = tmp.dir_b;
                best.dir_a = tmp.dir_a;
            }
        } else {
            if(tmp.move_nb_a > tmp.move_nb_b) {
                 if(best.move_nb_a + best.move_nb_b > tmp.move_nb_a) {
                    best.value = tmp.value;
                    best.move_nb_b = tmp.move_nb_b;
                    best.move_nb_a = tmp.move_nb_a;
                    best.dir_b = tmp.dir_b;
                    best.dir_a = tmp.dir_a;
                }
            } else {
                 if(best.move_nb_a + best.move_nb_b > tmp.move_nb_b) {
                    best.value = tmp.value;
                    best.move_nb_b = tmp.move_nb_b;
                    best.move_nb_a = tmp.move_nb_a;
                    best.dir_b = tmp.dir_b;
                    best.dir_a = tmp.dir_a;
                }
            }
        }
        // ft_printf("b -> %d, %d ,%d\n", tmp.move_nb_b, tmp.dir_b, tmp.value);
        // ft_printf("a -> %d, %d \n\n", tmp.move_nb_a, tmp.dir_a);
        ptr = ptr->next;
        i++;
    }
    execute_move(best, pile_a, pile_b, size_a, size_b);
    //ft_printf("b -> %d, %d ,%d\n", best.move_nb_b, best.dir_b, best.value);
    //ft_printf("a -> %d, %d \n", best.move_nb_a, best.dir_a);
}
