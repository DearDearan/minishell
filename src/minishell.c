/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:24:39 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/02 16:44:33 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_pwd(void)
{
	char	*path;

	path = getenv("PWD");
	return (path);
}

int	main(void)
{
	char	*line;
	char	*prompt;
	
	prompt = ft_strjoin("Bush_Shell:", get_pwd());
	prompt = ft_strjoin(prompt, "$ ");
	line = readline(prompt);
	printf("%s\n", line);
	return 0;
}

