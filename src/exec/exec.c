/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:54:27 by Camille           #+#    #+#             */
/*   Updated: 2026/04/10 16:55:24 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"

static char	**extract_env_path(t_minishell *sh, char **envp);
static char	*get_executable_path(char *bin, char **env_path);
static char	*get_path_in_env(char *bin, char**paths);

int	exec(t_minishell *sh, int nb_cmds)
{
	int		i;
	int		next;
	char	**env_path;

	i = 0;
	next = 1;
	env_path = extract_env_path(sh, sh->envp);
	while (i < nb_cmds)
	{
		sh->exit_c = EXIT_FAILURE;
		if (set_redirections(sh, sh->cmds[i], sh->ios[i]))
		{
			sh->cmds[i]->path = get_executable_path(sh->cmds[i]->argv[0], env_path);
			if (!sh->cmds[i]->path)
				error_exit(sh, nb_cmds);
			if (next != nb_cmds)
				set_pipe(sh, &sh->cmds[i]->fds[1], &sh->cmds[next]->fds[0]);
			//sh->exit_c = make_child(sh->cmds[i]);TODO: make child func et retourner exit code
		}
		close_fds(&sh->cmds[i]->fds);//INFO:a verif plus tard si faut tout liberer ou pas
		i++;
		next++;
	}
	cleaning(sh, nb_cmds);
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
