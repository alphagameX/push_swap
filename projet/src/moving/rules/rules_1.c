/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:22:13 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 00:22:15 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

void	s(t_pile **pile, int size)
{
	int value;

	if (*pile != NULL && size > 1)
	{
		value = (*pile)->value;
		(*pile)->value = (*pile)->next->value;
		(*pile)->next->value = value;
	}
}

void	ss(t_ps *app)
{
	s(&app->a, app->size_a);
	s(&app->b, app->size_b);
}

void	r(t_pile **pile, int size)
{
	if (*pile != NULL && size > 1)
	{
		add_to_end(pile, &size, (*pile)->value);
		remove_to_start(pile, &size);
	}
}

void	p(t_pile **dst, t_pile **src, int *size_dst, int *size_src)
{
	if (*src != NULL)
	{
		add_to_start(dst, size_dst, (*src)->value);
		remove_to_start(src, size_src);
	}
}

void	rs(t_pile **pile_a, t_pile **pile_b, int *size_a, int *size_b)
{
	r(pile_a, *size_a);
	r(pile_b, *size_b);
}
