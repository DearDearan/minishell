/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:15:08 by Camille           #+#    #+#             */
/*   Updated: 2026/04/28 16:03:45 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

extern int	g_signal;

void	set_signals(bool heredoc);
void	reset_signals(void);
void	sigint_for_interactive_mode(int signum);
void	sigint_for_heredoc(int signum);

#endif
