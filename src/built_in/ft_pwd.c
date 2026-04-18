/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:39:07 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/18 12:02:23 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_minishell *sh, t_cmd *cmd)
{
	char	*path;
	int		i;

	(void) cmd;
	path = NULL;
	i = 0;
	if (!sh->envp)
		exit(2);
	while(sh->envp[i])
	{
		if (!ft_strncmp(sh->envp[i], "PWD=", 4))
		{
			path = getenv("PWD");
			break ;
		}
		else if (!ft_strncmp(sh->envp[i], "OLD_PWD=", 8))
		{
			path = getenv("OLD_PWD");
			break ;
		}
		i++;
	}
	printf("%s\n", path);
	return (0);
}
