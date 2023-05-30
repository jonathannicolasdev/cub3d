/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:53:04 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/26 16:53:06 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_map_zero_last_first(char **map, int y)
{
	int	i;

	i = 0;
	while (map[y - 1][i] != '\0')
	{
		if (map[y - 1][i] == '0')
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == '0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_map_check(t_parse *parse, char **map, int actual, int y)
{
	int	i;

	i = 0;
	if (ft_map_zero_last_first(map, y) == 1)
	{
		parse->map_wg_space = 1;
		return ;
	}
	while (map[actual][i] != '\0')
	{
		if ((ft_map_corner(map, actual, i) == 1)
			|| (ft_map_char(map, actual, i) == 1)
			|| (ft_map_space(map, actual, i, y) == 1)
			|| (ft_map_player(map, actual, i, y) == 1)
			|| (ft_map_zero(map, actual, i, y) == 1))
		{
			parse->map_wg_corner = 1;
			return ;
		}
		i++;
	}
}

t_parse	*ft_map(t_parse *parse, char **map)
{
	int	actual;
	int	y;

	actual = 0;
	y = 0;
	if (ft_map_total_position(map) == 1)
		parse->map_wg_player_number = 1;
	while (map[y] != NULL)
	{
		y++;
	}
	while (map[actual])
	{
		ft_map_check(parse, map, actual, y);
		actual++;
	}
	return (parse);
}
