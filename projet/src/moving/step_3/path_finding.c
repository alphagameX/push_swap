/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:26:23 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 00:27:14 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

int		value_searched_in_a(t_pile *pile, int size, int searched)
{
	t_pile	*ptr;
	int		max;
	int		min;

	max = max_value(pile, size);
	min = min_value(pile, size);
	ptr = pile;
	if (searched > max)
		return (min);
	while (ptr->value > searched)
		ptr = ptr->next;
	while (ptr->value < searched)
		ptr = ptr->next;
	return (ptr->value);
}

void	nb_rr(int rrb, int rb, int *dir, int *move)
{
	if (rrb < rb)
	{
		*dir = 1;
		*move = rrb;
	}
	else
	{
		*dir = -1;
		*move = rb;
	}
}

void	path_finding_b(t_pile **pile, int size, int searched, t_dir *dir)
{
	int		rb;
	int		rrb;
	t_pile	*ptr;

	rrb = 0;
	rb = 0;
	ptr = *pile;
	while (ptr->value != searched)
	{
		ptr = ptr->next;
		rrb++;
	}
	while (ptr->value != (*pile)->value)
	{
		ptr = ptr->next;
		rb++;
	}
	nb_rr(rrb, rb, &dir->dir_b, &dir->move_nb_b);
}

void	path_finding_a(t_pile **pile, int size, int searched, t_dir *dir)
{
	int		rb;
	int		rrb;
	t_pile	*ptr;

	rrb = 0;
	rb = 0;
	ptr = *pile;
	while (ptr->value != searched)
	{
		ptr = ptr->next;
		rrb++;
	}
	while (ptr->value != (*pile)->value)
	{
		ptr = ptr->next;
		rb++;
	}
	nb_rr(rrb, rb, &dir->dir_a, &dir->move_nb_a);
}
