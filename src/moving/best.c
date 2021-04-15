#include "../global.h"


void execute_move(t_dir best,t_pile **pile_a,t_pile **pile_b,int *size_a, int *size_b) {
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
    // if((*pile_a)->value > (*pile_a)->next->value) {
    //     s(pile_a, *size_a);
    //     ft_printf("sa\n");
    // }

	

}

void init_best(t_dir *dir, int a, int b) {
    dir->move_nb_a = a;
    dir->move_nb_b = b;
    dir->value = 0;
    dir->dir_a = 0;
    dir->dir_b = 0;
    dir->move_total = a + b;
}

void path_finding_b(t_pile **pile, int size, int searched, t_dir *dir) {
    int rb;
    int rrb;
    t_pile *ptr;

    rrb = 0;
    rb = 0;
    ptr = *pile;
    while(ptr->value != searched) {
        ptr = ptr->next;
        rrb++;
    }
    while(ptr->value != (*pile)->value) {
        ptr = ptr->next;
        rb++;
    }
    if(rrb < rb) {
        dir->dir_b = 1;
        dir->move_nb_b = rrb;
    } else {
        dir->dir_b = -1;
        dir->move_nb_b = rb;
    }
}

int value_searched_in_a(t_pile *pile, int size, int searched) {
    t_pile *ptr;
    int max;
    int min;

    max = max_value(pile, size);
    min = min_value(pile, size);
    ptr = pile;
    
    if(searched > max)
        return(min);
    while(ptr->value > searched)
        ptr = ptr->next;
    while(ptr->value < searched)
        ptr = ptr->next;
    return (ptr->value);
}

void path_finding_a(t_pile **pile, int size, int searched, t_dir *dir) {
    int rb;
    int rrb;
    t_pile *ptr;

    rrb = 0;
    rb = 0;
    ptr = *pile;
    while(ptr->value != searched) {
        ptr = ptr->next;
        rrb++;
    }
    while(ptr->value != (*pile)->value) {
        ptr = ptr->next;
        rb++;
    }
    if(rrb < rb) {
        dir->dir_a = 1;
        dir->move_nb_a = rrb;
    } else {
        dir->dir_a = -1;
        dir->move_nb_a = rb;
    }
    // ft_printf("searched - %d\n", searched);
}

void estimate_rotate(t_pile **pile_a, t_pile **pile_b, int *size_a, int *size_b) {
    t_dir best;
    t_dir tmp;
    t_pile *ptr;
    int i;
    i = 0;

    init_best(&best, *size_a, *size_b);

    ptr = *pile_b;
  
    while(i < *size_b) {
        // ft_printf("\n\nvalue - %d\n", ptr->value);
        path_finding_b(pile_b, *size_b, ptr->value, &tmp);
        path_finding_a(pile_a, *size_a, value_searched_in_a(*pile_a, *size_a, ptr->value), &tmp);  
    
        
        if(tmp.dir_a == tmp.dir_b)
            tmp.move_total = (tmp.move_nb_a > tmp.move_nb_b) ? tmp.move_nb_a : tmp.move_nb_b;
        else 
            tmp.move_total = tmp.move_nb_a + tmp.move_nb_b;
        if(best.move_total > tmp.move_total) {
            best.move_nb_a = tmp.move_nb_a;
            best.move_nb_b = tmp.move_nb_b;
            best.dir_b = tmp.dir_b;
            best.dir_a = tmp.dir_a;  
            best.move_total = tmp.move_total;    
        }
        // ft_printf("b | %d, %d\n", tmp.dir_b, tmp.move_nb_b);
        // ft_printf("a | %d, %d\n\n", tmp.dir_a, tmp.move_nb_a); 
        ptr = ptr->next;
        i++;
    }

    // ft_printf("best b | %d, %d\n", best.dir_b, best.move_nb_b);
    // ft_printf("best a | %d, %d\n\n", best.dir_a, best.move_nb_a); 

    // ft_printf("\nBEFORE\n\n---PILE A---\n");
    // ft_printf("len : %d\n", show_pile(*pile_a, *size_a));

    // ft_printf("---PILE B---\n");
    // ft_printf("len : %d\n", show_pile(*pile_b, *size_b));

    execute_move(best, pile_a, pile_b, size_a, size_b);

    // ft_printf("\nAFTER\n\n---PILE A---\n");
    // ft_printf("len : %d\n", show_pile(*pile_a, *size_a));

    // ft_printf("---PILE B---\n");
    // ft_printf("len : %d\n", show_pile(*pile_b, *size_b));

    // exit(0);
}
