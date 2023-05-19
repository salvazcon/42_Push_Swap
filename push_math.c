/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:14:56 by saazcon-          #+#    #+#             */
/*   Updated: 2023/05/19 20:57:17 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order(struct s_list *l)
{
	struct s_node	*aux;

	if (!l->cab || !l->cab->sig)
		return (0);
	aux = l->cab;
	while (aux->sig)
	{
		if (aux->number > aux->sig->number)
			return (0);
		aux = aux->sig;
	}
	return (1);
}

int	ft_check_order_rev(struct s_list *l)
{
	struct s_node	*aux;

	if (!l->cab || !l->cab->sig)
		return (0);
	aux = l->cab;
	while (aux->sig)
	{
		if (aux->number < aux->sig->number)
			return (0);
		aux = aux->sig;
	}
	return (1);
}

void	ft_min_max(struct s_var *v, struct s_list *l)
{
	struct s_node	*aux;

	if (!l->cab)
		return ;
	aux = l->cab;
	v->max = l->cab->number;
	v->min = l->cab->number;
	while (aux)
	{
		if (v->min > aux->number)
			v->min = aux->number;
		if (v->max < aux->number)
			v->max = aux->number;
		aux = aux->sig;
	}
}

void	ft_math(struct s_var *v)
{
	if (ft_check_order(v->a) || v->len_a <= 1)
		return ;
	else if (v->len_a == 2)
		ft_sort_two(v);
	else if (v->len_a == 3)
		ft_sort_three(v);
	else if (v->len_a <= 5)
		ft_sort_five(v);
	else if (v->len_a <= 100)
		ft_sort_100(v);
	else
		ft_sort_500(v);
}
