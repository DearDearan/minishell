/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:39:07 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/26 11:43:21 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// let Camille rewrite the function
int	ft_pwd(t_minishell *sh, t_cmd *cmd)
{
	char	*path;
	int		i;

	(void) cmd;
	path = NULL;
	i = 0;
	while(sh->envp && sh->envp[i])
	{
		if (!ft_strncmp(sh->envp[i], "PWD=", 4))
		{
			path = getenv("PWD");
			break ;
		}
		else if (!ft_strncmp(sh->envp[i], "OLDPWD=", 8))
		{
			path = getenv("OLDPWD");
			break ;
		}
		i++;
	}
	if (!path && sh->envp[0])
		path = getenv("PWD");
	printf("%s\n", path);
	return (0);
}
