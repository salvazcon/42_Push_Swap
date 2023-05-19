/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:02:45 by saazcon-          #+#    #+#             */
/*   Updated: 2023/04/27 00:15:40 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_atoi(struct s_var *v, char *str)
{
	int						i;
	int						sign;
	long long int			val;

	i = 0;
	sign = 1;
	val = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = (sign * -1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = (val * 10);
		val = (val + (str[i] - 48));
		i++;
	}
	if (-2147483648 > (val * sign) || (val * sign) > 2147483647)
		ft_error(v);
	return (val * sign);
}
