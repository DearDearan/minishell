/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:25:21 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/07 12:15:20 by lifranco         ###   ########.fr       */
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
/* TRIM_QUOTES_C */
char	*trim_quotes(char *str);

#endif
