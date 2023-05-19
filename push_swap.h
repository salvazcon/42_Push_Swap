/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:08:38 by saazcon-          #+#    #+#             */
/*   Updated: 2023/05/19 20:33:30 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//INCLUDES
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

struct	s_list{
	struct s_node	*cab;
};

struct	s_node { //*n
	int				number;
	struct s_node	*sig;
};

struct	s_var{ //*v
	struct s_list	*a;
	struct s_list	*b;
	struct s_node	*aux;
	char			**split;
	int				atoi;
	int				len_a;
	int				len_b;
	int				count_min;
	int				min;
	int				max;
	int				top;
	int				bot;
	int				next;
	int				last_next;
	int				rr;
	int				r;
	int				i;
	int				j;
};

int		ft_strlen(char *str);
int		ft_atoi(struct s_var *v, char *str);
int		ft_check_order(struct s_list *l);
int		ft_check_order_rev(struct s_list *l);
int		ft_check_chunck(struct s_var *v, int chunck);
int		ft_next_chunck(struct s_var *v, int num_chunck);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_error(struct s_var *v);
void	ft_free(struct s_var *v);
void	ft_check_numbers(struct s_var *v);
void	ft_check_letters(struct s_var *v, int i);
void	ft_fill_list(struct s_var *v, int num);
void	ft_fill_list_rev(struct s_list *l, int num);
void	ft_s(struct s_list *l, char letter);
void	ft_r(struct s_list *l, char letter);
void	ft_rr(struct s_list *l, char letter);
void	ft_p(struct s_list *l1, struct s_list *l2, char letter);
void	ft_double_r(struct s_var *v);
void	ft_double_rr(struct s_var *v);
void	ft_math(struct s_var *v);
void	ft_min_max(struct s_var *v, struct s_list *l);
void	ft_sort_two(struct s_var *v);
void	ft_sort_three(struct s_var *v);
void	ft_sort_five(struct s_var *v);
void	ft_sort_100(struct s_var *v);
void	ft_sort_500(struct s_var *v);
void	ft_sort_chunck(struct s_var *v);
void	ft_find_edge(struct s_var *v, int chunck);
void	ft_find_place(struct s_var *v, int num);
void	ft_read_list(struct s_list *l);
//void	ft_find_max(struct s_var *v);

#endif