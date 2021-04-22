/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:40:46 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 00:41:08 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

void	best_move(t_dir *best, t_ps *app)
{
	if (best->move_nb_a > 0 && best->move_nb_b > 0 &&
	best->dir_b == best->dir_a)
	{
		while (best->move_nb_b != 0 && best->move_nb_a != 0)
		{
			if (best->dir_a == 1)
			{
				rs(&app->a, &app->b, &app->size_a, &app->size_b);
				ft_putstr("rr\n");
			}
			else if (best->dir_a == -1)
			{
				rrs(&app->a, &app->b, &app->size_a, &app->size_b);
				ft_putstr("rrr\n");
			}
			best->move_nb_a--;
			best->move_nb_b--;
		}
	}
}

void	for_b(t_dir *best, t_ps *app)
{
	while (best->move_nb_b != 0)
	{
		if (best->dir_b == 1)
		{
			r(&app->b, app->size_b);
			ft_putstr("rb\n");
		}
		else if (best->dir_b == -1)
		{
			rr(&app->b, app->size_b);
			ft_putstr("rrb\n");
		}
		best->move_nb_b--;
	}
}

void	for_a(t_dir *best, t_ps *app)
{
	while (best->move_nb_a != 0)
	{
		if (best->dir_a == 1)
		{
			r(&app->a, app->size_a);
			ft_putstr("ra\n");
		}
		else if (best->dir_a == -1)
		{
			rr(&app->a, app->size_a);
			ft_putstr("rra\n");
		}
		best->move_nb_a--;
	}
}

void	execute_move(t_dir best, t_ps *app)
{
	best_move(&best, app);
	for_a(&best, app);
	for_b(&best, app);
	p(&app->a, &app->b, &app->size_a, &app->size_b);
	ft_putstr("pa\n");
}
