/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:05:26 by Camille           #+#    #+#             */
/*   Updated: 2026/04/07 17:08:35 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipe(t_cmd *current, t_cmd *next)
{
	int	fds;

	if (pipe(fds) == -1)
		exit(EXIT_FAILURE);//TODO: error clean exit
}
