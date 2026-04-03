/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:24:31 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/03 17:36:03 by lifranco         ###   ########.fr       */
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
} t_cmd;

#endif