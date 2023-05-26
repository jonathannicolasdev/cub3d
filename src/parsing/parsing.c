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

int	ft_error(t_parse *parse)
{
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

int	ft_space(char *str)
{
	char	*ptr;

	ptr = str;
	if (*ptr == ' ')
	{
		while (*ptr == ' ')
			ptr++;
	}
	return (*ptr == '1' || *ptr == '0');
}

char	**ft_add_to_map(char **tab)
{
	char	**map;
	int		i;
	int		k;

	i = 0;
	k = 0;
	map = malloc(sizeof(char *) * 100);
	if (!(map))
		return (NULL);
	while (tab && tab[i])
	{
		if (ft_space(tab[i]) == 1)
		{
			while (tab[i])
				map[k++] = ft_pstrdup(tab[i++], '\0');
			break ;
		}
		i++;
	}
	map[k] = 0;
	return (map);
}

void print_struct(t_parse *parse) {
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
		while (str[i] == ' ')
			i++;
		if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
			return (1);
		else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
			return (2);
		else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
			return (3);
		else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
			return (4);
		else if (str[i] == 'F' && str[i + 1] == ' ')
			return (5);
		else if (str[i] == 'C' && str[i + 1] == ' ')
			return (6);
		else if (ft_map_lost(str[i]) == 1)
			return (7);
	}
	return (0);
}

char* ft_file_path(const char* line) {
    char* start = strchr(line, '.');
    if (start != NULL) {
        char* end = strstr(start, ".xpm");
        if (end != NULL && end > start) {
            size_t filepath_length = end - start + 4;
            char* filepath = (char*)malloc((filepath_length + 1) * sizeof(char));
            strncpy(filepath, start, filepath_length);
            filepath[filepath_length] = '\0';
            return filepath;
        }
    }
    return NULL;
}

int ft_check_file(char *str)
{
	char *penis;
	int fd;

	penis = ft_file_path(str);
	if (penis == NULL)
	{
		printf("Invalid file path.\n");
		return 3;
	}
	fd = open(penis, O_RDONLY);
	free(penis);
	if (fd == -1)
	{
		printf("Failed to open file.\n");
		return 3;
	}
	if (fd == 3)
	{
		close(fd);
		return 1;
	}
	return 3;
}


t_parse	*ft_check_error(char **data, t_parse *parse)
{
	int	i;

	i = 0;
	while (data && data[i])
	{
		if (ft_file(data[i]) == 1 && parse->file_north == 1)
			parse->file_north = ft_check_file(data[i]);
		else if (ft_file(data[i]) == 2 && parse->file_south == 1)
			parse->file_south = ft_check_file(data[i]);
		else if (ft_file(data[i]) == 3 && parse->file_west == 1)
			parse->file_west = ft_check_file(data[i]);
		else if (ft_file(data[i]) == 4 && parse->file_east == 1)
			parse->file_east = ft_check_file(data[i]);
		else if (ft_file(data[i]) == 5 && parse->file_floor == 1)
			parse->file_floor = validate_rgb_color(data[i], 2);
		else if (ft_file(data[i]) == 6 && parse->file_ceiling == 1)
			parse->file_ceiling = validate_rgb_color(data[i], 2);
		i++;
	}
	return (parse);
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
	return (parse);
}

char	**ft_add_value_to_data(char **tab, t_parse *parse, char **data, int i)
{
	int	k;
	int	type;

	k = 0;
	while (tab[i])
	{
		type = ft_file(tab[i]);
		if (((type == 1 && parse->file_north)
				|| (type == 2 && parse->file_south)
				|| (type == 3 && parse->file_west)
				|| (type == 4 && parse->file_east)
				|| (type == 5 && parse->file_floor)
				|| (type == 6 && parse->file_ceiling)))
		{
			data[k++] = ft_pstrdup(tab[i], '\0');
		}
		i++;
	}
	data[k] = 0;
	return (data);
}

char *ft_file_color(char *str)
{
    char *result;
    int index;
    int count;

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
t_data	*ft_add_to_data(t_data *data, char **tab, int i)
{
	while (tab && tab[i])
	{
		if (ft_file(tab[i]) == 1)
			data->file_north = ft_file_path(tab[i]);
		if (ft_file(tab[i]) == 2)
			data->file_south = ft_file_path(tab[i]);
		if (ft_file(tab[i]) == 3)
			data->file_west = ft_file_path(tab[i]);
		if (ft_file(tab[i]) == 4)
			data->file_east = ft_file_path(tab[i]);
		if (ft_file(tab[i]) == 5)
			data->color_floor = ft_file_color(tab[i]);
		if (ft_file(tab[i]) == 6)
			data->color_ceiling = ft_file_color(tab[i]);
		i++;
	}
	data->map = ft_add_to_map(tab);
	return (data);
}


int	ft_parsing_second(t_parse *parse, char **data, char **map)
{
	parse = ft_check_error(data, parse);
	parse = ft_map(parse, map);
	map = ft_free_tab(map);
	data = ft_free_tab(data);
	print_struct(parse);
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
