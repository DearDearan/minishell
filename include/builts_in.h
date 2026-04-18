/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:13:34 by lifranco          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/18 15:34:45 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/04/17 13:27:04 by lifranco         ###   ########.fr       */
>>>>>>> a8dd686 (	modified:   Makefile)
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTS_IN_H
# define BUILTS_IN_H

/* FT_PWD_C */
<<<<<<< HEAD
int	ft_pwd(t_minishell *sh, t_cmd *cmd);

/* SET_ENVP_C*/
int	set_envp(t_minishell *sh, t_cmd *cmd);
=======
void	ft_pwd(t_minishell *sh);

/* GET_ENVP_C */
void	get_envp(char **envp, t_minishell *shell);

/* SET_ENVP_C*/
void	set_envp(t_minishell *sh, char **env, char *var);
>>>>>>> a8dd686 (	modified:   Makefile)
#endif