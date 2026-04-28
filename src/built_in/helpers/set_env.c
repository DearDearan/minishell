/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:16:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/28 13:25:35 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_varname(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
		i++;
	ret = ft_calloc(i + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
	{
		ret[j] = str[i];
		j++;
		i++;
	}		
	return (ret);
}

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
	if (!env)
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
	if (!env[i])
		error_exit(shell, shell->nb_cmds);
	ft_free_strs(shell->envp);
	shell->envp = env;
}

void	ft_set_env(char *var, t_minishell *sh)
{
	int		i;
	char	*equal;
	char	*name;
	int		j;

	i = 0;
	j = 0;
	name = get_varname(var);
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
			break ;
		}
		i++;
	}
	if (!sh->envp[i])
		put_into_env(var, sh->envp, sh);
	free(equal);
}
