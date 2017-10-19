/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 07:35:43 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/20 14:56:57 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Prints a path on the screen by making sure it's parsed first
**
** @param		path	The path to print
** @return		N/A
*/

void			print_pth(char *path)
{
	char	*home;

	home = parse_home_path(path, 0);
	ft_putstr(home);
	free(home);
}

/*
** Changes the working directoy and updates the environment variable
** accordingly while handling errors
** NOTE: I was not allowed to use errno/strerror to handle errors for this
** project.
** TODO: I should be changing the value of PWD too but I was getting
** some memory leaks for some reason. I will fix that later.
**
** @param		path			The path to change to
** @param		print_path		A boolean to know whether a not to print the
**								path
** @return		N/A
*/

void			change_dir(char *path, int print_path)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		if (print_path)
		{
			print_pth(path);
			ft_putchar('\n');
		}
		set_env_var("OLDPWD", cwd);
	}
	else
	{
		ft_putstr("cd: ");
		if (access(path, F_OK) == -1)
			ft_putstr("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			ft_putstr("permission denied: ");
		else
			ft_putstr("not a directory: ");
		ft_putendl(path);
	}
}

/*
** Checks if the input has two or more arguments and acts accordingly
**
** @param		args	The list of arguments to check
** @return		0 if there is no second argument, 1 if there is
*/

int				has_two_args(char **args)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*tmp;

	if (args[1])
	{
		if (args[2])
		{
			ft_putendl("cd: too many arguments");
			return (1);
		}
		cwd = getcwd(buff, 4096);
		if (!(tmp = ft_strreplace(cwd, args[0], args[1])))
		{
			ft_putstr("cd: string not in pwd: ");
			ft_putendl(args[0]);
			free(tmp);
			return (1);
		}
		change_dir(tmp, 1);
		free(tmp);
		return (1);
	}
	return (0);
}

/*
** Executes the builtin cd command
**
** @param		args	The arguments to pass to cd
** @return 		1 on completion
*/

int				cd_builtin(char **args)
{
	char	*home;

	home = get_envv("HOME");
	if (!args[0])
	{
		change_dir(home, 0);
		return (1);
	}
	if (has_two_args(args))
		return (1);
	else
	{
		if (ft_strequ(args[0], "--"))
		{
			change_dir(home, 0);
			return (1);
		}
		else if (args[0][0] == '-' && !args[0][2])
		{
			change_dir(get_envv("OLDPWD"), 1);
			return (1);
		}
		change_dir(args[0], 0);
	}
	return (1);
}
