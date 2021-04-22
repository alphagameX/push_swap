/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:41:41 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 00:42:15 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

void	init_best(t_dir *dir, int a, int b)
{
	dir->move_nb_a = a;
	dir->move_nb_b = b;
	dir->value = 0;
	dir->dir_a = 0;
	dir->dir_b = 0;
	dir->move_total = a + b;
}

void	check_estimate(t_dir *tmp, t_dir *best)
{
	if (tmp->dir_a == tmp->dir_b)
		tmp->move_total = (tmp->move_nb_a > tmp->move_nb_b) ?
		tmp->move_nb_a : tmp->move_nb_b;
	else
		tmp->move_total = tmp->move_nb_a + tmp->move_nb_b;
	if (best->move_total > tmp->move_total)
	{
		best->move_nb_a = tmp->move_nb_a;
		best->move_nb_b = tmp->move_nb_b;
		best->dir_b = tmp->dir_b;
		best->dir_a = tmp->dir_a;
		best->move_total = tmp->move_total;
	}
}

void	estimate_rotate(t_ps *app)
{
	t_dir	best;
	t_dir	tmp;
	t_pile	*ptr;
	int		i;

	i = 0;
	init_best(&best, app->size_a, app->size_b);
	ptr = app->b;
	while (i < app->size_b)
	{
		path_finding_b(&app->b, app->size_b, ptr->value, &tmp);
		path_finding_a(&app->a, app->size_a, value_searched_in_a(app->a,
		app->size_a, ptr->value), &tmp);
		check_estimate(&tmp, &best);
		ptr = ptr->next;
		i++;
	}
	execute_move(best, app);
}
