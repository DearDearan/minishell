/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:24:31 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/01 15:59:51 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include <unistd.h>

typedef struct s_cmd
{
	char			*path;
	char			**argv;
	int				fds[2];
	pid_t			pid;
	struct t_cmd	*next;
} t_cmd;

#endif