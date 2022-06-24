/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsibesson <tamsibesson@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:20:38 by tamsibesson       #+#    #+#             */
/*   Updated: 2022/06/23 10:45:17 by tamsibesson      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->pos;
	mid = (*a)->n->pos;
	bot = (*a)->n->n->pos;
	if (top > mid && top < bot && mid < bot)
		swap(a, "sa");
	else if (top > mid && top > bot && mid > bot)
	{
		swap(a, "sa");
		reverse_rotate(a, "rra");
	}
	else if (top < mid && top < bot && mid > bot)
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
	else if (top > mid && top > bot && mid < bot)
		rotate(a, "ra");
	else if (top < mid && top > bot && mid > bot)
		reverse_rotate(a, "rra");
}

int	is_sorted_reverse(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*iter;

	tmp = *a;
	if (*a != NULL && *b == NULL)
	{
		tmp = *a;
		while (tmp != NULL)
		{
			iter = tmp->n;
			while (iter != NULL)
			{
				if (iter->v > tmp->v)
					return (0);
				iter = iter->n;
			}
			tmp = tmp->n;
		}
		return (1);
	}
	return (0);
}

void	handle_exception(t_stack **a, t_stack **b, int ac)
{
	int	tab[5];
	int	i;

	i = 0;
	tab[0] = (*a)->pos;
	tab[1] = (*a)->n->pos;
	tab[2] = (*a)->n->n->pos;
	tab[3] = (*a)->n->n->n->pos;
	if ((tab[0] < tab[1] && tab[0] < tab[2] && tab[0] > tab[3] \
	&& tab[0] > tab[4] && tab[1] > tab[2] && tab[1] > tab[3] \
	&& tab[1] > tab[4] && tab[2] > tab[3] && tab[2] > tab[4] \
	&& tab[3] > tab[4]) || is_sorted_reverse(a, b))
	{
		reverse_rotate(a, "rra");
		push(a, b, "pb");
		reverse_rotate(a, "rra");
		push(a, b, "pb");
		sort_three(a);
		push(b, a, "pa");
		push(b, a, "pa");
	}
}

void	sort_four_five(t_stack **a, t_stack **b, int ac)
{
	int	min_in_stack;
	int	push_limit;

	push_limit = 2;
	if (ac == 4)
		push_limit = 1;
	min_in_stack = 0;
	if (ac == 5)
		handle_exception(a, b, ac);
	while (min_in_stack < push_limit)
	{
		while ((*a)->pos != min_in_stack)
			rotate(a, "ra");
		if (is_sorted(a, b))
			return ;
		if ((*a)->pos == min_in_stack)
		{
			push(a, b, "pb");
			min_in_stack++;
		}
	}
	sort_three(a);
	push(b, a, "pa");
	if (push_limit == 2)
		push(b, a, "pa");
}

void	sort_stacks(t_stack **a, t_stack **b, int ac)
{
	if (ac == 2)
		if ((*a)->v > (*a)->n->v)
			swap(a, "sa");
	if (ac == 3)
		sort_three(a);
	if (ac == 4 || ac == 5)
		sort_four_five(a, b, ac);
	if (ac > 5)
		big_sort(a, b, ac);
}
