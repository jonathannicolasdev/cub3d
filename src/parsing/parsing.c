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
	parse = get_error(parse, tab, 0);
	data = ft_add_value_to_data(tab, parse, data, 0);
	map = ft_add_to_map(tab);
	return (ft_parsing_second(parse, data, map));
}
