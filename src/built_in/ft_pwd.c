/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:39:07 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/17 11:45:25 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_minishell *sh)
{
	char	*path;
	int		i;

	i = 0;
	if (!sh->envp)
		error_exit(sh, sh->nb_cmds);
	while(sh->envp[i])
	{
		if (!ft_strncmp(sh->envp[i], "PWD=", 4))
		{
			path = getenv("PWD");
			break ;
		}
		else if (!ft_strncmp(sh->envp[i], "OLD_PWD=", 8))
		{
			path = get_env("OLD_PWD");
			break ;
		}
		i++;
	}
	printf("%s\n", path);
}
