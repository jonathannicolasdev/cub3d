/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:05:46 by jnicolas          #+#    #+#             */
/*   Updated: 2023/05/28 19:57:43 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	calculate_column_param(t_ray *ray, t_game *game)
{
	ray->direction = (!ray->side) * (2 + (ray->step_x > 0)) + \
	ray->side * (ray->step_y < 0);
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = game->player->pos_y + ray->perp_wall_dist
			* ray->ray_dir_y;
	else
		ray->wall_x = game->player->pos_x + ray->perp_wall_dist
			* ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	draw_column(int x, t_ray *ray, t_map *map, t_game *game)
{
	t_tex	*tex;
	int		color;
	int		j;
	char	*dst;
	double	step;

	tex = malloc(sizeof(*tex));
	calculate_column_param(ray, game);
	calculate_texture_coordinates(ray, tex, map, &step);
	j = ray->draw_start;
	while (j <= ray->draw_end)
	{
		tex->y = (int)tex->tex_pos & (tex->tex_height - 1);
		tex->tex_pos += step;
		color = *(unsigned int *)(game->map->img[ray->direction].addr + tex->y
				* game->map->img[ray->direction].len + tex->x
				* (game->map->img[ray->direction].bpp / 8));
		dst = game->img.addr + j * game->img.len + x * (game->img.bpp / 8);
		*(unsigned int *)dst = color;
		j++;
	}
	free(tex);
}

void	perform_dda(t_ray *ray, t_map *map)
{
	int		hit;
	int		side;
	char	current_tile;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			side = 1;
		}
		current_tile = map->map[ray->map_x][ray->map_y];
		if (current_tile != '0' && current_tile != 'N' && current_tile != 'S' \
				&& current_tile != 'E' && current_tile != 'W')
			hit = 1;
	}
	set_side_perpwalldist(ray, &side);
}

void	perform_column_raycasting(t_player *player, t_camera *camera,
		t_game *game, int x)
{
	t_ray	*ray;

	ray = init_ray(player, camera, x);
	perform_dda(ray, game->map);
	draw_column(x, ray, game->map, game);
	free(ray);
}

void	perform_raycasting(t_player *player, t_game *game)
{
	int			x;
	t_camera	*camera;

	camera = init_camera(player);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		perform_column_raycasting(player, camera, game, x);
		x++;
	}
	free(camera);
}
