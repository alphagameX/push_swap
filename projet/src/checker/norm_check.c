/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:36:38 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/21 11:36:49 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"

void	check_return(t_ps app)
{
	if (is_sorted(app.a, app.size_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
