/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:25:21 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/18 15:22:04 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSING_H
# define PARSING_H 
# include "structs.h"

/* LEXER_C */
t_lexer *lex(char *argv);
/* SPLIT_QUOTES_C*/
char	**ft_split_outquote(char const *s, char c);
/* FT_LEXLAST_C */
t_lexer	*ft_lexlast(t_lexer *lst);
/* TRIM_QUOTES_C */
char	*trim_quotes(char *str);
/* GET_VAR_C */
char	*get_var(char **envp, char *var);
char	*get_var_name(char *str);
int		get_size(char *str, t_minishell *shell, int i);
/* EXPAND_C */
char	*expand(char *str, t_minishell *shell);
/* IS_IN_SQ_C*/
bool	is_in_sq(char *str, int pos);
/* PARSING_C */
void	parse(char *line, t_minishell *parsing);
/* PROCESS_C */
t_lexer	*fill_cmds_words(t_minishell *parse, t_lexer *lex, int cmd_i);
t_lexer *process_io(t_minishell *parse, t_lexer *lex, int cmd_i);
char	*process_word(char *content, t_minishell *parse);

#endif
