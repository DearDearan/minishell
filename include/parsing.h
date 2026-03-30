/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:25:21 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/30 16:39:36 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSING_H
# define PARSING_H 
# include "minishell.h"

enum redirect
{
	RED_IN,
	RED_OUT,
	RED_LIM,
	RED_APP
};

typedef struct s_cmd
{
	char	**cmd;
	int		red_type;
	char	*filename;

	struct s_cmd	*next;
}	t_cmd;

#endif