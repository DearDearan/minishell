/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:24:39 by lifranco          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/27 14:29:04 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/04/27 11:55:03 by lifranco         ###   ########.fr       */
>>>>>>> 688682a6841fbb33498369043a8c18f88a50d5a1
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*init_prompt(void)
{
	char 	*prompt;
	char	*cwd;
	char	*tmp;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	tmp = ft_strjoin("NavidShell:", cwd);
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
	if (!shell->envp)
		get_envp(envp, shell);
	return (shell);
}
static int	read_exec(t_minishell *shell)
{
	char		*line;

	line = readline(shell->prompt);
	if (!line)
	{
		printf("exit\n");
		return (1);
	}
	if (line[0] != '\0')
	{
		if (check_for_specials(line))
		{
			add_history(line);
			free(line);
			return (0);
		}
		add_history(line);
		parse(line, shell);
		exec(shell, shell->nb_cmds);
	}
	free(line);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*shell;
<<<<<<< HEAD
=======
	char		*line;
>>>>>>> 688682a6841fbb33498369043a8c18f88a50d5a1
	
	(void)		argc;
	(void)		argv;
	shell = init_sh(envp);
	if (!shell)
		error_exit(NULL, 0);
	while (1)
	{
		shell->prompt = init_prompt();
		if (read_exec(shell))
			break ;
<<<<<<< HEAD
=======
		}
		if (line[0] != '\0' && !check_for_specials(line))
		{
			add_history(line);
			parse(line, shell);
			exec(shell, shell->nb_cmds);
		}
		free(line);
>>>>>>> 688682a6841fbb33498369043a8c18f88a50d5a1
	}
	cleaning(shell, 0);
	rl_clear_history();
	exit(EXIT_SUCCESS);
}
