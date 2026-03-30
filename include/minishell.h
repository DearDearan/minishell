/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:12:57 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/31 16:16:55 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "command.h"
# include "parsing.h"
# include "ft_stdio.h"
# include "ft_stdlib.h"
# include "ft_string.h"
# include "strutils.h"

typedef struct s_bushell
{
	int		exit_c;
	char	**envp;
	t_cmd	*cmd;
	int		type;
	//	t_pipe		exec;
}	t_bushell;

typedef struct s_fds
{
	char	*fdin;
	char	*fdout;
	char	*limiter;
}	t_fds;

static int	g_signal;


#endif