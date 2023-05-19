/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:06:18 by saazcon-          #+#    #+#             */
/*   Updated: 2023/05/11 20:06:24 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_step_one(struct s_var *v, int num)
{
	ft_p(v->b, v->a, 'a');
	if (num > v->max)
		ft_r(v->a, 'a');
	ft_min_max(v, v->a);
}

void	ft_step_two(struct s_var *v)
{
	ft_r(v->a, 'a');
	ft_p(v->b, v->a, 'a');
	if (v->b->cab)
	{
		if (v->b->cab->number < v->a->cab->number && \
		v->b->cab->number > v->min && v->b->cab->number < v->max)
			ft_p(v->b, v->a, 'a');
		else if (v->b->cab->number > v->a->cab->number && \
		v->b->cab->number < v->a->cab->sig->number && \
		v->b->cab->number > v->min && v->b->cab->number < v->max)
		{
			ft_p(v->b, v->a, 'a');
			ft_s(v->a, 'a');
		}
	}
	ft_rr(v->a, 'a');
}

void	ft_step_tree(struct s_var *v)
{
	ft_rr(v->a, 'a');
	ft_p(v->b, v->a, 'a');
	if (v->b->cab)
	{
		if (v->b->cab->number > v->a->cab->number && \
		v->b->cab->number > v->min && v->b->cab->number < v->max)
		{
			ft_r(v->a, 'a');
			ft_p(v->b, v->a, 'a');
		}
		else if (v->b->cab->number < v->a->cab->number && \
		v->b->cab->number > v->a->cab->sig->sig->sig->number && \
		v->b->cab->number > v->min && v->b->cab->number < v->max)
		{
			ft_p(v->b, v->a, 'a');
			ft_r(v->a, 'a');
		}
		ft_r(v->a, 'a');
	}
	else
		ft_r(v->a, 'a');
	ft_r(v->a, 'a');
}

void	ft_step_four(struct s_var *v)
{
	ft_r(v->a, 'a');
	ft_r(v->a, 'a');
	ft_p(v->b, v->a, 'a');
	ft_rr(v->a, 'a');
	ft_rr(v->a, 'a');
}

void	ft_sort_five(struct s_var *v)
{
	int	num;

	while (v->len_a-- != 3 && !ft_check_order(v->a))
		ft_p(v->a, v->b, 'b');
	ft_sort_three(v);
	ft_min_max(v, v->a);
	while (v->b->cab)
	{
		num = v->b->cab->number;
		if (num < v->min || num > v->max)
			ft_step_one(v, num);
		else if (num < v->a->cab->sig->number)
			ft_step_two(v);
		else
		{
			if (num < v->a->cab->sig->sig->number && \
			v->a->cab->sig->sig->sig)
				ft_step_four(v);
			else
				ft_step_tree(v);
		}
	}
}
