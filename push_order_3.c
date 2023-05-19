/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_0-3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:06:48 by saazcon-          #+#    #+#             */
/*   Updated: 2023/04/24 19:37:03 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(struct s_var *v)
{
	if (v->a->cab->number > v->a->cab->sig->number)
		ft_s(v->a, 'a');
}

void	ft_sort_three(struct s_var *v)
{
	int	pri;
	int	seg;
	int	ter;

	pri = v->a->cab->number;
	seg = v->a->cab->sig->number;
	ter = v->a->cab->sig->sig->number;
	if (pri > seg && seg < ter && ter > pri)
		ft_s(v->a, 'a');
	else if (pri > seg && seg > ter && ter < pri)
	{
		ft_s(v->a, 'a');
		ft_rr(v->a, 'a');
	}
	else if (pri > seg && seg < ter && ter < pri)
		ft_r(v->a, 'a');
	else if (pri < seg && seg > ter && ter > pri)
	{
		ft_s(v->a, 'a');
		ft_r(v->a, 'a');
	}
	else if (pri < seg && seg > ter && ter < pri)
		ft_rr(v->a, 'a');
}
