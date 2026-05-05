/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:13:15 by Camille           #+#    #+#             */
/*   Updated: 2026/05/04 16:08:52 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

static void	handle_sigint(int signum);

void	set_signals(void)
{
	struct sigaction	sa;

	if (sigemptyset(&sa.sa_mask) == -1)
		exit(EXIT_FAILURE);
	sa.sa_flags = 0;
	sa.sa_handler = handle_sigint;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

static void	handle_sigint(int signum)
{
	g_signal = signum;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
