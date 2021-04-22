/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:16:28 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 10:16:31 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

t_pile	*init_pile(void)
{
	return (NULL);
}

void	fill_pile(t_pile **tmp, t_pile **ptr, int *size)
{
	if (*size == 1)
	{
		(*tmp)->next = *ptr;
		(*tmp)->prev = *ptr;
		(*ptr)->prev = *tmp;
		(*ptr)->next = *tmp;
	}
	else
	{
		(*tmp)->prev = (*ptr)->prev;
		(*tmp)->next = *ptr;
		(*ptr)->prev->next = *tmp;
		(*ptr)->prev = *tmp;
	}
}

void	add_to_start(t_pile **current, int *size, int value)
{
	t_pile *tmp;
	t_pile *ptr;

	if (*current == NULL || *size == 0)
		*current = create_link(value);
	else
	{
		ptr = *current;
		tmp = create_link(value);
		fill_pile(&tmp, &ptr, size);
		*current = tmp;
	}
	*size += 1;
}

void	add_to_end(t_pile **current, int *size, int value)
{
	t_pile	*tmp;
	t_pile	*ptr;
	int		i;

	if (*current == NULL || *size == 0)
		*current = create_link(value);
	else
	{
		tmp = create_link(value);
		ptr = *current;
		i = 0;
		while (i < *size - 1)
		{
			i++;
			ptr = ptr->next;
		}
		(*current)->prev = tmp;
		tmp->prev = ptr;
		ptr->next = tmp;
		tmp->next = *current;
	}
	*size += 1;
}

void	create_loop(t_pile **current, int size)
{
	int		i;
	t_pile	*start;

	i = 0;
	start = *current;
	while (i < size - 1)
	{
		*current = (*current)->next;
		i++;
	}
	start->prev = *current;
	(*current)->next = start;
	*current = start;
}
