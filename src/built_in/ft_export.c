/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:40:57 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/01 17:07:34 by lifranco         ###   ########.fr       */
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
	return (true);
}

static int	check_for_args(t_minishell *sh, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->argv[0] && !cmd->argv[1])
	{
		while (sh->envp[i])
		{
			printf("declare -x %s\n", sh->envp[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_export(t_minishell *sh, t_cmd *cmd)
{
	int		i;
	char	*var;
	char	*trim;
	bool	error;

	error = false;
	if (sh->nb_cmds > 1 || check_for_args(sh, cmd))
		return (EXIT_SUCCESS);
	i = 0;
	while (cmd->argv[++i])
	{
		trim = trim_quotes(cmd->argv[i]);
		var = get_varname(trim);
		if (is_correct_varname(trim) == false)
		{
			ft_dprintf(2, "export: Error. \"%s\"'s not a valid ID.\n", trim);
			error = true;
		}
		else
			ft_set_env(cmd->argv[i], sh);
		free(var);
		free(trim);
	}
	return ((int)error);
}
