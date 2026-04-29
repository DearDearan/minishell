/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:24:39 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/29 15:53:14 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *choose_shell_name(int *i)
{
	static char *name[10] = {"NavidShell:", "Bush_Shell:", "NavidShell...?:",
		"Coquillage:", "PearlAbyssShell:", "MyShell.pk3:",
		"Fish:", "\033[0;94mHouse\033[0mShell:", "EauCalmeShell:",
		NULL};
	if (!name[*i])
		*i = 0;
	return (name[*i]);
}

static char	*init_prompt(t_minishell *sh, int *i)
{
	char 	*prompt;
	char	*cwd;
	char	*tmp;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		(void)sh;//TODO: si pas de cwd car rm par ex. faire en sorte de garder le dernier prompt
	tmp = ft_strjoin(choose_shell_name(i), cwd);
	prompt = ft_strjoin(tmp, "$ ");
	free(tmp);
	free(cwd);
	return (prompt);
}

static t_minishell *init_sh(char **envp)
{
	t_minishell	*shell;

	set_signals();
	shell = ft_calloc(1, sizeof(t_minishell));
	if (!shell)
		error_exit(shell, 0);
	if (!shell->envp && envp)
		get_envp(envp, shell);
	else if (!envp)
		shell->envp = NULL;
	shell->first_home_dir_path = getenv("HOME");
	return (shell);
}
static int	read_exec(t_minishell *shell)
{
	char	*line;

	line = readline(shell->prompt);
	if (!line)
	{
		printf("exit\n");
		return (1);
	}
	if (line[0] != '\0')
	{
		if (check_for_specials(line, shell))
		{
			add_history(line);
			free(line);
			return (0);
		}
		add_history(line);
		if (!parse(line, shell))
			exec(shell, shell->nb_cmds);
	}
	if (line[0] == '\0')
		free(shell->prompt);
	shell->prompt = NULL;
	free(line);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*shell;
	int		i;

	i = 0;
	(void)		argc;
	(void)		argv;
	shell = init_sh(envp);
	if (!shell)
		error_exit(NULL, 0);
	while (1)
	{
		shell->prompt = init_prompt(shell, &i);
		i++;
		if (read_exec(shell))
			break ;
	}
	cleaning(shell, 0);
	rl_clear_history();
	exit(EXIT_SUCCESS);
}
