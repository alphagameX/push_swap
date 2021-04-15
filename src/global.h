#ifndef GLOBAL_HEADER
#define GLOBAL_HEADER

#include "../vendor/libft/libft.h"
#include <stdbool.h>

typedef struct s_pile{
    int value;

    struct s_pile *next;
    struct s_pile *prev;
}t_pile;

typedef struct s_garbage {
    t_pile *garb;
    int start;
    int size_garb;
}t_garbage;

typedef struct s_ps {
    t_pile *a;
    t_pile *b;

    int size_a;
    int size_b;
}t_ps;

typedef struct s_dir {

    int dir_a;
    int dir_b;
    int move_nb_a; 
    int move_nb_b;
    int move_total;

    int value;

}   t_dir;

/*FUNCTION PILE*/
t_pile *init_pile();
void add_to_start(t_pile **current,int *size, int value);
void add_to_end(t_pile **current,int *size, int value);
void remove_to_start(t_pile **current,int *size);
void remove_to_end(t_pile **current,int *size);
void create_loop(t_pile **current, int size);


/*CONTROL FUNCTION*/
int show_pile(t_pile *pile, int size);
void free_pile(t_pile **current, int size);
bool has_duplicate(t_pile *pile, int size);
int max_value(t_pile *current, int size);
void set_index(t_pile **current, int size);
int min_value(t_pile *current, int size);
t_garbage *cpy_pile(t_pile *current, int size);
int is_sorted(t_pile *current, int size);


/*RULES*/
void s(t_pile **pile, int size);
void r(t_pile **pile, int size);
void p(t_pile **dst, t_pile **src,  int *size_dst, int *size_src);
void rs(t_pile **pile_a, t_pile **pile_b, int *size_a, int *size_b);
void ss(t_ps *app);
void rr(t_pile **pile, int size);
void rrs(t_pile **pile_a, t_pile **pile_b, int *size_a, int *size_b);


t_garbage *greater_than(t_pile *current, int size);
int fast_r(t_pile **current, int size, int search);
void estimate_rotate(t_pile **pile_a, t_pile **pile_b, int *size_a, int *size_b);

#endif