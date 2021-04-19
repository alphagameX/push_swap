#include "global.h"

int main(int argv, char **argc) {
	t_ps app;
	t_garbage new;

	if(argv < 2)
		return (0);
	init_app(&app);
	parse_args(&app.a, &app.size_a, argv, argc);
	create_loop(&app.a, app.size_a);
	if(is_sorted(app.a, app.size_a) == 1)
		return (1);
	greater_than(app.a, app.size_a, &new);
	clear_pile_a(&app, &new);
	while(app.size_b != 0) {
		create_loop(&app.a, app.size_a);
		create_loop(&app.b, app.size_b);
		estimate_rotate(&app.a, &app.b, &app.size_a, &app.size_b);
	}
	fast_r(&app.a, app.size_a, min_value(app.a, app.size_a));

	// show_pile(app.a, app.size_a);

	free_pile(&app.a, app.size_a);
	free_pile(&app.b, app.size_b);
	// system("leaks push_swap");
	return (0);
}