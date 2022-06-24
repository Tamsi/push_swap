/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsibesson <tamsibesson@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:58:26 by tbesson           #+#    #+#             */
/*   Updated: 2022/06/23 10:26:44 by tamsibesson      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_word_len(char const *str, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] && c == str[i])
		i++;
	while (str[i] && c != str[i])
	{
		i++;
		len++;
	}
	return (len);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (c == str[i] && str[i])
			i++;
		if (c != str[i] && str[i])
		{
			count++;
			while (c != str[i] && str[i])
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	while (i < count_words(s, c))
	{
		j = 0;
		tab[i] = malloc((ft_word_len(&s[k], c) + 1) * sizeof(char));
		while (c == s[k] && s[k])
			k++;
		while (c != s[k] && s[k])
			tab[i][j++] = s[k++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
