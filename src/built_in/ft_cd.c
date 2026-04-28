/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:19:39 by Camille           #+#    #+#             */
/*   Updated: 2026/04/28 17:20:50 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	can_execute_cd(char **argv, const char **envp);
static bool	update_envpwd_and_old(char *oldpwd_path, t_minishell *sh);

int	ft_cd(t_minishell *sh, t_cmd *cmd)
{
	char	*oldpwd_path;

	if (sh->nb_cmds > 1)
		return (EXIT_FAILURE);
	oldpwd_path = getcwd(NULL, 0);
	if (!oldpwd_path)
		error_exit(sh, sh->nb_cmds);
	if (!can_execute_cd(cmd->argv, (const char **)sh->envp))
	{
		free(oldpwd_path);
		return (EXIT_FAILURE);
	}
	if (!update_envpwd_and_old(oldpwd_path, sh))
		error_exit(sh, sh->nb_cmds);
	return (EXIT_SUCCESS);
}

static bool	can_execute_cd(char **argv, const char **envp)
{
	int	argc;

	argc = get_argc(argv);
	if (argc > 2)
	{
		ft_dprintf(2, "minishell: cd: too many arguments\n");
		return (false);
	}
	if (argc == 1)
	{
		if (chdir(ft_getenv("HOME", envp)) == -1)
		{
			perror("minishell");
			return (false);
		}
	}
	else
	{
		if (chdir(argv[1]) == -1)
		{
			perror("minishell");
			return (false);
		}
	}
	return (true);
}

static bool	update_envpwd_and_old(char *oldpwd_path, t_minishell *sh)
{
	char	*pwd_path;
	char	*newpwd_path;

	pwd_path = oldpwd_path;
	oldpwd_path = ft_strjoin("OLDPWD=", oldpwd_path);
	free(pwd_path);
	if (!oldpwd_path)
		return (false);
	ft_set_env(oldpwd_path, sh);
	free(oldpwd_path);
	pwd_path = getcwd(NULL, 0);
	if (!pwd_path)
		return (false);
	newpwd_path = ft_strjoin("PWD=", pwd_path);
	free(pwd_path);
	if (!newpwd_path)
		return (false);
	ft_set_env(newpwd_path, sh);
	free(newpwd_path);
	return (true);
}
