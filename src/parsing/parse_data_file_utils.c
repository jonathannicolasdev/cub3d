/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_file_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:34:50 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/29 16:34:51 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	ft_isalpha_or_point(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == 'N' && line[i + 1] == 'O')
			|| (line[i] == 'S' && line[i + 1] == 'O')
			|| (line[i] == 'W' && line[i + 1] == 'E')
			|| (line[i] == 'E' && line[i + 1] == 'A'))
			break ;
		i++;
	}
	i += 2;
	while (line[i] != '\0')
	{
		if ((line[i] >= 'a' && line[i] <= 'z')
			|| (line[i] >= 'A' && line[i] <= 'Z')
			|| (line[i] >= '0' && line[i] <= '9')
			|| (line[i] == '.'))
			return (line[i]);
		i++;
	}
	return ('\0');
}

int	ft_after_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '.' && line[i + 1] == 'x'
			&& line[i + 2] == 'p' && line[i + 3] == 'm')
			break ;
		i++;
	}
	i += 4;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
