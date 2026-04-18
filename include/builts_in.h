/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:13:34 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/18 15:45:58 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTS_IN_H
# define BUILTS_IN_H

/* FT_PWD_C */
int	ft_pwd(t_minishell *sh, t_cmd *cmd);

/* GET_ENVP_C */
int	get_envp(t_minishell *shell, t_cmd *cmd);

/* SET_ENVP_C*/
int	set_envp(t_minishell *sh, t_cmd *cmd);
#endif