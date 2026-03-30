/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:25:21 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/31 16:17:00 by lifranco         ###   ########.fr       */
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

}	t_lexer;

#endif