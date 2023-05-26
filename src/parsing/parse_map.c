#include "../../cub3d.h"

void	ft_map_check(t_parse *parse, char **map, int actual, int y)
{
	int	i;

	i = 0;
	while (map[actual][i] != '\0')
	{
		if (ft_map_char(map, actual, i) == 1)
			parse->map_wg_character = 1;
		if (ft_map_space(map, actual, i, y) == 1)
			parse->map_wg_space = 1;
		if (ft_map_player(map, actual, i, y) == 1)
			parse->map_wg_player = 1;
		if (ft_map_zero(map, actual, i, y) == 1)
			parse->map_wg_zero = 1;
		i++;
	}
}

t_parse	*ft_map(t_parse *parse, char **map)
{
	int	i;
	int	actual;
	int	y;

	i = 0;
	actual = 0;
	y = 0;
	if (ft_map_total_position(map) == 1)
		parse->map_wg_player_number = 1;
	while (map[y] != NULL)
		y++;
	while (map[actual])
	{
		ft_map_check(parse, map, actual, y);
		actual++;
	}
	return (parse);
}
