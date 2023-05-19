/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order_100_pt1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:31:27 by saazcon-          #+#    #+#             */
/*   Updated: 2023/05/19 21:11:21 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_next(struct s_var *v, int len, int i, int j)
{
	v->r = 0;
	v->rr = 0;
	if (i < (len - j))
	{
		while (i-- != 0)
			v->r++;
		v->next = v->top;
	}
	else
	{
		while (j++ != len)
			v->rr++;
		v->next = v->bot;
	}
}

void	ft_find_edge(struct s_var *v, int chunck)
{
	struct s_node	*aux;
	int				bt;
	int				tp;

	v->i = 0;
	v->j = 0;
	aux = v->a->cab;
	while (aux)
	{
		if (aux->number <= chunck)
		{
			v->i++;
			bt = v->j;
			v->bot = aux->number;
			if (v->i == 1)
			{
				tp = v->j;
				v->top = aux->number;
			}
		}
		v->j++;
		aux = aux->sig;
	}
	ft_find_next(v, v->j, tp, bt);
}

int	ft_next_chunck(struct s_var *v, int num_chunck)
{
	struct s_node	*aux;
	int				last_min;

	if ((v->len_a - v->len_b) <= (v->len_a / num_chunck))
		return (v->max);
	v->i = 1;
	last_min = v->min;
	while (v->i < (v->len_a / num_chunck))
	{
		v->min = v->max;
		aux = v->a->cab;
		while (aux)
		{
			if (v->min > aux->number && aux->number > last_min)
				v->min = aux->number;
			aux = aux->sig;
		}
		last_min = v->min;
		v->i++;
	}
	return (v->min);
}

int	ft_check_chunck(struct s_var *v, int chunck)
{
	struct s_node	*aux;

	aux = v->a->cab;
	while (aux)
	{
		if (aux->number <= chunck)
			return (1);
		aux = aux->sig;
	}
	return (0);
}

void	ft_sort_100(struct s_var *v)
{
	int	chunck;

	ft_min_max(v, v->a);
	chunck = ft_next_chunck(v, 6);
	while (v->a->cab)
	{
		ft_find_edge(v, chunck);
		ft_sort_chunck(v);
		if (!ft_check_chunck(v, chunck))
		{
			ft_min_max(v, v->a);
			chunck = ft_next_chunck(v, 6);
			ft_min_max(v, v->b);
		}
		if ((v->next < v->min) || (v->next > v->max))
			ft_min_max(v, v->b);
	}
	while (v->b->cab)
	{
		ft_find_place(v, v->max);
		ft_p(v->b, v->a, 'a');
		ft_min_max(v, v->b);
	}
}
