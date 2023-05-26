/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:05:43 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/19 13:05:43 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_check_new_line(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	gnl_strlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(new = malloc(sizeof(char) * gnl_strlen(s1, '\0') + gnl_strlen(s2, '\0') + 1)))
	{
		return (NULL);
	}
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[k])
	{
		new[i++] = s2[k++];
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*gnl_strdup(char *buffer, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(char) * gnl_strlen(buffer, c) + 1)))
	{
		return (NULL);
	}
	while (buffer && buffer[i] && buffer[i] != c)
	{
		new[i] = buffer[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*gnl_strcut(char *buffer, char c)
{
	int	i;

	i = 0;
	if (!(buffer))
	{
		return (NULL);
	}
	if (gnl_check_new_line(buffer, c) == 0)
	{
		return (NULL);
	}
	while (buffer[i] != c)
	{
		i++;
	}
	i++;
	return (gnl_strdup(buffer + i, '\0'));
}
