/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order_100_pt2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:31:27 by saazcon-          #+#    #+#             */
/*   Updated: 2023/05/19 19:14:37 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_top_a(struct s_var *v)
{
	while (v->rr > 0 || v->r > 0)
	{
		if (v->r-- > 0)
			ft_r(v->a, 'a');
		else if (v->rr-- > 0)
			ft_rr(v->a, 'a');
	}
}

void	ft_move_top_b(struct s_var *v, int len, int i)
{
	if (i < (len - i))
	{
		while (i-- > 0)
		{
			if (v->r-- > 0)
				ft_double_r(v);
			else
				ft_r(v->b, 'b');
		}
	}
	else
	{
		while (i++ < len)
		{
			if (v->rr-- > 0)
				ft_double_rr(v);
			else
				ft_rr(v->b, 'b');
		}
	}
	if (v->rr > 0 || v->r > 0)
		ft_move_top_a(v);
}

void	ft_find_place(struct s_var *v, int num)
{
	struct s_node	*aux;

	v->i = 0;
	v->j = 0;
	aux = v->b->cab;
	if (v->next > v->last_next)
	{
		while (aux && aux->number != v->max)
		{
			aux = aux->sig;
			v->i++;
		}
		v->j = v->i;
	}	
	while ((aux) && ((num != v->max && v->next < aux->number) \
	|| (num == v->max && aux->number != v->max)))
	{
		aux = aux->sig;
		v->i++;
	}
	v->j = v->i;
	ft_move_top_b(v, v->len_b, v->j);
}

void	ft_sort_chunck(struct s_var *v)
{
	ft_find_place(v, v->next);
	ft_p(v->a, v->b, 'b');
	v->len_b++;
	if (v->next < v->min)
		v->count_min++;
	else
		v->count_min = 0;
	if ((v->last_next > v->next && v->len_b == 2) || (v->count_min == 2))
		ft_s(v->b, 'b');
	else
		v->last_next = v->next;
}
