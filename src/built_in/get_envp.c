/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:44:05 by lifranco          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2026/04/16 17:35:20 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/04/16 13:23:30 by lifranco         ###   ########.fr       */
>>>>>>> 3650a83731399c22c14a46ae13621ed809345e30
=======
/*   Updated: 2026/04/16 18:34:15 by lifranco         ###   ########.fr       */
>>>>>>> 8f51444 (	modified:   src/built_in/ft_pwd.c)
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_tab_size(char **str)
{
	int	i;

	if (!str || !*str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	get_envp(char **envp, t_minishell *shell)
{
	int	i;
	char **env;

	i = 0;
	env = ft_calloc(sizeof(char *), get_tab_size(envp) + 1);
	if (!env || !*env)
		error_exit(shell, shell->nb_cmds);
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		if (!env[i])
			error_exit(shell, shell->nb_cmds);
		i++;
	}
	env[i] = NULL;
	shell->envp = env;
}


