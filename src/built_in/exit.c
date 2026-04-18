/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:54:50 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/17 17:02:36 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_args(char **args)
{
	int	i;

	while (args && args[i])
		i++;
	return (i);
}

int ft_exit(t_minishell *shell, t_cmd *cmd)
{
	int	exit_c;

	(void) shell;
	(void) cmd;
	if (count_args(args) > 2)
	{
		ft_dprintf(2, "Syntax Error: more than 1 arguments.\n");
		return (-1);
	}
	else if (count_args == 1)
		exit(0);
	else
		exit_c = ft_atoi(args[1]);
	if (exit_c < 0 || exit_c > 255)
		exit(0);
	exit(exit_c);
}
