/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:56:51 by saazcon-          #+#    #+#             */
/*   Updated: 2023/05/19 21:07:33 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct	s_node	*ft_create_node(struct s_node *n, int num)
{
	n->number = num;
	n->sig = NULL;
	return (n);
}

void	ft_fill_list(struct s_var *v, int num)
{
	struct s_node	*n;
	struct s_node	*aux;

	n = ft_calloc(sizeof(struct s_node), 1);
	n = ft_create_node(n, num);
	v->len_a++;
	if (!v->a->cab)
		v->a->cab = n;
	else
	{
		aux = v->a->cab;
		while (aux->sig)
			aux = aux->sig;
		aux->sig = n;
	}
}

void	ft_fill_list_rev(struct s_list *l, int num)
{
	struct s_node	*n;
	struct s_node	*aux;

	n = ft_calloc(sizeof(struct s_node), 1);
	n = ft_create_node(n, num);
	if (!l->cab)
		l->cab = n;
	else
	{
		aux = l->cab;
		l->cab = n;
		l->cab->sig = aux;
	}
}
