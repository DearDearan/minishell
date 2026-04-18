/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:09:31 by Camille           #+#    #+#             */
/*   Updated: 2026/04/17 16:09:38 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	set_built_in(t_cmd *cmd, char *bin)
{
	int	size;

	size = ft_strlen(bin);
	if (!size)
		return (false);
	//else if (size == 4 && !ft_strncmp(bin, "echo", size))
		//set pointeur de fonction
	//else if (size == 2 && !ft_strncmp(bin, "cd", size))
		//set pointeur de fonction
	//else if (size == 3 && !ft_strncmp(bin, "pwd", size))
		//set pointeur de fonction
	//else if (size == 6 && !ft_strncmp(bin, "export", size))
		//set pointeur de fonction
	//else if (size == 5 && !ft_strncmp(bin, "unset", size))
		//set pointeur de fonction
	//else if (size == 3 && !ft_strncmp(bin, "env", size))
		//set pointeur de fonction
	//else if (size == 4 && !ft_strncmp(bin, "exit", size))
		//set pointeur de fonction
	else if (size == 4 && !ft_strncmp(bin, "TEST", size))
		cmd->built_in = test;//TODO:a delete + tard
	else
		return (false);
	return (true);
}

int	test(t_minishell *sh, t_cmd *cmd)//TODO:a delete + tard
{
	(void)cmd;
	printf("TEST built-in\n");
	if (sh->nb_cmds != 1)
		exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
