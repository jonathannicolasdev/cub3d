/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:03:06 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/24 19:03:07 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_new_line(char *str, char c)
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

char	*ft_strcut(char *buffer, char c)
{
	int	i;

	i = 0;
	if (!(buffer))
		return (NULL);
	if (check_new_line(buffer, c) == 0)
		return (NULL);
	while (buffer[i] != c)
		i++;
	i++;
	return (ft_pstrdup(buffer + i, '\0'));
}
