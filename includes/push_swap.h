/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsibesson <tamsibesson@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:32:26 by tamsibesson       #+#    #+#             */
/*   Updated: 2022/06/23 10:23:20 by tamsibesson      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				v;
	int				pos;
	struct s_node	*n;
}					t_stack;

typedef struct s_bigsort
{
	int					bulk_size;
	int					bulk_begin;
	int					bulk_end;
	int					dist_up;
	int					dist_down;
	int					ac;
}						t_bigsort;

// UTILS
int		check_argv(int ac, char **av);
void	fill_a(t_stack **a, char **av);
void	_err(void);
void	print_stacks(t_stack **a, t_stack **b, int n);
void	update_stack_index(t_stack **a, char **av, int ac);
int		is_sorted(t_stack **a, t_stack **b);

// LIBFT UTILS
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(const char *str);

// LIST UTILS
t_stack	*newnode(int v, int pos);
void	add_back(t_stack **s, t_stack *new);
void	add_front(t_stack **s, t_stack *new);
t_stack	*getlast(t_stack *stack);
void	free_stack(t_stack **s);

// BIG SORT UTILS
void	init_bs(t_bigsort *bs, int ac);
int		get_bulksize(int ac);
void	rotate_push_to_a(t_stack **a, t_stack **b, int dist, int dir);
void	rotate_push_to_b(t_stack **a, t_stack **b, int dist, int dir);
void	reverse_stack(t_stack **rev, t_stack **a);
void	copy_stack(t_stack **copy, t_stack **src);

// MOVES
void	swap(t_stack **s, char *move);
void	push(t_stack **src, t_stack **dst, char *move);
void	rotate(t_stack **s, char *move);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **s, char *move);

// ALGO
void	sort_stacks(t_stack **a, t_stack **b, int ac);
void	big_sort(t_stack **a, t_stack **b, int ac);
void	sort_three(t_stack **a);

// SPLIT
char	**ft_split(char const *s, char c);
#endif
