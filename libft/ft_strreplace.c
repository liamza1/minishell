/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:53:22 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/20 13:53:24 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char *term, char *replace_by)
{
	int		i;
	char	*new_path;
	int		done;

	if (!ft_strstr(str, term))
		return (NULL);
	new_path = ft_strnew(1);
	i = -1;
	done = 0;
	while (str[++i])
	{
		if (ft_strstartswith(str + i, term) && !done)
		{
			new_path = ft_strjoincl(new_path, replace_by, 0);
			i += ft_strlen(term);
			if (!str[i])
				break ;
			new_path = ft_strjoinchcl(new_path, str[i]);
			done = 1;
		}
		else
			new_path = ft_strjoinchcl(new_path, str[i]);
	}
	return (new_path);
}
