/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_init_and_free.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:54:21 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/26 16:54:22 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	parse->map_wg_corner = 0;
	parse->file_too_much = 0;
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

void	ft_free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}
