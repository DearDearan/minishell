/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:39:07 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/27 16:28:23 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_minishell *sh, t_cmd *cmd)
{
	char	*pwd_path;
	
	(void)cmd;
	pwd_path = getcwd(NULL, 0);
	if (!pwd_path)
		error_exit(sh, sh->nb_cmds);
	printf("%s\n", pwd_path);
	free(pwd_path);
	return (EXIT_SUCCESS);
}
