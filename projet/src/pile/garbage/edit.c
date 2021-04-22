/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:21:20 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 10:21:22 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

void		init_garbage(t_garbage *new)
{
	new->garb = init_pile();
	new->size_garb = 0;
}

int			inside_garbage(int value, t_garbage *new)
{
	int		i;
	t_pile	*ptr;

	i = 0;
	ptr = new->garb;
	while (i < new->size_garb)
	{
		if (value == ptr->value)
			return (1);
		i++;
		ptr = ptr->next;
	}
	return (0);
}

void		remove_garbage_value_at(int value, t_pile **pile, int *size)
{
	while ((*pile)->value != value)
		r(pile, *size);
	remove_to_start(pile, size);
}

t_garbage	*cpy_pile(t_pile *current, int size)
{
	int			i;
	t_garbage	*cpy;

	i = 0;
	if ((cpy = malloc(sizeof(t_garbage))) == NULL)
		return (NULL);
	cpy->garb = init_pile();
	cpy->size_garb = 0;
	while (i < size)
	{
		add_to_end(&cpy->garb, &cpy->size_garb, current->value);
		i++;
		current = current->next;
	}
	return (cpy);
}
