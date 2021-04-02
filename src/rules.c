#include "global.h"

void print_stack(t_stack stack) {
    t_stack_link *tmp;

    tmp = stack;
    while(tmp != NULL) {
        ft_printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

int secure_stack_next_value(t_stack stack) {
    if(stack->next == NULL)
        return (stack->value);
    return(stack->next->value);
}

int stack_has_doublon(t_stack stack) {
    t_stack_link *start;

    while(stack != NULL) {
        start = stack->next;
        while(start != NULL) {
            if(start->value == stack->value)
                return (1);
            start = start->next;
        }
        stack = stack->next;
    }
    return (0);
}

int stack_length(t_stack stack) {
    int i;

    t_stack_link *tmp;
    i = 0;
    tmp = stack;
    while(tmp != NULL) {
        i++;
        tmp = tmp->next;
    } 
    return (i);
}

int stack_is_sort(t_stack stack) {
    t_stack_link *tmp;

    tmp = stack;

    if(stack_length(stack) == 1)
        return (0);

    while(tmp->next != NULL) {
        if(tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int min_stack_value(t_stack stack) {
    t_stack_link *tmp;
    int min;

    min = 0;
    if(stack_length(stack) > 0) {
        tmp = stack;
        min = tmp->value;
        while(tmp != NULL) {
            if(tmp->value < min)
                min = tmp->value;
            tmp = tmp->next;
        }
    }
    return (min);
}

int is_empty_stack(t_stack stack) {
    if(stack == NULL)
        return (1);
    return (0);
}

t_stack new_stack(void) {
    return (NULL);
}

t_stack push_stack_front(t_stack stack, int value) {
    
    t_stack new;
    t_stack_link *tmp;

    if((new = malloc(sizeof(t_stack_link))) == NULL)
        return (NULL);
    new->value = value;
    new->next = NULL;
    new->prev = NULL;
    if(is_empty_stack(stack))
        return (new);
    tmp = stack;
    while(tmp->next != NULL)
        tmp = tmp->next;
    new->prev = tmp;
    tmp->next = new;
    return (stack);
}

t_stack push_stack_back(t_stack stack, int value) {
    t_stack new;
    t_stack_link *tmp;

    if((new = malloc(sizeof(t_stack))) == NULL)
        return (NULL);
    new->value = value;
    if(is_empty_stack(stack)) {
        new->next = NULL;
        new->prev = NULL;
    }
    else {
        new->next = stack;
        stack->prev = new; 
    }
    
    return (new);
    
}

t_stack_link *pop_stack_back(t_stack *stack) {
    t_stack_link *tmp = NULL;

    if(!is_empty_stack(*stack)) {
        tmp = (*stack);
        (*stack)->prev = tmp;
        (*stack) = tmp->next;
    }
    return (tmp);
}

t_stack_link *pop_stack_front(t_stack *stack) {
    t_stack_link *tmp = NULL;

    if(is_empty_stack(*stack) || stack_length(*stack) == 1) {
         *stack = NULL;
        return (tmp);
    }
    tmp = *stack;
    while(tmp->next != NULL)
        tmp = tmp->next;

    tmp->prev->next = NULL;
    return (tmp);
}


void s(t_stack stack) {
    int tmp;

    if(!is_empty_stack(stack)) {
        tmp = stack->value;
        stack->value = stack->next->value;
        stack->next->value = tmp;
    }
}

void ss(t_stack a, t_stack b) {
    if(!is_empty_stack(a))
        s(a);
    if(!is_empty_stack(b))
        s(b);
}
 
void p(t_stack *dst, t_stack *src) {
    t_stack_link *top_src = pop_stack_back(src);
    if(top_src != NULL) {
        (*dst) = push_stack_back(*dst, top_src->value);
        free(top_src);
    }
}

void r(t_stack *stack) {
    t_stack_link *tmp; 
    if(!is_empty_stack(*stack)) {
        tmp = pop_stack_back(stack);
        *stack = push_stack_front(*stack, tmp->value);
    }
}

void rr(t_stack *a, t_stack *b) {
   if(!is_empty_stack(*a))
        r(a);
    if(!is_empty_stack(*b))
        r(b);
}

void rrr(t_stack *stack) {
    t_stack_link *tmp;

    tmp = (*stack); 
    while(tmp->next != NULL)
        tmp = tmp->next;
    
    (*stack) = push_stack_back(*stack, tmp->value);
    pop_stack_front(stack);
}

void rrrr(t_stack *a, t_stack *b) {
    if(!is_empty_stack(*a))
        rrr(a);
    if(!is_empty_stack(*b))
        rrr(b);
}