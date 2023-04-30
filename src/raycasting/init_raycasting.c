/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:05:37 by jnicolas          #+#    #+#             */
/*   Updated: 2023/04/29 19:05:39 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_camera	*init_camera(t_data *data)
{
	t_camera	*camera;

	camera = malloc(sizeof(*camera));
	if (!camera)
		return (NULL);
	camera->camera_plane_x = data->player_dir_y * 0.66;
	camera->camera_plane_y = -(data->player_dir_x * 0.66);
	camera->camera_dir_x = data->player_dir_x;
	camera->camera_dir_y = data->player_dir_y;
	camera->camera_x = data->pos_x;
	camera->camera_y = data->pos_y;
}
