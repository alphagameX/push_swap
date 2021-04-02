#include "../global.h"

int main(int argv, char **argc) {

    t_stack a = new_stack();
    t_stack b = new_stack();
    int i;
    int value;

    i = 1;
    if(argv < 3)
        return (0);
    while(i < argv) {
        a = push_stack_front(a, ft_atoi(argc[i]));
        i++;
    }

    if(stack_has_doublon(a))
        return (0);
    
    value = stack_length(a);

    //ft_printf("%d\n", value);

    
    // V2

    // while(!stack_is_sort(a) || value != stack_length(a)) {
    //     if(a->value > a->next->value) {
    //         s(a);
    //         ft_printf("sa\n");
    //     }

    //     if(stack_length(a) == 2) {
    //         p(&b, &a);
    //         ft_printf("pb\n");
    //         p(&b, &a);
    //         ft_printf("pb\n");
    //     }
    //     while(stack_length(a) > 2 && a->value < a->next->value)
    //         p(&b, &a);
    //         ft_printf("pb\n");
        
    //     if(stack_length(a) == 0) {
    //         while(stack_length(b) > 0) {
    //             p(&a, &b);
    //             ft_printf("pa\n");
    //         }
    //     }
                
    // }

    // V3


    // V1

    while(!stack_is_sort(a) || value != stack_length(a)) {
        while(a->value != min_stack_value(a)) {
            //ft_printf("ra\n");
            r(&a);
        }
        //ft_printf("pb\n");
        p(&b, &a);

        break;

        if(stack_length(a) == 0) {
            while(stack_length(b) != 0) {
                //ft_printf("pa\n");
                p(&a, &b);
            }
            break;
        }

    }


    print_stack(a);
    write(1, "\n", 1);
    print_stack(b);
    return (0);
}