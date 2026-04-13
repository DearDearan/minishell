/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:23:08 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/13 11:59:27 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var(char **envp, char *var)
{
	int		i;
	int		size;
	char	*equal;

	equal = ft_strjoin(var, "=");
	if (!equal || !envp || !*envp)
		return (NULL);
	i = 0;
	size = ft_strlen(equal);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], equal, size) == 0)
		{
			free(equal);
			return (envp[i] + size);
		}
		i++;
	}
	free(equal);
	return (NULL);
}

char	*get_var_name(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 1;
	j = 0;
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
		i++;
	ret = ft_calloc(i + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 1;
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
	{
		ret[j] = str[i];
		j++;
		i++;
	}		
	return (ret);
}
