/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:16:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/21 11:40:45 by lifranco         ###   ########.fr       */
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

int	set_envp(t_minishell *sh, t_cmd *cmd)
{
	int		i;
	char	*equal;
	int		j;

	i = 0;
	j = 0;
	equal = ft_strjoin(get_var_name(cmd->argv[1]), "=");
	while (sh->envp && sh->envp[i])
	{
		if (!ft_strncmp(equal, sh->envp[i], ft_strlen(equal)))
		{
			free(sh->envp[i]);
			sh->envp[i] = ft_strdup(cmd->argv[1]);
			if (!sh->envp[i])
				return (2);
		}
		i++;
	}
	if (!sh->envp[i])
		put_into_env(cmd->argv[1], sh->envp, sh);
	free(equal);
	return (0);
}
