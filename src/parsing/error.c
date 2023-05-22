/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:08:55 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/22 17:08:55 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	tinder(char *str)
{
	int	i;

	i = 0;
	if (str && str[i])
	{
		if (str[i] == 'R' && str[i + 1] == ' ')
			return (1);
		else if (str[i] == 'N' && str[i + 1] == 'O')
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
	if (parse->north != 1 || parse->south != 1 || parse->west != 1
		|| parse->east != 1 || parse->floor != 1 || parse->ceiling != 1
		|| parse->no_map != 0 || parse->map_wg_char != 0 || parse->map_end != 0
		|| parse->map_wall != 0 || parse->map_dup != 0 || parse->map_no_pos != 0
		|| parse->wrong_line != 0)
	{
		return (1);
	}
	return (0);
}

t_parse	*get_error(t_parse *parse, char **tab, int i)
{
	while (tab[i])
	{
		if (tinder(tab[i]) == 2)
			parse->north = is_double(parse->north);
		else if (tinder(tab[i]) == 3)
			parse->south = is_double(parse->south);
		else if (tinder(tab[i]) == 4)
			parse->west = is_double(parse->west);
		else if (tinder(tab[i]) == 5)
			parse->east = is_double(parse->east);
		else if (tinder(tab[i]) == 7)
			parse->floor = is_double(parse->floor);
		else if (tinder(tab[i]) == 8)
			parse->ceiling = is_double(parse->ceiling);
		else if (tinder(tab[i]) == 9)
			parse->wrong_line = 1;
		i++;
	}
	return (parse);
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

void	print_error(t_parse *parse)
{
	if (parse->north != 1 || parse->south != 1 || parse->west != 1
		|| parse->east != 1 || parse->floor != 1 || parse->ceiling != 1
		|| parse->map_wg_char == 1 || parse->map_end == 1
		|| parse->map_wall == 1 || parse->map_dup == 1 || parse->map_no_pos == 1
		|| parse->no_map == 1 || parse->wrong_line == 1)
	{
		ft_pputstr("Error!\n");
	}
}
