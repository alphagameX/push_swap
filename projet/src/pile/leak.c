/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:21:59 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 10:22:20 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

void	free_pile(t_pile **current, int size)
{
	int		i;
	t_pile	*ptr;

	i = 0;
	while (i < size)
	{
		i++;
		ptr = (*current);
		(*current) = (*current)->next;
		if (ptr != NULL)
			free(ptr);
	}
	*current = init_pile();
}

void	free_garbage(t_garbage *garbage)
{
	free_pile(&garbage->garb, garbage->size_garb);
	free(garbage);
}

void	error(t_ps *app)
{
	free_pile(&app->a, app->size_a);
	free_pile(&app->b, app->size_b);
	ft_putstr("Error\n");
	exit(1);
}
