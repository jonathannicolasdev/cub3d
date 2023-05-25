/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:37:34 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/24 17:54:11 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_parse_file(char *filename, char ***tab_ptr)
{
	char	**tab;
	char	*line;
	int		fd;
	int		i;

	line = NULL;
	i = 0;
	fd = ft_fd_cub(filename);
	if (fd == -1)
		return (fd);
	tab = malloc(sizeof(char *) * 100);
	if (!tab)
		return (FAIL);
	ft_memset(tab, 0, sizeof(char *) * 100);
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

int	parse_file_and_tab(char *filename, char ***tab)
{
	int	ret;

	ret = ft_parse_file(filename, tab);
	if (ret != SUCCESS)
		return (ret);
	if (ft_parsing(*tab) == 1)
	{
		*tab = ft_free_tab(*tab);
		return (FAIL);
	}
	return (SUCCESS);
}

t_data	*create_data_from_tab(char **tab)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data = ft_add_to_data(data, tab, 0);
	if (!data)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

t_map	*create_map_from_data(t_data *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = data->map;
	return (map);
}

void	ft_map_player_position(t_map *data, char **map)
{
	int	actual;
	int	i;

	actual = 0;
	i = 0;
	while (map[actual])
	{
		i = 0;
		while (map[actual][i] != '\0')
		{
			if (map[actual][i] == 'N' || map[actual][i] == 'S'
				|| map[actual][i] == 'W' || map[actual][i] == 'E')
			{
				data->player_x = i + 0.5;
				data->player_y = actual + 0.5;
			}
			i++;
		}
		actual++;
	}
}

int	ft_parse(char **argv, t_map **map)
{
	char	**tab;
	t_data	*data;

	if (parse_file_and_tab(argv[1], &tab) != SUCCESS)
		return (FAIL);
	data = create_data_from_tab(tab);
	tab = ft_free_tab(tab);
	if (!data)
		return (FAIL);
	*map = create_map_from_data(data);
	free(data);
	if (!(*map))
		return (FAIL);
	ft_map_player_position(*map, (*map)->map);
	return (SUCCESS);
}
