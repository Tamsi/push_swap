/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsibesson <tamsibesson@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:32:46 by tamsibesson       #+#    #+#             */
/*   Updated: 2022/06/23 09:36:03 by tamsibesson      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*newnode(int v, int pos)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->v = v;
	new->pos = pos;
	new->n = NULL;
	return (new);
}

void	add_back(t_stack **s, t_stack *new)
{
	t_stack	*last;

	if (s == NULL)
		return ;
	last = *s;
	if (*s == NULL)
		*s = new;
	else
	{
		while (last->n)
			last = last->n;
		last->n = new;
		new->n = NULL;
	}
}

void	add_front(t_stack **s, t_stack *new)
{
	if (new && s)
	{
		new->n = *s;
		*s = new;
	}
}

t_stack	*getlast(t_stack *s)
{
	if (s == NULL)
		return (0);
	while (s->n)
		s = s->n;
	return (s);
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*copy;

	if (!s)
		return ;
	copy = *s;
	while (copy)
	{
		tmp = copy->n;
		free(copy);
		copy = tmp;
	}
	*s = NULL;
}
