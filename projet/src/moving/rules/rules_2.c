/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:04:59 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/21 20:05:01 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

void	rr(t_pile **pile, int size)
{
	t_pile	*ptr;
	int		i;

	if (*pile != NULL && size > 1)
	{
		i = 0;
		ptr = *pile;
		while (i < size - 1)
		{
			ptr = ptr->next;
			i++;
		}
		add_to_start(pile, &size, ptr->value);
		remove_to_end(pile, &size);
	}
}

void	rrs(t_pile **pile_a, t_pile **pile_b, int *size_a, int *size_b)
{
	rr(pile_a, *size_a);
	rr(pile_b, *size_b);
}
