/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:55:45 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/24 17:55:46 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void print_struct(t_parse *parse) {
    printf("parse->north = %d\n", parse->north);
    printf("parse->south = %d\n", parse->south);
    printf("parse->west = %d\n", parse->west);
    printf("parse->east = %d\n", parse->east);
    printf("parse->floor = %d\n", parse->floor);
    printf("parse->ceiling = %d\n", parse->ceiling);
    printf("parse->map_wg_char = %d\n", parse->map_wg_char);
    printf("parse->map_end = %d\n", parse->map_end);
    printf("parse->map_wall = %d\n", parse->map_wall);
    printf("parse->map_dup = %d\n", parse->map_dup);
    printf("parse->map_no_pos = %d\n", parse->map_no_pos);
    printf("parse->no_map = %d\n", parse->no_map);
    printf("parse->wrong_line = %d\n", parse->wrong_line);
    printf("parse->map_wg_player = %d\n", parse->map_wg_player);
    printf("parse->map_wg_player_number = %d\n", parse->map_wg_player_number);
    printf("parse->map_wg_space = %d\n", parse->map_wg_space);
    printf("parse->map_wg_zero = %d\n", parse->map_wg_zero);
    printf("parse->map_wg_character = %d\n", parse->map_wg_character);
    printf("parse->file_north = %d\n", parse->file_north);
    printf("parse->file_south = %d\n", parse->file_south);
    printf("parse->file_west = %d\n", parse->file_west);
    printf("parse->file_east = %d\n", parse->file_east);
    printf("parse->file_floor = %d\n", parse->file_floor);
    printf("parse->file_ceiling = %d\n", parse->file_ceiling);
    printf("parse->file_wrong_line = %d\n", parse->file_wrong_line);
}

int	ft_map_lost(char c)
{
	if (c != '\0' && c != '1' && c != '0' && c != ' ')
		return (1);
	return (0);
}

int	ft_file(char *str)
{
	int	i;

	i = 0;
	if (str && str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
			return (1);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			return (2);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			return (3);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			return (4);
		else if (str[i] == 'F')
			return (5);
		else if (str[i] == 'C')
			return (6);
		else if (ft_map_lost(str[i]) == 1)
			return (7);
	}
	return (0);
}

t_parse	*ft_get_error(t_parse *parse, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_file(tab[i]) == 1)
			parse->file_north += 1;
		else if (ft_file(tab[i]) == 2)
			parse->file_south += 1;
		else if (ft_file(tab[i]) == 3)
			parse->file_west += 1;
		else if (ft_file(tab[i]) == 4)
			parse->file_east += 1;
		else if (ft_file(tab[i]) == 5)
			parse->file_floor += 1;
		else if (ft_file(tab[i]) == 6)
			parse->file_ceiling += 1;
		else if (ft_file(tab[i]) == 7)
			parse->file_wrong_line += 1;
		i++;
	}
	print_struct(parse);
	return (parse);
}

int	ft_parsing_second(t_parse *parse, char **data, char **map)
{
	parse = check_error(data, parse);
	parse = ft_map(parse, map);
	map = ft_free_tab(map);
	data = ft_free_tab(data);
	if (ft_error(parse) == 1)
	{
		free(parse);
		return (1);
	}
	free(parse);
	return (0);
}

int	ft_parsing(char **tab)
{
	t_parse	*parse;
	char	**data;
	char	**map;

	parse = malloc(sizeof(t_parse));
	if (!parse)
		return (0);
	data = malloc(sizeof(char *) * 9);
	if (!data)
	{
		free(parse);
		return (0);
	}
	parse = init_struct(parse);
	parse = ft_get_error(parse, tab);
	data = ft_add_value_to_data(tab, parse, data, 0);
	map = ft_add_to_map(tab);
	return (ft_parsing_second(parse, data, map));
}
