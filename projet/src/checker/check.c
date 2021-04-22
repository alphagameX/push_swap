/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:35:42 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/21 11:36:20 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global.h"
#include "limits.h"

void	rotate(t_ps *app, char *line, int *len)
{
	if (ft_strncmp(line, "ra", 2) == 0)
	{
		r(&app->a, app->size_a);
		*len += 1;
	}
	if (ft_strncmp(line, "rb", 2) == 0)
	{
		r(&app->b, app->size_b);
		*len += 1;
	}
	if (ft_strncmp(line, "rra", 3) == 0)
	{
		rr(&app->a, app->size_a);
		*len += 1;
	}
	if (ft_strncmp(line, "rrb", 3) == 0)
	{
		rr(&app->b, app->size_b);
		*len += 1;
	}
}

void	push_swap(t_ps *app, char *line, int *len)
{
	if (ft_strncmp(line, "pb", 2) == 0)
	{
		p(&app->b, &app->a, &app->size_b, &app->size_a);
		*len += 1;
	}
	if (ft_strncmp(line, "pa", 2) == 0)
	{
		p(&app->a, &app->b, &app->size_a, &app->size_b);
		*len += 1;
	}
	if (ft_strncmp(line, "sa", 2) == 0)
	{
		s(&app->a, app->size_a);
		*len += 1;
	}
	if (ft_strncmp(line, "sb", 2) == 0)
	{
		s(&app->b, app->size_b);
		*len += 1;
	}
}

void	all(t_ps *app, char *line, int *len)
{
	if (ft_strncmp(line, "rr", 2) == 0 && ft_strlen(line) == 2)
	{
		rs(&app->a, &app->b, &app->size_a, &app->size_b);
		*len += 1;
	}
	if (ft_strncmp(line, "rrr", 3) == 0 && ft_strlen(line) == 3)
	{
		rrs(&app->a, &app->b, &app->size_a, &app->size_b);
		*len += 1;
	}
	if (ft_strncmp(line, "ss", 2) == 0 && ft_strlen(line) == 2)
	{
		ss(app);
		*len += 1;
	}
}

int		check_authorized(char *str)
{
	static char *authorized[] = {
		"sa", "sb", "rra", "rrb", "rr", "ra", "rb", "rrr", "pa", "pb",
		"ss", NULL};
	int			i;
	int			compare;

	i = 0;
	compare = 0;
	while (authorized[i] != NULL)
	{
		if (ft_strncmp((const char *)str, (const char *)authorized[i],
					ft_strlen(authorized[i]) + 1) == 0)
			compare = 1;
		i++;
	}
	return (compare);
}

int		main(int argv, char **argc)
{
	t_ps	app;
	char	*line;
	int		ret;
	int		len;

	len = 0;
	if (argv < 2)
		return (0);
	init_app(&app);
	parse_args(&app.a, &app.size_a, argv, argc);
	ret = 1;
	while (ret)
	{
		if ((ret = get_next_line(0, &line)) == -1 || (check_authorized(line)
		== 0 && *line != '\0'))
			error(&app);
		rotate(&app, line, &len);
		push_swap(&app, line, &len);
		all(&app, line, &len);
	}
	check_return(app);
	return (0);
}
