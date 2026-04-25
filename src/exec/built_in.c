/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:09:31 by Camille           #+#    #+#             */
/*   Updated: 2026/04/25 17:53:51 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	set_built_in(t_cmd *cmd, char *bin)
{
	int	size;

	size = ft_strlen(bin);
	if (!size)
		return (false);
	else if (size == 4 && !ft_strncmp(bin, "echo", size))
		cmd->built_in = ft_echo;
	//else if (size == 2 && !ft_strncmp(bin, "cd", size))//TODO: utiliser chdir
		//set pointeur de fonction
	else if (size == 3 && !ft_strncmp(bin, "pwd", size))
		cmd->built_in = ft_pwd;
	//else if (size == 6 && !ft_strncmp(bin, "export", size))
		//set pointeur de fonction
	else if (size == 5 && !ft_strncmp(bin, "unset", size))
		cmd->built_in = ft_unset;
	else if (size == 3 && !ft_strncmp(bin, "env", size))
		cmd->built_in = ft_env;
	else if (size == 4 && !ft_strncmp(bin, "exit", size))
		cmd->built_in = ft_exit;
	else
		return (false);
	return (true);
}
