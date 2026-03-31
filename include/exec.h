/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:31:30 by Camille           #+#    #+#             */
/*   Updated: 2026/04/02 12:05:57 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define WARN_EOF \
	"minishell: warning: here-document delimited by end-of-file (wanted '%s')"

# include "minishell.h"

//exec.c
int	exec(t_minishell *sh, int nb_cmds);

// redirections.c
void	set_redirections(t_cmd *cmd, t_io *io);

// pipes.c
void	set_pipe(t_cmd *current, t_cmd *next);

#endif
