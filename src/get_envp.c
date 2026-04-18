/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:44:05 by lifranco          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/18 15:34:43 by lifranco         ###   ########.fr       */
=======
<<<<<<<< HEAD:src/built_in/get_envp.c
<<<<<<< HEAD
/*   Updated: 2026/04/18 15:37:53 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/04/17 17:08:10 by lifranco         ###   ########.fr       */
>>>>>>> a8dd686 (	modified:   Makefile)
========
/*   Updated: 2026/04/18 14:41:33 by lifranco         ###   ########.fr       */
>>>>>>>> f3ae237 (	modified:   Makefile):src/get_envp.c
>>>>>>> f3ae237 (	modified:   Makefile)
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
	if (!env)
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


