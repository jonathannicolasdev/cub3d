/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:08:55 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/24 18:33:40 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


int	tinder(char *str)
{
	int	i;

	i = 0;
	if (str && str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
			return (2);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			return (3);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			return (4);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			return (5);
		else if (str[i] == 'F' && str[i + 1] == ' ')
			return (7);
		else if (str[i] == 'C' && str[i + 1] == ' ')
			return (8);
		else if (is_non_map_char(str[i]) == 1)
			return (9);
	}
	return (0);
}

int	ft_error(t_parse *parse)
{
	if (parse->no_map != 0 || parse->map_wg_char != 0 || parse->map_end != 0
		|| parse->map_wall != 0 || parse->map_dup != 0 || parse->map_no_pos != 0)
	{
		printf("penis!\n");
		return (1);
	}
	if (parse->file_north != 1 || parse->file_south != 1 || parse->file_west != 1
		|| parse->file_east != 1 || parse->file_ceiling != 1 || parse->file_floor != 1
		|| parse->file_wrong_line != 0)
	{
		printf("Couleur/Texture en double!?\n");
		return (1);
	}
	if (parse->map_wg_player != 0 || parse->map_wg_player_number != 0
		|| parse->map_wg_space != 0 || parse->map_wg_zero != 0
		|| parse->map_wg_character != 0)
	{
		printf("La map cause problème mon pote.\n");
		return (1);
	}
	return (0);
}

t_parse	*check_error(char **data, t_parse *parse)
{
	int	i;

	i = 0;
	while (data && data[i])
	{
		if (tinder(data[i]) == 2 && parse->north == 1)
			parse->north = check_file_readability(data[i], 3);
		else if (tinder(data[i]) == 3 && parse->south == 1)
			parse->south = check_file_readability(data[i], 3);
		else if (tinder(data[i]) == 4 && parse->west == 1)
			parse->west = check_file_readability(data[i], 3);
		else if (tinder(data[i]) == 5 && parse->east == 1)
			parse->east = check_file_readability(data[i], 3);
		else if (tinder(data[i]) == 7 && parse->floor == 1)
			parse->floor = validate_rgb_color(data[i], 2);
		else if (tinder(data[i]) == 8 && parse->ceiling == 1)
			parse->ceiling = validate_rgb_color(data[i], 2);
		i++;
	}
	return (parse);
}
