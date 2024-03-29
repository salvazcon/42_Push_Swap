/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:33:58 by saazcon-          #+#    #+#             */
/*   Updated: 2023/09/08 15:36:52 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(struct s_list *l)
{
	struct s_node	*aux;

	while (l->cab)
	{
		aux = l->cab;
		l->cab = l->cab->sig;
		free(aux);
	}
	free(l);
}

void	ft_free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free(struct s_var *v)
{
	if (v->a)
		ft_free_list(v->a);
	if (v->b)
		ft_free_list(v->b);
	if (v->aux)
		free(v->aux);
	if (v)
		free(v);
}

void	ft_error(struct s_var *v)
{
	write(2, "Error\n", 6);
	ft_free(v);
	exit (1);
}
