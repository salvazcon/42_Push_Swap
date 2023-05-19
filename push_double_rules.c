/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_r_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 03:41:54 by saazcon-          #+#    #+#             */
/*   Updated: 2023/05/12 19:11:59 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_aux_rr(struct s_list *l)
{
	int				num;
	int				num_cab;
	struct s_node	*aux_node;

	num_cab = l->cab->number;
	num = l->cab->sig->number;
	aux_node = l->cab;
	while (aux_node->sig)
	{
		aux_node->number = num;
		aux_node = aux_node->sig;
		if (aux_node->sig)
			num = aux_node->sig->number;
	}
	aux_node->number = num_cab;
}

void	ft_aux_rrr(struct s_list *l)
{
	int				num;
	int				aux_num;
	struct s_node	*aux_node;

	num = l->cab->number;
	aux_num = l->cab->sig->number;
	aux_node = l->cab->sig;
	while (aux_node)
	{
		aux_node->number = num;
		num = aux_num;
		aux_node = aux_node->sig;
		if (aux_node)
			aux_num = aux_node->number;
	}
	l->cab->number = num;
}

void	ft_double_r(struct s_var *v)
{
	if (v->a->cab && v->a->cab->sig && v->b->cab && v->b->cab->sig)
	{
		ft_aux_rr(v->a);
		ft_aux_rr(v->b);
		write(1, "rr\n", 3);
	}
}

void	ft_double_rr(struct s_var *v)
{
	if (v->a->cab && v->a->cab->sig && v->b->cab && v->b->cab->sig)
	{
		ft_aux_rrr(v->a);
		ft_aux_rrr(v->b);
		write(1, "rrr\n", 4);
	}
}
