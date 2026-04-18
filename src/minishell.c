/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:24:39 by lifranco          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2026/04/18 15:36:00 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/04/17 11:46:12 by lifranco         ###   ########.fr       */
>>>>>>> b118b2e (feat: linking parsing & execution & fixing some bugs)
=======
/*   Updated: 2026/04/17 15:49:22 by lifranco         ###   ########.fr       */
>>>>>>> a8dd686 (	modified:   Makefile)
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell *init_sh(char **envp)
{
	t_minishell	*shell;

	shell = ft_calloc(1, sizeof(t_minishell));
	if (!shell)
		error_exit(shell, 0);
	if (!shell->envp)
		get_envp(envp, shell);
	return (shell);
}


 char	*get_pwd(void)
{
	char	*path;

	path = getenv("PWD");
	return (path);
}

int	main(int argc, char **argv, char **envp)
{
	(void)		argc;
	(void)		argv;
	char		*prompt;
	t_minishell	shell;
	char		*line;
	
	shell = *init_sh(envp);
	prompt = ft_strjoin("Bush_Shell:", get_pwd());
	prompt = ft_strjoin(prompt, "$ ");
	while (1)
	{
		line = readline(prompt);
		if (!line)
			continue ;
		if (line[0] != '\0')
		{
			add_history(line);
			parse(line, &shell);
			exec(&shell, shell.nb_cmds);
		}
		free(line);
	}
	rl_clear_history();
}
