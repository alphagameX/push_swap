/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:19:36 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 10:19:37 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

t_pile	*create_link(int value)
{
	t_pile	*new;

	if ((new = malloc(sizeof(t_pile))) == NULL)
		return (NULL);
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int		max_value(t_pile *current, int size)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < size)
	{
		if (current->value >= res)
			res = current->value;
		i++;
		current = current->next;
	}
	return (res);
}

int		min_value(t_pile *current, int size)
{
	int	i;
	int	res;

	res = current->value;
	i = 0;
	while (i < size)
	{
		if (current->value < res)
			res = current->value;
		i++;
		current = current->next;
	}
	return (res);
}

int		show_pile(t_pile *pile, int size)
{
	t_pile	*ptr;
	int		i;

	i = 0;
	ptr = pile;
	while (i < size)
	{
		ft_printf("%d\n", ptr->value);
		ptr = ptr->next;
		i++;
	}
	return (i);
}
