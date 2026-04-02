/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:12:57 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/02 16:24:01 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "command.h"
# include "parsing.h"
# include "ft_stdio.h"
# include "ft_stdlib.h"
# include "ft_string.h"
# include "strutils.h"
# include "ft_list.h"


typedef struct s_io
{
	char	*infile;
	char	*outfile;
	char	*limiter;
	int		outfile_flags;
	struct s_io		*io;
}	t_io;

typedef struct s_bushshell
{
	int		exit_c;
	char	**envp;
	size_t	nb_cmds;
	t_cmd	**cmds;
	t_io	*io;
}	t_bushell;

static int	g_signal;

/* FT_FREEALL_C */
void	ft_freeall(char **strs);


#endif