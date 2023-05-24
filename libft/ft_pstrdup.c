/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:03:17 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/24 19:03:18 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pstrlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_pstrjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		k;

	i = 0;
	k = 0;
	new = malloc(sizeof(char) * ft_pstrlen(s1, '\0')
			+ ft_pstrlen(s2, '\0') + 1);
	if (!new)
		return (NULL);
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

char	*ft_pstrdup(char *buffer, char c)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * ft_pstrlen(buffer, c) + 1);
	if (!new)
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
