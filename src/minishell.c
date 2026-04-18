/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:24:39 by lifranco          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/18 15:36:00 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/04/17 11:46:12 by lifranco         ###   ########.fr       */
>>>>>>> b118b2e (feat: linking parsing & execution & fixing some bugs)
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

 char	*get_pwd(void)
{
	char	*path;

	path = getenv("PWD");
	return (path);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void)	argv;
	char	*prompt;
	t_minishell *shell;
	char		*line;
	size_t i = 0;
	size_t j = 0;
	t_io *curr;
	
	prompt = ft_strjoin("Bush_Shell:", get_pwd());
	prompt = ft_strjoin(prompt, "$ ");
	while (1)
	{
		line = readline(prompt);
		if (!line)
			continue ;
		if (line[0] != '\0')
			add_history(line);
		shell = parse(line, envp);
		if (!shell)
			continue ;
		shell->envp = envp;
		i = 0;
		while (i < shell->nb_cmds)
		{
			j = 0;
			printf("------------------------\n");
			while (shell->cmds[i]->argv[j])
			{
				printf("Commande = %s\n", shell->cmds[i]->argv[j]);
				j++;
			}
			i++;
			curr = shell->ios[i - 1];
			while (curr)
			{
				printf("Outfile = %s\n", curr->outfile);
				printf("Infile = %s\n", curr->infile);
				printf("is_lim = %d\n", curr->is_lim);
				printf("outflags = %i\n", curr->outfile_flags);
				curr = curr->next;
			}
		}
		exec(shell, shell->nb_cmds);
		free(line);
	}
}
