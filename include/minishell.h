/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:12:57 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/13 12:49:28 by lifranco         ###   ########.fr       */
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
# include "ft_ctype.h"
# include <fcntl.h>
# include "structs.h"


//static int	g_signal;

/* FT_FREEALL_C */
void	ft_freetabs(char **strs);
/* FILL_IO_C */
t_lexer *fill_io(t_minishell *shell, t_lexer *lexed, int i);
/* PARSING_C */
t_minishell *parse(char *line, char **envp);
/* FILL_IO_C */
t_io	*ft_iolast(t_io *lst);
t_io	*ft_iolast(t_io *lst);

#endif