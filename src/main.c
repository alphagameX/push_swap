#include "global.h"

int main(int argv, char **argc) {

	t_ps app;
	int arg;

	if(argv < 2)
		return (0);
	app.a = init_pile();
	app.b = init_pile();

	app.size_a = 0;
	app.size_b = 0;

	arg = 1;
	while(arg < argv) {
		add_to_end(&app.a, &app.size_a, ft_atoi(argc[arg]));
		arg++;
	}   
	if(has_duplicate(app.a, app.size_a) == true)
		return (false);

	create_loop(&app.a, app.size_a);
	// set_index(&app.a, app.size_a);

	if(is_sorted(app.a, app.size_a) == 1) {
		return (1);
	}

	t_garbage *new = greater_than(app.a, app.size_a);

	

	while(new->size_garb != 0) {
		fast_r(&app.a, app.size_a, new->garb->value);
		ft_printf("pb\n");
		p(&app.b, &app.a, &app.size_b, &app.size_a);
		remove_to_start(&new->garb, &new->size_garb); 
	}

	while(app.size_b != 0) {
		create_loop(&app.a, app.size_a);
		create_loop(&app.b, app.size_b);
		estimate_rotate(&app.a, &app.b, &app.size_a, &app.size_b);
	}

	fast_r(&app.a, app.size_a, min_value(app.a, app.size_a));


	ft_printf("\n\n\n---PILE A---\n");
	ft_printf("len : %d\n", show_pile(app.a, app.size_a));

	// ft_printf("---PILE B---\n");
	// ft_printf("len : %d\n", show_pile(app.b, app.size_b));

	free_pile(&app.a, app.size_a);
	free_pile(&app.b, app.size_b);
	return (0);
}