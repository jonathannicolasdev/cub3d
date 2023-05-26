/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:05:46 by jnicolas          #+#    #+#             */
/*   Updated: 2023/05/25 19:07:12 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void draw_background(t_game *game)
{
	char *dst;
	int i;
	int j;

	i = 0;
	while (i < screen_width)
	{
		j = 0;
		while (j < screen_height)
		{
			dst = game->img.addr + j * game->img.len + i * (game->img.bpp / 8);
			*(unsigned int *)dst = BLACK;
			j++;
		}
		i++;
	}
}

void draw_column_color(int x, t_ray *ray, t_map *map, t_game *game)
{
	int lineHeight;
	int drawStart;
	int drawEnd;
	int color;
	int j;
	char *dst;

	lineHeight = (int)(screen_height / ray->perpWallDist);
	drawStart = -lineHeight / 2 + screen_height / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + screen_height / 2;
	if (drawEnd >= screen_height)
		drawEnd = screen_height - 1;
	if (map->map[ray->map_x][ray->map_y] == '1')
		color = RED;
	else if (map->map[ray->map_x][ray->map_y] == '2')
		color = GREEN;
	else if (map->map[ray->map_x][ray->map_y] == '3')
		color = BLUE;
	else if (map->map[ray->map_x][ray->map_y] == '4')
		color = 0xFFFFFF;
	else
		color = 0xFFFF00;
	j = drawStart;

	if (ray->side == 1)
	{
		switch (color)
		{
		case RED:
			color = 0x880000;
			break;
		case GREEN:
			color = 0x008800;
			break;
		case BLUE:
			color = 0x000088;
			break;
		case 0xFFFFFF:
			color = 0x888888;
			break;
		default:
			color = 0x888800;
		}
	}

	while (j <= drawEnd)
	{
		dst = game->img.addr + j * game->img.len + x * (game->img.bpp / 8);
		color = *(unsigned int *)(game->map->img[0].addr + (j % 64) * game->map->img[0].len + (x % 64) * (game->map->img[0].bpp / 8));

		// draw->color = *(unsigned int *)(map->imgs[draw->wall_idx].addr
		// 					+ (draw->tex.y * map->imgs[draw->wall_idx].len
		// 						+ draw->tex.x * map->imgs[draw->wall_idx].bpp / 8));

		*(unsigned int *)dst = color;
		j++;
	}
}

void calculate_column_param(t_ray *ray, t_game *game)
{

	if (ray->side == 1)
		ray->direction = (ray->step_y < 0) ? 0 : 1;
	else
		ray->direction = (ray->step_x > 0) ? 2 : 3;

	ray->lineHeight = (int)(screen_height / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + screen_height / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + screen_height / 2;
	if (ray->drawEnd >= screen_height)
		ray->drawEnd = screen_height - 1;
	if (ray->side == 0)
		ray->wallX = game->player->pos_y + ray->perpWallDist * ray->ray_dir_y;
	else
		ray->wallX = game->player->pos_x + ray->perpWallDist * ray->ray_dir_x;

	ray->wallX -= floor(ray->wallX);
}

void draw_column(int x, t_ray *ray, t_map *map, t_game *game)
{
	//int lineHeight;
	//int drawStart;
	//int drawEnd;
	int color;
	int j;
	char *dst;
	int tex_x, tex_y;
	int TEX_WID, TEX_HEI;
	//int direction = 0;
	double /*wallX,*/ step, tex_pos;

	// if (ray->side == 1)
	// 	direction = (ray->step_y < 0) ? 0 : 1;
	// else
	// 	direction = (ray->step_x > 0) ? 2 : 3;

 calculate_column_param(ray, game);

	TEX_WID = map->img->wid;
	TEX_HEI = map->img->hei;

	// lineHeight = (int)(screen_height / ray->perpWallDist);
	// drawStart = -lineHeight / 2 + screen_height / 2;
	// if (drawStart < 0)
	// 	drawStart = 0;
	// drawEnd = lineHeight / 2 + screen_height / 2;
	// if (drawEnd >= screen_height)
	// 	drawEnd = screen_height - 1;

	// 

	// if (ray->side == 0)
	// 	wallX = game->player->pos_y + ray->perpWallDist * ray->ray_dir_y;
	// else
	// 	wallX = game->player->pos_x + ray->perpWallDist * ray->ray_dir_x;


j = ray->drawStart;
	// wallX -= floor(wallX);
	tex_x = (int)(ray->wallX * (double)TEX_WID);
	step = 1.0 * TEX_HEI / ray->lineHeight;
	tex_pos = (ray->drawStart - (screen_height / 2 - ray->lineHeight / 2)) * step;

	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = TEX_WID - tex_x - 1;

	while (j <= ray->drawEnd)
	{
		tex_y = (int)tex_pos & (TEX_HEI - 1);
		tex_pos += step;
		color = *(unsigned int *)(game->map->img[ray->direction].addr + tex_y * game->map->img[ray->direction].len + tex_x * (game->map->img[ray->direction].bpp / 8));

		dst = game->img.addr + j * game->img.len + x * (game->img.bpp / 8);
		*(unsigned int *)dst = color;
		j++;
	}
}

void perform_dda(t_ray *ray, t_map *map)
{
	int hit;
	int side;

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
		if (map->map[ray->map_x][ray->map_y] != '0')
			hit = 1;
	}
	if (side == 0)
		ray->perpWallDist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perpWallDist = (ray->side_dist_y - ray->delta_dist_y);
	ray->side = side;
}

void perform_column_raycasting(t_player *player, t_camera *camera,
							   t_game *game, int x)
{
	t_ray *ray;

	ray = init_ray(player, camera, x);
	perform_dda(ray, game->map);
	draw_column(x, ray, game->map, game);
}

void perform_raycasting(t_player *player, t_game *game)
{
	int x;
	t_camera *camera;
	printf("before fail\n");

	camera = init_camera(player);
	x = 0;
	while (x < screen_width)
	{
		perform_column_raycasting(player, camera, game, x);
		x++;
	}
}
