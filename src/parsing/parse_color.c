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

char	*ft_file_color(char *str)
{
	char	*result;
	int		index;
	int		count;

	index = 0;
	count = 0;
	result = malloc(sizeof(char) * ft_strlen(str));
	if (!result)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			count++;
			str++;
		}
		else if (ft_isalpha(*str))
		{
			count++;
			str++;
		}
		else if (ft_isdigit(*str) || *str == ',')
		{
			result[index++] = *str;
			str++;
		}
		else
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

int	validate_rgb_color(char *str, int i)
{
	if (str && str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
		{
			while (str[i] && str[i] >= '0' && str[i] <= '9')
				i++;
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i] && str[i] == ',')
			{
				i++;
				while (str[i] && str[i] == ' ')
					i++;
				if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
				{
					while (str[i] && str[i] >= '0' && str[i] <= '9')
						i++;
					while (str[i] && str[i] == ' ')
						i++;
					if (str[i] && str[i] == ',')
					{
						i++;
						while (str[i] && str[i] == ' ')
							i++;
						if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
						{
							while (str[i] && str[i] >= '0' && str[i] <= '9')
								i++;
							while (str[i] && str[i] == ' ')
								i++;
							if (!str[i])
								return (validate_color_string(str, i));
						}
					}
				}
			}
		}
	}
	return (3);
}
