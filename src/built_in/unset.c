/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:src/built_in/unset.c
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
========
/*   builts_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:13:34 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/18 14:41:06 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTS_IN_H
# define BUILTS_IN_H

/* FT_PWD_C */
int	ft_pwd(t_minishell *sh, t_cmd *cmd);

/* SET_ENVP_C*/
int	set_envp(t_minishell *sh, t_cmd *cmd);
#endif
>>>>>>>> f3ae237aab3bc3e6ccb5c07dd324d2432834e193:include/builts_in.h
