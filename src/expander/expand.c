/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:55:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/13 10:49:21 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_var_size(char *str, int *i, t_minishell *shell, int *size)
{
	char	*var;
	char	*value;

	var = get_var_name(&str[*i]);
	if (!var)
		return (-1);
	*size -= ft_strlen(var) + 1;
	value = get_var(shell->envp, var);
	if (value)
		*size += ft_strlen(value);
	*i += ft_strlen(var) + 1;
	free(var);
	return (0);
}

static int	get_size(char *str, t_minishell *shell, int i)
{
	char	*var;
	int		size;

	size = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			size -= 2;
			var = ft_itoa(shell->exit_c);
			size += ft_strlen(var);
			free(var);
			i += 2;
		}
		else if (str[i] == '$' && (ft_isalnum(str[i + 1]) == 1
			|| str[i + 1] == '_'))
			{
				if (handle_var_size(str, &i, shell, &size) == -1)
					return (-1);
			}
		else
			i++;
	}
	return (size);
}

static void	copy_value(char *ret, int *j, char *val)
{
	int	i;

	i = 0;
	while (val && val[i])
		ret[(*j)++] = val[i++];
}
static void	handle_expand(char *s, char *ret, t_minishell *shell)
{
	int		i;
	int		j;
	char	*var;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] == '?')
		{
			var = ft_itoa(shell->exit_c);
			copy_value(ret, &j, var);
			free(var);
			i += 2;
		}
		else if (s[i] == '$' && (ft_isalnum(s[i + 1]) || s[i + 1] == '_'))
		{
			var = get_var_name(&s[i]);
			copy_value(ret, &j, get_var(shell->envp, var));
			free(var);
			i += ft_strlen(var) + 1;
		}
		else
			ret[j++] = s[i++];
	}
}

char	*expand(char *str, t_minishell *shell)
{
	int		i;
	char	*ret;
	int		size;

	i = 0;
	size = get_size(str, shell, 0);
	if (size == -1)
		return (NULL);
	ret = ft_calloc(size + 1, sizeof(char));
	if (!ret)
		return (NULL);
	handle_expand(str, ret, shell);
	ret[size] = '\0';
	return (ret);
}


