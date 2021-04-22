/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinseau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:53:33 by atinseau          #+#    #+#             */
/*   Updated: 2021/04/22 10:53:34 by atinseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../global.h"

void	remove_to_start(t_pile **current, int *size)
{
	t_pile	*f;

	if (*size > 0 || *current != NULL)
	{
		f = *current;
		if (*size > 1)
		{
			(*current) = (*current)->next;
			(*current)->prev = f->prev;
			(*current)->prev->next = *current;
			free(f);
		}
		else
		{
			free(*current);
			*current = NULL;
		}
		*size -= 1;
	}
}

void	remove_to_end(t_pile **current, int *size)
{
	int		i;
	t_pile	*ptr;

	i = 0;
	if (*size > 0 || *current != NULL)
	{
		ptr = *current;
		while (i < *size - 1)
		{
			i++;
			ptr = ptr->next;
		}
		ptr->prev->next = (*current);
		(*current)->prev = ptr->prev;
		free(ptr);
		ptr = NULL;
		*size -= 1;
	}
}
