/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:13:34 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/17 13:27:04 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTS_IN_H
# define BUILTS_IN_H

/* FT_PWD_C */
void	ft_pwd(t_minishell *sh);

/* GET_ENVP_C */
void	get_envp(char **envp, t_minishell *shell);

/* SET_ENVP_C*/
void	set_envp(t_minishell *sh, char **env, char *var);
#endif