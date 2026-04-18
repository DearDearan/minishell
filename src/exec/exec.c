/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:54:27 by Camille           #+#    #+#             */
/*   Updated: 2026/04/18 15:46:57 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**extract_env_path(t_minishell *sh, char **envp);
static void	exec_cmds(t_minishell *sh, int nb_cmds, char **env_path);
static char	*get_executable_path(char *bin, char **env_path);
static char	*get_path_in_env(char *bin, char**paths);

int	exec(t_minishell *sh, int nb_cmds)
{
	char	**env_path;
	int		wstatus;

	env_path = extract_env_path(sh, sh->envp);
	if (nb_cmds == 1 && set_built_in(sh->cmds[0], sh->cmds[0]->argv[0]))
		sh->exit_c = sh->cmds[0]->built_in(sh, sh->cmds[0]);
	else
	{
		exec_cmds(sh, nb_cmds, env_path);
		wait_children(sh->cmds, sh->nb_cmds, &wstatus);
		sh->exit_c = get_exit_code(sh->cmds[nb_cmds - 1]->pid, wstatus);
	}
	cleaning_for_next_prompt(sh, nb_cmds);
	return (sh->exit_c);
}

static char	**extract_env_path(t_minishell *sh, char **envp)
{
	int		i;
	char	*env_path;
	char	**splitted_env_path;

	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp)
		return (NULL);
	if (!envp[i])
		env_path = ft_strdup("");
	else
		env_path = ft_strdup(envp[i] + 5);
	if (!env_path)
		error_exit(sh, sh->nb_cmds);
	splitted_env_path = ft_split(env_path, ':');
	free(env_path);
	if (!splitted_env_path)
		error_exit(sh, sh->nb_cmds);
	return (splitted_env_path);
}

static void	exec_cmds(t_minishell *sh, int nb_cmds, char **env_path)
{
	int		i;
	int		next;

	i = 0;
	next = 1;
	while (i < nb_cmds)
	{
		if (set_redirections(sh, sh->cmds[i], sh->ios[i]))
		{
			if (!set_built_in(sh->cmds[i], sh->cmds[i]->argv[0]))
			{
				sh->cmds[i]->path = get_executable_path(sh->cmds[i]->argv[0], env_path);
				if (!sh->cmds[i]->path)
					error_exit(sh, nb_cmds);
			}
			if (next != nb_cmds)
				set_pipe(sh, &sh->cmds[i]->fds[1], &sh->cmds[next]->fds[0]);
			make_child(sh, sh->cmds[i]);
		}
		close_fds(&sh->cmds[i]->fds);
		i++;
		next++;
	}
}

static char	*get_executable_path(char *bin, char **env_path)
{
	char	*path;

	if (ft_strchr(bin, '/') || (bin[0] && !*env_path))
		path = ft_strdup(bin);
	else if (!*env_path)
		path = ft_strdup("");
	else
		path = get_path_in_env(bin, env_path);
	return (path);
}

static char	*get_path_in_env(char *bin, char**env_path)
{
	int		i;
	char	*path;
	char	*prepath;

	i = 0;
	while (env_path[i])
	{
		prepath = ft_strjoin(env_path[i], "/");
		if (!prepath)
			return (NULL);
		path = ft_strjoin(prepath, bin);
		free(prepath);
		if (!path)
			return (NULL);
		if (!access(path, F_OK))
			return (path);
		free(path);
		path = NULL;
		i++;
	}
	path = ft_strdup("");
	return (path);
}
