/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:34:46 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/04 17:22:51 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_trim(char *str, char *trim, int i, int j)
{
	bool	in_sq;
	bool	in_dq;

	in_sq = false;
	in_dq = false;
	while (str && str[i])
	{
		if (str[i] == '\'' && !in_dq)
		{
			in_sq = !in_sq;
			i++;
		}
		else if (str[i] == '"' && !in_sq)
		{
			in_dq = !in_dq;
			i++;
		}
		else
		{
			trim[j++] = str[i];
			i++;
		}
	}
}

char	*trim_quotes(char *str)
{
	char	*trim;

	trim = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!trim)
		return (NULL);
	fill_trim(str, trim, 0, 0);
	if ((trim[0] == '\"' || trim[0] == '\'') && ft_strlen(trim) == 1)
	{
		free(trim);
		return ("\0");
	}
	return (trim);
}
