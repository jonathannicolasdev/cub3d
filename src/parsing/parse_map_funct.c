/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:54:06 by ylabbe            #+#    #+#             */
/*   Updated: 2023/06/02 18:00:45 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_map_space(char **map, int actual, int i, int y)
{
	if (ft_isspace(map[actual][i]) == '1')
	{
		if (i - 1 >= 0 && map[actual][i - 1] == '0')
		{
			return (1);
		}
		if (map[actual][i + 1] == '0')
		{
			return (1);
		}
		if (actual + 1 != y && map[actual + 1][i] == '0')
		{
			return (1);
		}
		if (actual != 0 && map[actual - 1][i] == '0')
		{
			return (1);
		}
	}
	return (0);
}

int	ft_map_player(char **map, int actual, int i, int y)
{
	if (map[actual][i] == 'N' || map[actual][i] == 'S' || map[actual][i] == 'E'
		|| map[actual][i] == 'W')
	{
		if (i - 1 >= 0 && (map[actual][i - 1] != '0'
			&& map[actual][i - 1] != '1'))
			return (1);
		if (map[actual][i + 1] != '0' && map[actual][i + 1] != '1')
			return (1);
		if (actual + 1 != y && (map[actual + 1][i] != '0'
			&& map[actual + 1][i] != '1'))
			return (1);
		if (actual != 0 && (map[actual - 1][i] != '0'
			&& map[actual - 1][i] != '1'))
			return (1);
		if (actual + 1 == y)
			return (1);
	}
	return (0);
}

int	ft_map_char(char **map, int actual, int i)
{
	if (ft_skip(map[actual][i]) != 1 && map[actual][i] != '1'
		&& map[actual][i] != '0'
		&& map[actual][i] != 'N' && map[actual][i] != 'S'
		&& map[actual][i] != 'W' && map[actual][i] != 'E')
		return (1);
	return (0);
}

int	ft_map_zero(char **map, int actual, int i, int y)
{
	if (map[actual][i] == '0')
	{
		if (map[actual][i + 1] != '1' && map[actual][i + 1] != '0'
		&& map[actual][i + 1] != 'N' && map[actual][i + 1] != 'S'
		&& map[actual][i + 1] != 'E' && map[actual][i + 1] != 'W')
			return (1);
		if (map[actual][i - 1] != '1' && map[actual][i - 1] != '0'
		&& map[actual][i - 1] != 'N' && map[actual][i - 1] != 'S'
		&& map[actual][i - 1] != 'E' && map[actual][i - 1] != 'W')
			return (1);
		if (actual + 1 != y && map[actual + 1][i] != '1'
		&& map[actual + 1][i] != '0' && map[actual + 1][i] != 'N'
		&& map[actual + 1][i] != 'S' && map[actual + 1][i] != 'E'
		&& map[actual + 1][i] != 'W')
			return (1);
		if (actual - 1 > -1 && map[actual - 1][i] != '1'
		&& map[actual - 1][i] != '0' && map[actual - 1][i] != 'N'
		&& map[actual - 1][i] != 'S' && map[actual - 1][i] != 'E'
		&& map[actual - 1][i] != 'W')
			return (1);
		if (actual + 1 == y || actual == 0)
			return (1);
	}
	return (0);
}

int	ft_map_total_position(char **map)
{
	int	actual;
	int	i;
	int	total_position;

	actual = 0;
	i = 0;
	total_position = 0;
	while (map[actual])
	{
		i = 0;
		while (map[actual][i] != '\0')
		{
			if (map[actual][i] == 'N' || map[actual][i] == 'S'
				|| map[actual][i] == 'W' || map[actual][i] == 'E')
				total_position++;
			i++;
		}
		actual++;
	}
	if (total_position == 1)
		return (0);
	return (1);
}
