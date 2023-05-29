/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:54:12 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/26 16:54:13 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_valid_character(char c)
{
	return (ft_isdigit(c) || c == ',');
}

char	*ft_file_color(char *str)
{
	char	*result;
	int		index;

	index = 0;
	result = malloc(sizeof(char) * ft_strlen(str));
	if (!result)
		return (NULL);
	while (*str != '\0')
	{
		if (is_valid_character(*str))
		{
			result[index++] = *str;
		}
		str++;
	}
	result[index] = '\0';
	return (result);
}

int	validate_color_string(char *str, int i)
{
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (1);
	return (3);
}

int	is_valid_number(char *str, int i)
{
	if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
	{
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		return (i);
	}
	return (-1);
}

int	validate_rgb_color(char *str, int i)
{
	if (str && str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		i = is_valid_number(str, i);
		if (i != -1 && str[i] && str[i] == ',')
		{
			i++;
			while (str[i] && str[i] == ' ')
				i++;
			i = is_valid_number(str, i);
			if (i != -1 && str[i] && str[i] == ',')
			{
				i++;
				while (str[i] && str[i] == ' ')
					i++;
				i = is_valid_number(str, i);
				if (i != -1 && !str[i])
					return (validate_color_string(str, i));
			}
		}
	}
	return (3);
}
