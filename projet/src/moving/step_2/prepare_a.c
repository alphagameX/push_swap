/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinseau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:52:44 by atinseau          #+#    #+#             */
/*   Updated: 2021/04/22 10:52:49 by atinseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

int		better_garbage(t_pile **pile, int size, t_garbage **new)
{
	t_garbage	tmp;

	s(pile, size);
	greater_than(*pile, size, &tmp);
	if (tmp.size_garb < (*new)->size_garb)
	{
		free_pile(&(*new)->garb, (*new)->size_garb);
		(*new)->garb = tmp.garb;
		(*new)->size_garb = tmp.size_garb;
		return (1);
	}
	free_pile(&tmp.garb, tmp.size_garb);
	s(pile, size);
	return (0);
}

void	clear_pile_a(t_ps *app, t_garbage *new)
{
	while (new->size_garb != 0)
	{
		if (better_garbage(&app->a, app->size_a, &new))
		{
			ft_putstr("sa\n");
		}
		else if (inside_garbage(app->a->value, new))
		{
			remove_garbage_value_at(app->a->value, &new->garb, &new->size_garb);
			p(&app->b, &app->a, &app->size_b, &app->size_a);
			ft_putstr("pb\n");
		}
		else
		{
			r(&app->a, app->size_a);
			ft_putstr("ra\n");
		}
	}
	free_pile(&new->garb, new->size_garb);
}
