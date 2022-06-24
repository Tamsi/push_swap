/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsibesson <tamsibesson@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:34:22 by tamsibesson       #+#    #+#             */
/*   Updated: 2022/06/23 09:34:45 by tamsibesson      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_bulk_range(t_stack **a, int start, int end)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->pos >= start && tmp->pos <= end)
			return (i);
		tmp = tmp->n;
		i++;
	}
	return (-1);
}

int	find_biggest(t_stack **s, int biggest)
{
	t_stack	*tmp;
	int		dist;

	tmp = *s;
	dist = 0;
	while (tmp)
	{
		if (tmp->pos == biggest)
			return (dist);
		tmp = tmp->n;
		dist++;
	}
	return (-1);
}

void	push_bulks_in_b(t_stack **a, t_stack **b, t_bigsort *bs, t_stack **rev)
{
	while (*a)
	{
		bs->dist_up = 0;
		bs->dist_down = 0;
		while (bs->dist_up != -1 && bs->dist_down != -1)
		{
			reverse_stack(rev, a);
			bs->dist_up = check_bulk_range(a, bs->bulk_begin, bs->bulk_end);
			bs->dist_down = check_bulk_range(rev, bs->bulk_begin, bs->bulk_end);
			if (bs->dist_up <= bs->dist_down \
			&& bs->dist_down != -1 && bs->dist_up != -1)
				rotate_push_to_b(a, b, bs->dist_up, 1);
			if (bs->dist_up > bs->dist_down \
			&& bs->dist_down != -1 && bs->dist_up != -1)
				rotate_push_to_b(a, b, bs->dist_down, 0);
			free_stack(rev);
		}
		bs->bulk_begin += bs->bulk_size;
		bs->bulk_end += bs->bulk_size;
	}
}

void	biggest_in_a(t_stack **a, t_stack **b, t_bigsort *bs, t_stack **rev)
{
	int	biggest;

	biggest = bs->ac - 1;
	while (biggest > 0)
	{
		bs->dist_up = 0;
		bs->dist_down = 0;
		reverse_stack(rev, b);
		bs->dist_up = find_biggest(b, biggest);
		bs->dist_down = find_biggest(rev, biggest);
		if (bs->dist_up <= bs->dist_down)
			rotate_push_to_a(a, b, bs->dist_up, 1);
		if (bs->dist_up > bs->dist_down)
			rotate_push_to_a(a, b, bs->dist_down, 0);
		free_stack(rev);
		biggest--;
	}
	push(b, a, "pa");
}

void	big_sort(t_stack **a, t_stack **b, int ac)
{
	t_bigsort	bs;
	t_stack		*rev;

	rev = 0;
	init_bs(&bs, ac);
	push_bulks_in_b(a, b, &bs, &rev);
	biggest_in_a(a, b, &bs, &rev);
}
