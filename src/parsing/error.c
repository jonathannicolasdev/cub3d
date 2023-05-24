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
	if (parse->north != 1 || parse->south != 1 || parse->west != 1
		|| parse->east != 1 || parse->floor != 1 || parse->ceiling != 1
		|| parse->no_map != 0 || parse->map_wg_char != 0 || parse->map_end != 0
		|| parse->map_wall != 0 || parse->map_dup != 0 || parse->map_no_pos != 0
		|| parse->wrong_line != 0)
	{
		return (1);
	}
	if (parse->map_wg_player != 0 || parse->map_wg_player_number != 0 || parse->map_wg_space != 0
		|| parse->map_wg_zero != 0 || parse->map_wg_character != 0)
	{
		printf("La map cause problème mon pote.\n");
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

int ft_parsing(char **tab)
{
	t_parse *parse;
	char **data;
	char **map;

	if (!(parse = malloc(sizeof(t_parse))))
	{
		return (0);
	}
	if (!(data = malloc(sizeof(char *) * 9)))
	{
		free(parse);
		return (0);
	}
	parse = init_struct(parse);
	parse = get_error(parse, tab, 0);
	data = ft_add_value_to_data(tab, parse, data, 0);
	map = ft_add_to_map(tab);
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


int ft_parse_file(char *filename, char ***tab_ptr)
{
	char **tab;
	char *line;
	int fd;
	int i;

	line = NULL;
	i = 0;
	fd = ft_fd_cub(filename);
	if (fd == -1)
		return (fd);
	tab = malloc(sizeof(char *) * 100);
	if (!tab)
	{
		return (FAIL);
	}
	memset(tab, 0, sizeof(char *) * 100);
	while (gnl(fd, &line) == 1)
	{
		tab[i] = ft_pstrdup(line, '\0');
		free(line);
		i++;
	}
	tab[i] = ft_pstrdup(line, '\0');
	free(line);
	*tab_ptr = tab;
	close(fd);
	return (SUCCESS);
}

int ft_parse(char **argv, t_map **map)
{
    t_data  *data;
    char    **tab;
    int     ret;

    ret = ft_parse_file(argv[1], &tab);
    if (ret != SUCCESS)
        return (ret);
    if (ft_parsing(tab) == 1)
    {
        tab = ft_free_tab(tab);
        return (FAIL);
    }
    data = malloc(sizeof(t_data));
    if (!data)
    {
        tab = ft_free_tab(tab);
        return (FAIL);
    }
    data = ft_add_to_data(data, tab, 0);
    if (!data)
    {
		free(data);
        tab = ft_free_tab(tab);
        return (FAIL);
    }
    *map = malloc(sizeof(t_map));
    if (!(*map))
    {
        ft_free_data(data);
        tab = ft_free_tab(tab);
        return (FAIL);
    }
    (*map)->map = data->map;
	//ft_free_data(data); // Besoin pour cesser le leaks
	tab = ft_free_tab(tab);
	free(data);
    return (SUCCESS);
}