/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:18:18 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/20 14:54:49 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Prints out a string on the screen
**
** @param		str		The string to print
** @param		pos		The position at which to start printing
** @return		N/A
*/

static void	echo_out(char **str, int pos)
{
	int		start;
	int		end;
	int		len;

	start = IS_QUOTE(str[pos][0]);
	len = (int)ft_strlen(str[pos]);
	end = IS_QUOTE(str[pos][len - 1]);
	if (end && start)
		ft_putnstr(str[pos] + 1, -1);
	else if (end)
		ft_putnstr(str[pos], -1);
	else if (start)
		ft_putstr(str[pos + 1]);
	else
		ft_putstr(str[pos]);
	if (str[pos + 1])
		ft_putchar(' ');
}

/*
** Executes the builtin echo command
**
** @param		args		The arguments to pass to echo
** @return		1 on completion
*/

int			echo_builtin(char **args)
{
	int		i;
	int		flag;

	flag = 0;
	if (!args[0])
	{
		write(1, "\n", 1);
		return (1);
	}
	else if (args[0][0] == '-' && args[0][1] == 'n' && args[0][2] == '\0')
		flag = 1;
	i = -1;
	if (flag)
		i++;
	while (args[++i])
	{
		echo_out(args, i);
		if (!args[i + 1] && !flag)
			ft_putchar('\n');
	}
	return (1);
}
