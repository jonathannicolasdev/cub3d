/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_print_struct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:52:58 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/26 16:57:02 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	print_data(const t_data *data)
{
	printf("file_north: %s\n", data->file_north);
	printf("file_south: %s\n", data->file_south);
	printf("file_west: %s\n", data->file_west);
	printf("file_east: %s\n", data->file_east);
	printf("color_floor: %s\n", data->color_floor);
	printf("color_ceiling: %s\n", data->color_ceiling);
}

int	ft_i(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == 'C' || str[i] == 'F')
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_skip(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f' || c == 32 || c == 9)
		return (1);
	return (0);
}
