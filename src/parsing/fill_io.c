/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:07:59 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/03 18:19:24 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer *fill_io(t_bushell *shell, t_lexer *lexed, int i)
{
	if (lexed->type == IN && lexed->next != NULL)
	{
		shell->io[i]->infile = lexed->next->content;
		shell->io[i]->is_lim = false;		
	}
	else if (lexed->type == OUT && lexed->next != NULL)
	{
		shell->io[i]->outfile = lexed->next->content;
		shell->io[i]->outfile_flags = O_CREAT | O_TRUNC | O_WRONLY;
	}
	else if (lexed->type == LIM && lexed->next != NULL)
	{
		shell->io[i]->infile = lexed->next->content;
		shell->io[i]->is_lim = true;
	}
	else if (lexed->type == APP && lexed->next != NULL)
	{
		shell->io[i]->outfile = lexed->next->content;
		shell->io[i]->outfile_flags = O_CREAT | O_APPEND | O_WRONLY;
	}
	return (lexed->next);
}

