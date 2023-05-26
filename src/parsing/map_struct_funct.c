#include "../../cub3d.h"

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

t_map	*create_map_from_data(t_data *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = data->map;
	return (map);
}