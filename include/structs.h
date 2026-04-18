/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:25:25 by lifranco          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2026/04/17 17:54:49 by Camille          ###   ########.fr       */
=======
/*   Updated: 2026/04/16 19:23:08 by Camille          ###   ########.fr       */
>>>>>>> b118b2e (feat: linking parsing & execution & fixing some bugs)
=======
/*   Updated: 2026/04/17 17:11:57 by lifranco         ###   ########.fr       */
>>>>>>> a8dd686 (	modified:   Makefile)
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
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_minishell
{
<<<<<<< HEAD
	int				exit_c;
	char			**envp;
	size_t			nb_cmds;
	struct s_cmd	**cmds;
	struct s_io		**ios;
=======
	int		exit_c;
	char	**envp;
	size_t	nb_cmds;
	struct s_cmd	**cmds;
	struct s_io	**ios;
>>>>>>> a8dd686 (	modified:   Makefile)
}	t_minishell;

typedef struct s_cmd
{
	char	*path;
	char	**argv;
	int		fds[2];
	pid_t	pid;
<<<<<<< HEAD
<<<<<<< HEAD
	int		(*built_in)(struct s_minishell *, struct s_cmd *);
=======
	int		exit_code;//TODO:a supprimer, plus besoin anymore
>>>>>>> b118b2e (feat: linking parsing & execution & fixing some bugs)
=======
	int		(*built_in)(t_minishell *, struct s_cmd *);
	
>>>>>>> a8dd686 (	modified:   Makefile)
} t_cmd;

typedef struct s_io
{
	char		*infile;
	char		*outfile;
	bool		is_lim;
	int			outfile_flags;
	struct s_io	*next;
}	t_io;

<<<<<<< HEAD
=======

>>>>>>> a8dd686 (	modified:   Makefile)

<<<<<<< HEAD
=======

>>>>>>> b118b2e (feat: linking parsing & execution & fixing some bugs)
#endif
