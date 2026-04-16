/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:25:25 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/16 19:23:08 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_type
{
	WORDS,
	FILENAME,
	PIPES,
	IN,
	OUT,
	LIM,
	APP
} t_type;

typedef struct s_lexer
{
	char			*content;
	int				type;
	bool			is_sq;
	struct s_lexer	*next;
}	t_lexer;


typedef struct s_cmd
{
	char	*path;
	char	**argv;
	int		fds[2];
	pid_t	pid;
	int		exit_code;//TODO:a supprimer, plus besoin anymore
} t_cmd;

typedef struct s_io
{
	char		*infile;
	char		*outfile;
	bool		is_lim;
	int			outfile_flags;
	struct s_io	*next;
}	t_io;

typedef struct s_minishell
{
	int		exit_c;
	char	**envp;
	size_t	nb_cmds;
	t_cmd	**cmds;
	t_io	**ios;
}	t_minishell;


#endif
