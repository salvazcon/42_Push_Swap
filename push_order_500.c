/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order_500.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:47:16 by saazcon-          #+#    #+#             */
/*   Updated: 2023/05/19 19:31:04 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_500(struct s_var *v)
{
	int	chunck;

	ft_min_max(v, v->a);
	chunck = ft_next_chunck(v, 13);
	while (v->a->cab)
	{
		ft_find_edge(v, chunck);
		ft_sort_chunck(v);
		if (!ft_check_chunck(v, chunck))
		{
			ft_min_max(v, v->a);
			chunck = ft_next_chunck(v, 13);
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
