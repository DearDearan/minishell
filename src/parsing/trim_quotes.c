/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:34:46 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/07 12:15:23 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_trim(char *str, char *trim, bool is_dq, bool is_sq)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] == '\"' && !is_dq && !is_sq)
			is_dq = true;
		else if (str[i] == '\"' && is_dq && !is_sq)
			is_dq = false;
		else if (str[i] == '\'' && !is_sq && !is_dq)
			is_sq = true;
		else if (str[i] == '\'' && !is_dq && is_sq)
			is_sq = false;
		else
		{
			trim[j] = str[i];
			j++;
		}
		i++;
	}
}


char	*trim_quotes(char *str)
{
	bool	is_sq;
	bool	is_dq;
	char	*trim;

	is_dq = false;
	is_sq = false;
	trim = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	fill_trim(str, trim, is_dq, is_sq);
	return (trim);
}
