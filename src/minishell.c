/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:24:39 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/03 18:11:54 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

 char	*get_pwd(void)
{
	char	*path;

	path = getenv("PWD");
	return (path);
}

int	main(void)
{
	// char	*line;
	char	*prompt;
	t_bushell	*shell;
	char		*line;
	size_t i = 0;
	size_t j = 0;
	
	prompt = ft_strjoin("Bush_Shell:", get_pwd());
	prompt = ft_strjoin(prompt, "$ ");
	while (1)
	{
		line = readline(prompt);
		add_history(line);
	 	shell = parse(line);
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
			printf("Outfile = %s\n", shell->io[i - 1]->outfile);
			printf("Infile = %s\n", shell->io[i - 1]->infile);
			printf("is_lim = %d\n", shell->io[i - 1] ->is_lim);
			printf("outflags = %i\n", shell->io[i - 1] ->outfile_flags);
		}
	}
}
