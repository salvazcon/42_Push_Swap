/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:52:20 by saazcon-          #+#    #+#             */
/*   Updated: 2023/09/08 15:40:49 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reserve(struct s_var *v)
{
	v->b = ft_calloc(sizeof(struct s_list), 1);
	if (!v->b)
		ft_error(v);
	v->a = ft_calloc(sizeof(struct s_list), 1);
	if (!v->a)
		ft_error(v);
	v->i = 0;
}


int	main(int argc, char **argv)
{
	struct s_var	*v;

	if (argc < 2)
		return (0);
	v = ft_calloc(sizeof(struct s_var), 1);
	if (!v)
		ft_error(v);
	ft_reserve(v);
	while (++v->i != argc)
	{
		v->split = ft_split(argv[v->i], 32);
		v->j = -1;
		while (v->split[++v->j])
		{
			ft_check_letters(v, v->j);
			v->atoi = ft_atoi(v, v->split[v->j]);
			ft_fill_list(v, v->atoi);
		}
		ft_free_double(v->split);
	}
	ft_check_numbers(v);
	ft_math(v);
	ft_free(v);
	return (0);
}

/*
void	ft_read_list(struct s_list *l)
{
	struct s_node	*aux;

	aux = l->cab;
	while (aux)
	{
		printf("%d\n", aux->number);
		aux = aux->sig;
	}
}
void	ft_leaks(void)
{
	system("leaks -q push_swap");
	atexit(ft_leaks);
}
*/