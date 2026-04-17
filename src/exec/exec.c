/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:54:27 by Camille           #+#    #+#             */
/*   Updated: 2026/04/16 18:33:19 by Camille          ###   ########.fr       */
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
	exec_cmds(sh, nb_cmds, env_path);
	wait_children(sh->cmds, sh->nb_cmds, &wstatus);
	sh->exit_c = get_exit_code(wstatus);
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
	t_cmd	*cmd;

	i = 0;
	next = 1;
	while (i < nb_cmds)
	{
		cmd = sh->cmds[i];
		if (set_redirections(sh, cmd, sh->ios[i]))
		{
			cmd->path = get_executable_path(cmd->argv[0], env_path);
			if (!cmd->path)
				error_exit(sh, nb_cmds);
			if (next != nb_cmds)
				set_pipe(sh, &cmd->fds[1], &sh->cmds[next]->fds[0]);
			make_child(sh, cmd);
		}
		close_fds(&cmd->fds);//INFO:a verif plus tard si faut tout liberer ou pas
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
