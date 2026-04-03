/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:07:53 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/03 10:51:30 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	strcount(const char *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == c)
			j = 0;
		str++;
	}
	return (i);
}

static size_t	to_next_c(const char *str, char c)
{
	size_t	i;
	char	quote_c;

	i = 0;
	quote_c = '\"';
	while (str[i] && str[i] != c)
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			quote_c = str[i];
			i++;
			while (str[i] && str[i] != quote_c)
				i++;
		}
		i++;
	}
	return (i);
}

static void	freeall(char **strs, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	**fill_tab(char **tab, char const *s, char c)
{
	int	i;
	int	next_char;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			next_char = to_next_c(s, c);
			tab[i] = ft_substr(s, 0, next_char);
			if (!tab[i])
			{
				freeall(tab, i);
				return (NULL);
			}
			i++;
			s += next_char;
		}
		else
			s++;
	}
	return (tab);
}

char	**ft_split_outquote(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = ft_calloc((strcount(s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	tab = fill_tab(tab, s, c);
	return (tab);
}
