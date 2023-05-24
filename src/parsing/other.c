/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:34:03 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/24 18:34:55 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_non_map_char(char c)
{
	if (c != '\0' && c != '1' && c != '0' && c != ' ')
		return (1);
	return (0);
}

int	is_double(int a)
{
	if (a == 1 || a == 2)
		return (2);
	return (1);
}

int	ft_space(char *str)
{
	char	*ptr;

	ptr = str;
	if (*ptr == ' ')
	{
		while (*ptr == ' ')
			ptr++;
	}
	return (*ptr == '1' || *ptr == '0');
}
