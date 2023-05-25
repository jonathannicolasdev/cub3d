/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:03:17 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/22 17:03:21 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_parse	*init_struct(t_parse *parse)
{
	parse->north = 0;
	parse->south = 0;
	parse->west = 0;
	parse->east = 0;
	parse->floor = 0;
	parse->ceiling = 0;
	parse->map_wg_char = 0;
	parse->map_end = 0;
	parse->map_wall = 0;
	parse->map_dup = 0;
	parse->map_no_pos = 0;
	parse->no_map = 0;
	parse->wrong_line = 0;
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
	{
		free(tab[i++]);
	}
	free(tab);
	return (tab);
}

t_data	*ft_free_data(t_data *data)
{
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->east);
	free(data->floor);
	free(data->ceiling);
	data->map = ft_free_tab(data->map);
	free(data);
	return (data);
}
