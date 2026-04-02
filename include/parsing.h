/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:25:21 by lifranco          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/02 16:52:06 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/03/31 16:18:20 by lifranco         ###   ########.fr       */
>>>>>>> 8851e7e (Fix merge conflict in parsing.h)
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSING_H
# define PARSING_H 


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

/* LEXER_C */
t_lexer *lex(char *argv);
/* SPLIT_QUOTES_C*/
char	**ft_split_outquote(char const *s, char c);
/* FT_LEXLAST_C */
t_lexer	*ft_lexlast(t_lexer *lst);

#endif
