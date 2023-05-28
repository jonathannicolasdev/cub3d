/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_corner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:59:31 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/28 18:59:32 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_map_corner_top_rigth(char **map, int actual, int i)
{
	if (map[actual][i + 1] == '1' && map[actual - 1][i] == '1')
		if (map[actual - 1][i + 1] != '1' && map[actual - 1][i + 1] != '0'
			&& map[actual - 1][i + 1] != 'N' && map[actual - 1][i + 1] != 'S'
			&& map[actual - 1][i + 1] != 'W' && map[actual - 1][i + 1] != 'E')
			return (1);
	return (0);
}

int	ft_map_corner_bot_rigth(char **map, int actual, int i)
{
	if (map[actual][i + 1] == '1' && map[actual + 1][i] == '1')
		if (map[actual + 1][i + 1] != '1' && map[actual + 1][i + 1] != '0'
			&& map[actual + 1][i + 1] != 'N' && map[actual + 1][i + 1] != 'S'
			&& map[actual + 1][i + 1] != 'S' && map[actual + 1][i + 1] != 'W')
			return (1);
	return (0);
}

int	ft_map_corner_bot_left(char **map, int actual, int i)
{
	if (map[actual][i - 1] == '1' && map[actual + 1][i] == '1')
		if (map[actual + 1][i - 1] != '1' && map[actual + 1][i - 1] != '0'
			&& map[actual + 1][i - 1] != 'N' && map[actual + 1][i - 1] != 'S'
			&& map[actual + 1][i - 1] != 'W' && map[actual + 1][i - 1] != 'E')
			return (1);
	return (0);
}

int	ft_map_corner_top_left(char **map, int actual, int i)
{
	if (map[actual][i - 1] == '1' && map[actual - 1][i] == '1')
		if (map[actual - 1][i - 1] != '1' && map[actual - 1][i - 1] != '0'
			&& map[actual - 1][i - 1] != 'N' && map[actual - 1][i - 1] != 'S'
			&& map[actual - 1][i - 1] != 'W' && map[actual - 1][i - 1] != 'E')
			return (1);
	return (0);
}

int	ft_map_corner(char **map, int actual, int i)
{
	if (map[actual][i] == '0')
	{
		if (ft_map_corner_top_rigth(map, actual, i) == 1)
			return (1);
		if (ft_map_corner_bot_rigth(map, actual, i) == 1)
			return (1);
		if (ft_map_corner_bot_left(map, actual, i) == 1)
			return (1);
		if (ft_map_corner_top_left(map, actual, i) == 1)
			return (1);
	}
	return (0);
}
