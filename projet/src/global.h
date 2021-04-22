/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:35:16 by arthurtin         #+#    #+#             */
/*   Updated: 2021/04/22 10:36:14 by arthurtin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include "../libft/libft.h"

typedef struct		s_pile
{
	int				value;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

typedef struct		s_garbage
{
	t_pile			*garb;
	int				size_garb;
}					t_garbage;

typedef struct		s_ps
{
	t_pile			*a;
	t_pile			*b;
	int				size_a;
	int				size_b;
}					t_ps;

typedef struct		s_dir
{
	int				dir_a;
	int				dir_b;
	int				move_nb_a;
	int				move_nb_b;
	int				move_total;
	int				value;
}					t_dir;
void				init_app(t_ps *app);
void				parse_args(t_pile **pile_a, int *size, int argv,
					char **argc);
void				error(t_ps *app);
t_pile				*init_pile();
t_pile				*create_link(int value);
void				add_to_start(t_pile **current, int *size, int value);
void				add_to_end(t_pile **current, int *size, int value);
void				remove_to_start(t_pile **current, int *size);
void				remove_to_end(t_pile **current, int *size);
void				create_loop(t_pile **current, int size);
int					show_pile(t_pile *pile, int size);
int					has_duplicate(t_pile *pile, int size);
int					is_sorted(t_pile *current, int size);
int					max_value(t_pile *current, int size);
int					min_value(t_pile *current, int size);
void				free_pile(t_pile **current, int size);
void				init_garbage(t_garbage *new);
int					inside_garbage(int value, t_garbage *new);
void				remove_garbage_value_at(int value, t_pile **pile,
					int *size);
t_garbage			*cpy_pile(t_pile *current, int size);
void				free_garbage(t_garbage *garbage);
void				clear_pile_a(t_ps *app, t_garbage *new);
void				greater_than(t_pile *current, int size, t_garbage *best);
void				estimate_rotate(t_ps *app);
void				path_finding_b(t_pile **pile, int size, int searched,
					t_dir *dir);
void				path_finding_a(t_pile **pile, int size, int searched,
					t_dir *dir);
int					value_searched_in_a(t_pile *pile, int size, int searched);
void				execute_move(t_dir best, t_ps *app);
void				s(t_pile **pile, int size);
void				r(t_pile **pile, int size);
void				p(t_pile **dst, t_pile **src, int *size_dst,
					int *size_src);
void				rs(t_pile **pile_a, t_pile **pile_b, int *size_a,
					int *size_b);
void				ss(t_ps *app);
void				rr(t_pile **pile, int size);
void				rrs(t_pile **pile_a, t_pile **pile_b, int *size_a,
					int *size_b);
int					fast_r(t_pile **current, int size, int search);
void				check_return(t_ps app);

#endif
