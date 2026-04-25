/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:13:34 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/27 13:43:56 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTS_IN_H
# define BUILTS_IN_H

/* FT_ECHO_C */
int		ft_echo(t_minishell *sh, t_cmd *cmd);

/* FT_PWD_C */
int		ft_pwd(t_minishell *sh, t_cmd *cmd);

/* FT_EXPORT_C */
int		ft_export(t_minishell *sh, t_cmd *cmd);

/* SET_ENVP_C */
void	put_into_env(char *var, char **envp, t_minishell *shell);

/* FT_EXIT_C */
int		ft_exit(t_minishell *sh, t_cmd *cmd);

/* FT_ENV_C */
int		ft_env(t_minishell *sh, t_cmd *cmd);

/*FT_UNSET_C */
int		ft_unset(t_minishell *sh, t_cmd *cmd);

/* UNSET_C */
void	ft_unset_env(char *var, t_minishell *sh);

#endif
