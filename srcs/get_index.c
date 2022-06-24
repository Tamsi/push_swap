/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsibesson <tamsibesson@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:14:51 by tamsibesson       #+#    #+#             */
/*   Updated: 2022/06/23 09:35:10 by tamsibesson      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	*create_sorted_tab(char **av, int ac)
{
	int	*tab;
	int	i;
	int	j;

	i = 0;
	j = -1;
	tab = (int *)malloc(sizeof(int) * ac);
	if (!tab)
		return (0);
	while (av[++i])
		tab[++j] = ft_atoi(av[i]);
	sort_int_tab(tab, ac);
	return (tab);
}

void	update_stack_index(t_stack **a, char **av, int ac)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	tab = create_sorted_tab(av, ac);
	while (tmp && i < ac)
	{
		i = 0;
		while (tab[i] != tmp->v)
			i++;
		if (tab[i] == tmp->v)
			tmp->pos = i;
		tmp = tmp->n;
	}
	free(tab);
}
