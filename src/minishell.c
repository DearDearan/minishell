/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:24:39 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/22 11:38:51 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_pwd(void)
{
	char	*path;

	path = getenv("PWD");
	return (path);
}

static char	*init_prompt(void)
{
	char 	*prompt;
	char	*tmp;

	tmp = ft_strjoin("NavidShell:", get_pwd());
	prompt = ft_strjoin(tmp, "$ ");
	free(tmp);
	return (prompt);
}

static t_minishell *init_sh(char **envp)
{
	t_minishell	*shell;

	shell = ft_calloc(1, sizeof(t_minishell));
	if (!shell)
		error_exit(shell, 0);
	if (!shell->envp)
		get_envp(envp, shell);
	if (!shell->prompt)
		shell->prompt = init_prompt();
	return (shell);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*shell;
	char		*line;

	(void)		argc;
	(void)		argv;
	shell = init_sh(envp);
	while (1)
	{
		line = readline(shell->prompt);
		if (!line)
			continue ;
		if (line[0] != '\0')
		{
			add_history(line);
			parse(line, shell);
			exec(shell, shell->nb_cmds);
		}
		free(line);
	}
	free(shell->prompt);
	cleaning(shell, shell->nb_cmds);
	rl_clear_history();
}
