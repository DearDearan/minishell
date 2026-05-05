/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:07:53 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/04 17:27:31 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	strcount(const char *str, char c)
{
	size_t	i;
	size_t	count;
	bool	is_sq;
	bool	is_dq;

	i = 0;
	count = 0;
	is_sq = false;
	is_dq = false;
	while (str[i])
	{
		if (str[i] == '\'' && !is_dq)
			is_sq = !is_sq;
		else if (str[i] == '"' && !is_sq)
			is_dq = !is_dq;
		else if (str[i] == c && !is_sq && !is_dq)
			count++;
		i++;
	}
	return (count + 1);
}

static size_t	to_next_c(const char *str, char c)
{
	size_t	i;
	bool	is_sq;
	bool	is_dq;

	is_dq = false;
	is_sq = false;
	i = 0;
	while (str[i] && (str[i] != c || is_sq || is_dq))
	{
		if (str[i] == '\'' && !is_dq)
			is_sq = !is_sq;
		else if (str[i] == '\"' && !is_sq)
			is_dq = !is_dq;
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
