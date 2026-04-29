/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:42:57 by Camille           #+#    #+#             */
/*   Updated: 2026/04/28 18:11:46 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	get_option_n(int argc, char **argv);
static void	print_echo_argv(int argc, char **argv, bool option_n);

int	ft_echo(t_minishell *sh, t_cmd *cmd)
{
	int		argc;
	bool	option_n;

	(void)sh;
	argc = get_argc(cmd->argv);
	option_n = get_option_n(argc, cmd->argv);
	print_echo_argv(argc, cmd->argv, option_n);
	if (!option_n)
		printf("\n");
	return (EXIT_SUCCESS);
}

static bool	get_option_n(int argc, char **argv)
{
	int	size;

	if (argc > 1)
	{
		size = ft_strlen(argv[1]);
		if (size == 2 && !ft_strncmp(argv[1], "-n", size))
			return (true);
	}
	return (false);
}

static void	print_echo_argv(int argc, char **argv, bool option_n)
{
	int		i;
	char	*newline;

	if (option_n)
		i = 2;
	else
		i = 1;
	newline = NULL;
	while (i < argc)
	{
		if (option_n)
			newline = ft_strchr(argv[i], '\n');
		if (newline)
		{
			printf("%.*s", (int)(newline - argv[i]), argv[i]);
			break ;
		}
		else
			printf("%s", argv[i]);
		if (i + 1 < argc)
			printf(" ");
		i++;
	}
}
