/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinseau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:52:07 by atinseau          #+#    #+#             */
/*   Updated: 2021/04/22 10:52:10 by atinseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

void	not_sorted_pile(t_pile *current, int size, t_garbage *new)
{
	int i;
	int value;

	i = 0;
	value = current->value;
	if (new->size_garb > 0)
		free_pile(&new->garb, new->size_garb);
	new->garb = init_pile();
	new->size_garb = 0;
	while (i < size)
	{
		if (current->value <= value)
			value = current->value;
		else
			add_to_end(&new->garb, &new->size_garb, current->value);
		i++;
		current = current->prev;
	}
}

void	is_greater_garb(t_garbage *new, int *best_size, int *best_index, int i)
{
	if (new->size_garb < *best_size)
	{
		*best_size = new->size_garb;
		*best_index = i;
	}
}

void	greater_than(t_pile *current, int size, t_garbage *best)
{
	t_garbage	new;
	t_pile		*ptr;
	int			i;
	int			best_size;
	int			best_index;

	i = -1;
	init_garbage(&new);
	best_size = size;
	best_index = 0;
	ptr = current;
	while (i++ < size)
	{
		not_sorted_pile(ptr, size, &new);
		is_greater_garb(&new, &best_size, &best_index, i);
		ptr = ptr->next;
	}
	i = -1;
	while (i++ != best_index)
		current = current->next;
	not_sorted_pile(current, size, &new);
	best->garb = new.garb;
	best->size_garb = new.size_garb;
}
