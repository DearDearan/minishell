/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:22:30 by Camille           #+#    #+#             */
/*   Updated: 2026/04/14 15:24:54 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANING_H
# define CLEANING_H

# include "structs.h"

void	cleaning(t_minishell *sh, int nb_cmds);
void	cleaning_for_next_prompt(t_minishell *sh, int nb_cmds);
void	error_exit(t_minishell *sh, int nb_cmds);

#endif
