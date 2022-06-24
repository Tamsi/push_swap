/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsibesson <tamsibesson@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:20:10 by tamsibesson       #+#    #+#             */
/*   Updated: 2022/06/23 09:34:40 by tamsibesson      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_push_to_b(t_stack **a, t_stack **b, int dist, int dir)
{
	int	i;

	i = -1;
	if (dir == 1)
		while (++i < dist)
			rotate(a, "ra");
	if (dir == 0)
		while (++i < dist + 1)
			reverse_rotate(a, "rra");
	push(a, b, "pb");
}

void	rotate_push_to_a(t_stack **a, t_stack **b, int dist, int dir)
{
	int	i;

	i = -1;
	if (dir == 1)
		while (++i < dist)
			rotate(b, "rb");
	if (dir == 0)
		while (++i < dist + 1)
			reverse_rotate(b, "rrb");
	push(b, a, "pa");
}

void	copy_stack(t_stack **copy, t_stack **src)
{
	t_stack	*tmp;
	t_stack	*node;

	tmp = *src;
	while (tmp)
	{
		node = newnode(tmp->v, tmp->pos);
		add_back(copy, node);
		tmp = tmp->n;
	}
}

void	reverse_stack(t_stack **rev, t_stack **a)
{
	t_stack	*copy;
	t_stack	*tmp;

	copy = 0;
	copy_stack(&copy, a);
	while (copy)
	{
		tmp = copy->n;
		add_front(rev, copy);
		copy = tmp;
	}
}

void	init_bs(t_bigsort *bs, int ac)
{
	bs->bulk_size = get_bulksize(ac);
	bs->bulk_begin = 0;
	bs->bulk_end = bs->bulk_size;
	bs->dist_up = 0;
	bs->dist_down = 0;
	bs->ac = ac;
}
