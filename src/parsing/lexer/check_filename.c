/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:06:45 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/04 17:27:58 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_filename(char *str)
{
	int	i;

	i = 0;
	if (is_redir(str[i]) || is_pipes(str[i]))
	{
		ft_dprintf(2, "Syntax Error : %s is an invalid token\n", str);
		return (0);
	}
	return (1);
}
