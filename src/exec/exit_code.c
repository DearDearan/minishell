/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:15:36 by Camille           #+#    #+#             */
/*   Updated: 2026/04/27 14:27:25 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_exit_code(bool io_invalid, t_cmd *cmd, int wstatus)
{
	if (io_invalid)
		return (EXIT_FAILURE);
	if (!cmd->argv)
		return (EXIT_SUCCESS);
	if (cmd->pid == -1)
		return (EXIT_FAILURE);
	return (parse_wait_status(wstatus));
}

int	parse_wait_status(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus))
		return (WTERMSIG(wstatus) + 128);
	else if (WIFSTOPPED(wstatus))
		return (WSTOPSIG(wstatus) + 128);
	return (EXIT_FAILURE);
}
