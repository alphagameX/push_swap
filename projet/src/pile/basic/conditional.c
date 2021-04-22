/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditional.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:06:11 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 10:06:34 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

int	has_duplicate(t_pile *pile, int size)
{
	int		i;
	int		e;
	t_pile	*ptr;
	t_pile	*tmp;

	ptr = pile;
	e = 0;
	i = 0;
	while (i < size - 1)
	{
		tmp = ptr->next;
		e = 0;
		while (e + i < size - 1)
		{
			if (tmp->value == ptr->value)
				return (1);
			e++;
			tmp = tmp->next;
		}
		ptr = ptr->next;
		i++;
	}
	return (0);
}

int	is_sorted(t_pile *current, int size)
{
	t_pile	*ptr;
	int		i;

	i = 0;
	ptr = current;
	while (i < size - 1)
	{
		if (ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
		i++;
	}
	return (1);
}
