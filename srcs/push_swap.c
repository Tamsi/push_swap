/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:03:11 by tamsibesson       #+#    #+#             */
/*   Updated: 2022/06/23 16:38:55 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_argv2(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		if (!ft_atoi(av[i]) && av[i][0] != '0')
			return (0);
		while (av[i][++j])
		{
			if (j == 0 && av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (0);
		}
	}
	return (1);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**split_av_str(char **av)
{
	char	**new_av;
	int		i;

	new_av = ft_split(av[1], ' ');
	i = 0;
	while (new_av[i])
	{
		av[i + 1] = malloc((ft_strlen(new_av[i]) + 1) * sizeof(char));
		ft_strcpy(av[i + 1], new_av[i]);
		free(new_av[i]);
		i++;
	}
	free(new_av);
	av[i + 1] = NULL;
	return (av);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = 0;
	b = 0;
	i = 1;
	if (ac == 2)
	{
		av = split_av_str(av);
		while (av[i])
			i++;
		ac = i;
	}
	if (!check_argv(ac, av) || !check_argv2(av))
		_err();
	fill_a(&a, av);
	if (is_sorted(&a, &b))
	{
		free_stack(&a);
		exit(0);
	}
	update_stack_index(&a, av, ac - 1);
	is_sorted(&a, &b);
	sort_stacks(&a, &b, ac - 1);
	free_stack(&a);
}
