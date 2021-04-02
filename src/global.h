#ifndef GLOBAL_HEADER
#define GLOBAL_HEADER

#include "../vendor/libft/libft.h"

typedef struct s_stack {
    int value;

    struct s_stack *prev;
    struct s_stack *next;
} t_stack_link, *t_stack;

/*CHAIN*/
t_stack         new_stack(void);
int             is_empty_stack(t_stack stack);
t_stack         push_stack_front(t_stack stack, int value);
t_stack         push_stack_back(t_stack stack, int value);
t_stack_link    *pop_stack_back(t_stack *stack);
t_stack_link    *pop_stack_front(t_stack *stack);
int             secure_stack_next_value(t_stack stack);

/*FUNCTION*/
void print_stack(t_stack stack);
int stack_length(t_stack stack);
int stack_is_sort(t_stack stack);
int min_stack_value(t_stack stack);
int stack_has_doublon(t_stack stack);

/*RULES*/
void s(t_stack stack);
void ss(t_stack a, t_stack b);
void p(t_stack *dst, t_stack *src);
void r(t_stack *stack);
void rr(t_stack *a, t_stack *b);
void rrr(t_stack *stack);
void rrrr(t_stack *a, t_stack *b);

#endif