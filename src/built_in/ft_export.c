/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:40:57 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/29 15:50:48 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_varname(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
		i++;
	ret = ft_calloc(i + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	return (ret);
}

static bool	is_correct_varname(char *var)
{
	int	i;

	i = 0;
	if ((ft_isdigit(var[0]) || !ft_isalpha(var[0]))
		&& var[0] != '_')
		return (false);
	while(var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_'
			&& var[i] != '\'' && var[i] != '\"')
			return (false);
		i++;
	}
	if (var[i] != '=')
		return (false);
	return (true);
}

int	ft_export(t_minishell *sh, t_cmd *cmd)
{
	int		i;
	char	*var;
	char	*trim;

	if (sh->nb_cmds > 1)
		return (EXIT_SUCCESS);
	i = 1;
	while (cmd->argv[i])
	{
		trim = trim_quotes(cmd->argv[i]);
		var = get_varname(trim);
		if (is_correct_varname(trim) == false)
		{
			ft_dprintf(2, "export: Error. Invalid variable name\n");
			free(var);
			free(trim);
			return (2);
		}
		free(var);
		free(trim);
		ft_set_env(cmd->argv[i], sh);
		i++;
	}
	return (EXIT_SUCCESS);
}
