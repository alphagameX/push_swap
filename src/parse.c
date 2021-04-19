#include "global.h"

void init_app(t_ps *app) {
	app->a = init_pile();
	app->b = init_pile();
	app->size_a = 0;
	app->size_b = 0;
}

void parse_args(t_pile **pile_a, int *size, int argv, char **argc) {
	int arg;

	arg = 1;
	while(arg < argv) {
		add_to_end(pile_a, size, ft_atoi(argc[arg]));
		arg++;
	} 
	if(has_duplicate(*pile_a, *size) == true)
		exit(0);
}