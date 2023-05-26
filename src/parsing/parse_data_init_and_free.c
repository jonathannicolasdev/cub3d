#include "../../cub3d.h"

t_parse	*init_struct(t_parse *parse)
{
	parse->map_wg_player = 0;
	parse->map_wg_player_number = 0;
	parse->map_wg_space = 0;
	parse->map_wg_zero = 0;
	parse->map_wg_character = 0;
	parse->file_north = 0;
	parse->file_south = 0;
	parse->file_west = 0;
	parse->file_east = 0;
	parse->file_floor = 0;
	parse->file_ceiling = 0;
	parse->file_wrong_line = 0;
	return (parse);
}

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
	return (tab);
}

t_data	*ft_free_data(t_data *data)
{
	free(data->file_north);
	free(data->file_south);
	free(data->file_west);
	free(data->file_east);
	free(data->color_floor);
	free(data->color_ceiling);
	data->map = ft_free_tab(data->map);
	free(data);
	return (data);
}
