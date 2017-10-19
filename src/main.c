/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:50:50 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/20 15:12:10 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Parses a string to convert variables to their value then returns the parsed
** string
**
** @param		str		The input string to parse
** @param		pos		The position from which to start in the string
*/

static char	*parse_envv(char *str, int pos)
{
	char	*value;
	char	*key;
	char	c;

	key = ft_strnew(1);
	while (str[pos] && !IS_SPACE(str[pos]))
	{
		c = str[pos];
		key = ft_strjoinchcl(key, c);
		pos++;
	}
	if (!(value = get_envv(key)))
	{
		free(key);
		return (NULL);
	}
	free(key);
	return (value);
}

/*
** Parses the input by changing $VAR_NAME to the value of VAR_NAME in the
** environment variable or by nothing if it doesn't exist and by changing ~
** to the value of the user's home path then returns the parsed string
**
** @param		input		The input string
** @return		The parsed string
*/

static char	*parse_in(char *input)
{
	int		i;
	char	*new;

	i = -1;
	new = ft_strnew(1);
	while (input[++i])
	{
		if (input[i] == '$' && input[i + 1])
		{
			new = ft_strjoincl(new, parse_envv(input, i + 1), 0);
			while (input[i + 1] &&
					!IS_SPACE(input[i + 1]) && input[i + 1] != '$')
				i++;
		}
		else if (((i != 0 && IS_SPACE(input[i - 1])) || i == 0)
				&& input[i] == '~')
		{
			new = ft_strjoincl(new, parse_home_path(input + i, 1), 1);
			i += ft_strlen(input + i) - 1;
		}
		else
			new = ft_strjoinchcl(new, input[i]);
	}
	free(input);
	return (new);
}

/*
** Displays a prompt on the screen and fills the input character by character
** then adds it to the referenced variable (input) after parsing the whole
** input if necessary
**
** @param	input	The address of the variable to fill with the parsed input
** @return	N/A
*/

static void	get_in(char **input)
{
	int		ret;
	char	buf;
	int		i;
	int		c;

	*input = ft_strnew(1);
	c = 1;
	i = 0;
	while ((ret = read(0, &buf, 1)) && buf != '\n')
	{
		*(*input + i++) = buf;
		*input = ft_realloc(*input, c, c + 1);
		c++;
	}
	*(*input + i) = '\0';
	if (!ret)
	{
		free(*input);
		exit_shell();
	}
	if ((ft_strchr(*input, '$') != NULL) || (ft_strchr(*input, '~') != NULL))
		*input = parse_in(*input);
}

/*
** Takes care of multiple commands in the input
**
** @param		commands	The list of commands to execute
** @return		-1 if there was an interruption from one of the commands
**				or 0/1 if not
*/

int			exec_command(char **commands)
{
	int		i;
	int		ret;
	char	**command;

	i = -1;
	ret = 0;
	while (commands[++i])
	{
		command = ft_strsplitall(commands[i]);
		ret = exec_comm(command);
		ft_freestrarr(command);
		if (ret == -1)
			break ;
	}
	return (ret);
}

/*
** Initializes minishell
**
** @param	ac		argument counts
** @param	av		argument variables
** @param	envv	environment variables
** @return	0 on completion
*/

int			main(int argc, char **argv, char **envv)
{
	char	*input;
	int		ret;
	char	**commands;

	init_envv(argc, argv, envv);
	while (1)
	{
		display_prompt_msg();
		signal(SIGINT, signal_handler);
		get_in(&input);
		if (ft_isemptystr(input, 1))
		{
			free(input);
			continue;
		}
		commands = ft_strsplit(input, ';');
		free(input);
		ret = exec_command(commands);
		ft_freestrarr(commands);
		if (ret == -1)
			break ;
	}
	ft_freestrarr(g_envv);
	return (0);
}
