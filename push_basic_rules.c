/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_basic_rules.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:55:12 by saazcon-          #+#    #+#             */
/*   Updated: 2023/05/15 18:22:08 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(struct s_list *l, char letter)
{
	int	num;

	if (!l->cab || !l->cab->sig)
		return ;
	num = l->cab->number;
	l->cab->number = l->cab->sig->number;
	l->cab->sig->number = num;
	write(1, "s", 1);
	write(1, &letter, 1);
	write(1, "\n", 1);
}

void	ft_p(struct s_list *l1, struct s_list *l2, char letter)
{
	if (!l1->cab)
		return ;
	ft_fill_list_rev(l2, l1->cab->number);
	if (l1->cab->sig)
		l1->cab = l1->cab->sig;
	else
		l1->cab = NULL;
	write(1, "p", 1);
	write(1, &letter, 1);
	write(1, "\n", 1);
}

void	ft_r(struct s_list *l, char letter)
{
	int				num;
	int				num_cab;
	struct s_node	*aux_node;

	if (!l->cab || !l->cab->sig)
		return ;
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
	write(1, "r", 1);
	write(1, &letter, 1);
	write(1, "\n", 1);
}

void	ft_rr(struct s_list *l, char letter)
{
	int				num;
	int				aux_num;
	struct s_node	*aux_node;

	if (!l->cab || !l->cab->sig)
		return ;
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
	write(1, "rr", 2);
	write(1, &letter, 1);
	write(1, "\n", 1);
}
