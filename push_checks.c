/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:10:23 by saazcon-          #+#    #+#             */
/*   Updated: 2023/09/08 15:38:42 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_letters(struct s_var *v, int i)
{
	int	j;

	j = 0;
	if (v->split[i][j] == 45 && v->split[i][j + 1])
		j++;
	while (v->split[i][j])
	{
		if ((v->split[i][j]) < 48 || (v->split[i][j] > 57))
		{
			ft_free_double(v->split);
			ft_error(v);
		}
		j++;
	}
}

void	ft_check_numbers(struct s_var *v)
{
	struct s_node	*aux_node1;
	struct s_node	*aux_node2;

	aux_node1 = v->a->cab;
	while (aux_node1)
	{
		aux_node2 = aux_node1->sig;
		while (aux_node2)
		{
			if (aux_node1->number == aux_node2->number)
				ft_error(v);
			aux_node2 = aux_node2->sig;
		}
		aux_node1 = aux_node1->sig;
	}
}
