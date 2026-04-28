/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:29:02 by Camille           #+#    #+#             */
/*   Updated: 2026/04/25 16:51:06 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_getenv(const char *name, const char **envp)
{
	int	size;
	int	i;

	if (!name || !envp)
		return (NULL);
	size = ft_strlen(name);
	i = 0;
	while(envp[i])
	{
		if (!ft_strncmp(envp[i], name, size))
		{
			if (envp[i][size] == '=')
				return ((char *)(envp[i] + size + 1));
		}
		i++;
	}
	return (NULL);
}
