/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:12:57 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/06 14:08:42 by lifranco         ###   ########.fr       */
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
# include <fcntl.h>

typedef struct s_io
{
	char		*infile;
	char		*outfile;
	bool		is_lim;
	int			outfile_flags;
	struct s_io	*next;
}	t_io;

typedef struct s_bushell
{
	int		exit_c;
	char	**envp;
	size_t	nb_cmds;
	t_cmd	**cmds;
	t_io	**io;
}	t_bushell;

//static int	g_signal;

/* FT_FREEALL_C */
void	ft_freetabs(char **strs);
/* FILL_IO_C */
t_lexer *fill_io(t_bushell *shell, t_lexer *lexed, int i);
/* PARSING_C */
t_bushell *parse(char *line);
/* FILL_IO_C */
t_io	*ft_iolast(t_io *lst);
t_io	*ft_iolast(t_io *lst);

#endif