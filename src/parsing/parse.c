#include "../../cub3d.h"

t_parse	*ft_parse_map_continue(t_parse *parse, int dup, char *str)
{
	if (dup > 1)
	{
		parse->map_dup = 1;
	}
	if (dup == 0)
	{
		parse->map_no_pos = 1;
	}
	if (str != 0)
	{
		parse->map_end = 1;
	}
	return (parse);
}

t_parse	*ft_parse_map(char **map, t_parse *parse, int i, int dup)
{
	if (map[0] == 0)
	{
		parse->no_map = 1;
	}
	else
	{
		while (map && map[i] && ft_space(map[i]) == 1)
		{
			if ((i == 0 && ft_wall(map[i]) == 1) || ft_is_a_wall_around(map[i]) == 1)
			{
				parse->map_wall = 1;
			}
			if (map[i + 1] == 0)
			{
    			if (ft_wall(map[i]) == 1)
    			{
        			if (i > 0 && map[i - 1] != 0 && map[i - 1][i] == '1')
        			{
            			parse->map_wall = 1;
        			}
    			}
			}
			if (i > 0 && map[i + 1] != 0 && check_string_position(map[i - 1], map[i], map[i + 1]) == 1)
			{
				parse->map_wall = 1;
			}
			if (ft_unwanted_character(map[i]) == 1)
			{
				parse->map_wg_char = 1;
			}
			if (check_orientation(map[i]) > 0)
			{
				dup = dup + check_orientation(map[i]);
			}
			i++;
		}
		parse = ft_parse_map_continue(parse, dup, map[i]);
	}
	return (parse);
}

int	ft_parsing(char **tab)
{
	t_parse	*parse;
	char		**data;
	char		**map;

	if (!(parse = malloc(sizeof(t_parse))))
	{
		return (0);
	}
	if (!(data = malloc(sizeof(char *) * 9)))
	{
		return (0);
	}
	parse = init_struct(parse);
	parse = get_error(parse, tab, 0);
	data = ft_add_value_to_data(tab, parse, data, 0);
	map = ft_add_to_map(tab);
	parse = check_error(data, parse);
	parse = ft_parse_map(map, parse, 0, 0);
	print_error(parse);
	map = ft_free_tab(map);
	data = ft_free_tab(data);
	//ft_all_parse(parse); 	// sdkjgslgdklshfglsdlgksh sdlkghdlskghdlkshgklsdhghsglksdhlgk
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
    char    **tab;
    char    *line;
    int     fd;
    int     i;

    line = NULL;
    i = 0;
    fd = ft_fd_cub(filename);
    if (fd == -1)
        return (fd);
    tab = malloc(sizeof(char *) * 100);
    if (!tab)
        return (FAIL);
    while (gnl(fd, &line) == 1)
    {
        tab[i] = ft_pstrdup(line, '\0');
        free(line);
        i++;
    }
    tab[i] = 0;
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
        tab = ft_free_tab(tab);
        return (FAIL);
    }
 //   (void)map; // Variable 'map' is intentionally unused
    
    *map = malloc(sizeof(t_map));
    if (!(*map))
    {
        ft_free_data(data);
        tab = ft_free_tab(tab);
        return (FAIL);
    }
    (*map)->map = data->map; 
    ft_all_data(data);
	tab = ft_free_tab(tab);
    print_map(data->map);
   // tab = ft_free_tab(tab);
  //  ft_free_data(data);
    //free(data);
    return (SUCCESS);
}