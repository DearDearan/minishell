/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:05:26 by Camille           #+#    #+#             */
/*   Updated: 2026/04/07 17:53:14 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"

void	set_pipe(int *curr_cmd_fd_out, int *next_cmd_fd_in)
{
	int	fds[2];

	if (pipe(fds) == -1)
		exit(EXIT_FAILURE);//TODO: error clean exit
	if (*curr_cmd_fd_out == -1)
		*curr_cmd_fd_out = fds[1];
	else
		close_fd(&fds[1]);
	*next_cmd_fd_in = fds[0];
}

void	close_fds(int (*fds)[2])
{
	close_fd(fds[0]);
	close_fd(fds[1]);
}

void	close_fd(int *fd)
{
	if (*fd != -1)
		close(*fd);
	*fd = -1;
}
