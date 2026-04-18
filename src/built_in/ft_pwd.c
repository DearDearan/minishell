/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:39:07 by lifranco          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2026/04/16 13:43:14 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/04/16 12:02:06 by lifranco         ###   ########.fr       */
>>>>>>> 3650a83 (	modified:   src/built_in/ft_pwd.c)
<<<<<<< HEAD
/*   Updated: 2026/04/16 18:32:59 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/04/16 18:33:45 by lifranco         ###   ########.fr       */
>>>>>>> 8f51444 (	modified:   src/built_in/ft_pwd.c)
=======
/*   Updated: 2026/04/17 11:45:25 by lifranco         ###   ########.fr       */
>>>>>>> 61de3e8 (modified:   src/built_in/ft_pwd.c)
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
void	ft_pwd(t_minishell *sh)
=======
void	ft_pwd(t_minishell sh)
>>>>>>> 3650a83 (	modified:   src/built_in/ft_pwd.c)
{
	char	*path;
	int		i;

	i = 0;
	if (!sh->envp)
		error_exit(sh, sh->nb_cmds);
	while(sh->envp[i])
	{
		if (!ft_strncmp(sh->envp[i], "PWD=", 4))
		{
			path = getenv("PWD");
			break ;
		}
		else if (!ft_strncmp(sh->envp[i], "OLD_PWD=", 8))
		{
			path = get_env("OLD_PWD");
			break ;
		}
		i++;
	}
	printf("%s\n", path);
}
