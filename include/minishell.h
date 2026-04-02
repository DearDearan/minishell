/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:12:57 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/02 11:14:52 by lifranco         ###   ########.fr       */
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
# include "ft_list.h"

typedef struct s_bushell
{
	int			exit_c;
	char		**envp;
	t_cmd		*cmd;
	struct s_io	*io;
}	t_bushell;

typedef struct s_io
{
	char	*infile;
	char	*outfile;
	char	*limiter;
	int		outfile_flags;

}	t_io;

static int	g_signal;

/* FT_FREEALL_C */
void	ft_freeall(char **strs);


#endif