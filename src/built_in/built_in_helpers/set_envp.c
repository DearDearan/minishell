/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:16:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/27 13:54:17 by lifranco         ###   ########.fr       */
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

static void	put_into_env(char *var, char **envp, t_minishell *shell)
{
	int	i;
	char **env;

	i = 0;
	env = ft_calloc(sizeof(char *), get_tab_size(envp) + 2);
	if (!env || !*env)
		error_exit(shell, shell->nb_cmds);
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		if (!env[i])
			error_exit(shell, shell->nb_cmds);
		i++;
	}
	env[i] = ft_strdup(var);
	env[i + 1] = NULL;
	if (!env)
		error_exit(shell, shell->nb_cmds);
	ft_free_strs(shell->envp);
	shell->envp = env;
}

void	ft_set_envp(char *var, t_minishell *sh)
{
	int		i;
	char	*equal;
	char	name;
	int		j;

	i = 0;
	j = 0;
	name = get_var_name(var, sh);
	equal = ft_strjoin(name, "=");
	free(name);
	while (sh->envp && sh->envp[i])
	{
		if (!ft_strncmp(equal, sh->envp[i], ft_strlen(equal)))
		{
			free(sh->envp[i]);
			sh->envp[i] = ft_strdup(var);
			if (!sh->envp[i])
				error_exit(sh, sh->nb_cmds);
		}
		i++;
	}
	if (!sh->envp[i])
		put_into_env(cmd->argv[1], sh->envp, sh);
	free(equal);
	return (0);
}
