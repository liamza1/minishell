/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:55:46 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/20 15:18:02 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include "../libft/libft.h"

# define IS_QUOTE(x) (x == '"' || x == '\'')

int						exec_comm(char **command);
char					**g_envv;
void					exit_shell(void);
void					display_prompt_msg(void);
void					change_dir(char *path, int print_path);
int						cd_builtin(char **command);
int						echo_builtin(char **command);
int						exec_command(char **command);
int						unsetenv_builtin(char **args);
void					init_envv(int argc, char **argv, char **envv);
void					print_env(void);
int						setenv_builtin(char **args);
void					set_env_var(char *key, char *value);
char					**realloc_envv(int size);
char					*get_envv(char *var);
int						find_envv(char *var);
char					*parse_home_path(char *path, int reverse_parse);
void					signal_handler(int signo);
void					proc_signal_handler(int signo);

#endif
