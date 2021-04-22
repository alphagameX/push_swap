/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:23:09 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 10:23:19 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int	main(int argv, char **argc)
{
	t_ps		app;
	t_garbage	new;

	if (argv < 2)
		return (0);
	init_app(&app);
	parse_args(&app.a, &app.size_a, argv, argc);
	if (is_sorted(app.a, app.size_a) == 1)
		return (1);
	greater_than(app.a, app.size_a, &new);
	clear_pile_a(&app, &new);
	while (app.size_b != 0)
		estimate_rotate(&app);
	fast_r(&app.a, app.size_a, min_value(app.a, app.size_a));
	free_pile(&app.a, app.size_a);
	free_pile(&app.b, app.size_b);
	return (0);
}
