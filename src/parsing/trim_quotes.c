/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:34:46 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/14 13:23:02 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	fill_trim(char *str, char *trim)
{
	int		i = 0;
	int		j = 0;
	bool	in_sq;
	bool	in_dq;

	in_sq = false;
	in_dq = false;
	while (str[i])
	{
		if (str[i] == '\'' && !in_dq)
		{
			in_sq = !in_sq;
			i++;
			continue;
		}
		if (str[i] == '"' && !in_sq)
		{
			in_dq = !in_dq;
			i++;
			continue;
		}
		trim[j++] = str[i++];
	}
}

char *trim_quotes(char *str)
{
	char *trim;

	trim = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!trim)
		return (NULL);
	fill_trim(str, trim);
	return (trim);
}
