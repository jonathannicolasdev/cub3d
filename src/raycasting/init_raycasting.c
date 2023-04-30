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

t_player	*init_player(double pos_x, double pos_y, double dir_x, double dir_y)
{
	t_player	*player;

	player = malloc(sizeof(*player));
	player->pos_x = pos_x;
	player->pos_y = pos_y;
	player->vector_dir_x = dir_x;
	player->vector_dir_y = dir_y;
	player->map_x = (int)pos_x;
	player->map_y = (int)pos_y;
	return (player);
}

t_camera	*init_camera(t_player *player)
{
	t_camera	*camera;

	camera = malloc(sizeof(*camera));
	if (!camera)
		return (NULL);
	camera->camera_plane_x = player->vector_dir_x * 0.66;
	camera->camera_plane_y = -(player->vector_dir_y * 0.66);
	return (camera);
}

t_ray	*init_ray(t_player *player, t_camera *camera, int x_screen)
{
	double	camera_x;
	t_ray	*ray;

	ray = malloc(sizeof(*ray));
	camera_x = 2 * x_screen / (double)screen_width - 1;
	ray->ray_dir_x = player->vector_dir_x + camera->camera_plane_x * camera_x;
	ray->ray_dir_y = player->vector_dir_y + camera->camera_plane_y * camera_x;
	ray->delta_dist_x = fabs(1/ ray->ray_dir_x);
	ray->delta_dist_y = fabs(1/ ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - player->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (player->map_x + 1.0 - player->pos_x) \
		* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - player->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (player->map_y + 1.0 - \
		player->pos_y) * ray->delta_dist_y;
	}
	return (ray);
}
