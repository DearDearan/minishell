/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:48:36 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/17 14:02:16 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_and_free()
{
	
}


void	unset_env(char **env, char *var)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin(var, "=");
	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(tmp, envp[i], ft_strlen(tmp)))
			free(envp[i]);
		i++;
	}
}