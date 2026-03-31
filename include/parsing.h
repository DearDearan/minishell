/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:25:21 by lifranco          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/31 16:18:20 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/03/31 14:32:22 by lifranco         ###   ########.fr       */
>>>>>>> 205b94e (rename: Renamed the delimiters in the enum to be shorter)
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSING_H
# define PARSING_H 


typedef enum e_type
{
	WORDS,
	FILENAME,
	IN,
	OUT,
	LIM,
	APP
} t_type;

typedef struct s_lexer
{
	char	*content;
	int		type;
	t_lexer	*next;
<<<<<<< HEAD
=======

>>>>>>> 205b94e (rename: Renamed the delimiters in the enum to be shorter)
}	t_lexer;

#endif