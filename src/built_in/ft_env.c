/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:40:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/29 12:00:10 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_minishell *sh, t_cmd *cmd)
{
	int	i;

	(void) cmd;
	i = 0;
	if (get_argc(cmd->argv) > 1)
	{
		ft_dprintf(2, "NavidShell: Syntax Error, too many arguments\n");
		return (2);
	}
	if (!sh->envp)
		return (EXIT_SUCCESS);
	while (sh->envp && sh->envp[i])
	{
		printf("%s\n", sh->envp[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
