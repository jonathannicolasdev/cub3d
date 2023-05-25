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

void	draw_background(t_game *game)
{
	char	*dst;
	int		i;
	int		j;

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

void	draw_column(int x, t_ray *ray, t_map *map, t_game *game)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		j;
	char	*dst;

	line_height = (int)(screen_height / ray->perp_wall_dist);
	draw_start = -line_height / 2 + screen_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + screen_height / 2;
	if (draw_end >= screen_height)
		draw_end = screen_height - 1;
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
	j = draw_start;
	if (ray->side == 1)
	{
		switch (color)
		{
		case RED:
			color = 0x880000;
			break ;
		case GREEN:
			color = 0x008800;
			break ;
		case BLUE:
			color = 0x000088;
			break ;
		case 0xFFFFFF:
			color = 0x888888;
			break ;
		default:
			color = 0x888800;
		}
	}
	while (j <= draw_end)
	{
		dst = game->img.addr + j * game->img.len + x * (game->img.bpp / 8);
		*(unsigned int *)dst = color;
		j++;
	}
}

void	perform_dda(t_ray *ray, t_map *map)
{
	int	hit;
	int	side;

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
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->side = side;
}

void	perform_column_raycasting(t_player *player, t_camera *camera,
		t_game *game, int x)
{
	t_ray	*ray;

	ray = init_ray(player, camera, x);
	perform_dda(ray, game->map);
	draw_column(x, ray, game->map, game);
}

void	perform_raycasting(t_player *player, t_game *game)
{
	int			x;
	t_camera	*camera;

	camera = init_camera(player);
	x = 0;
	while (x < screen_width)
	{
		perform_column_raycasting(player, camera, game, x);
		x++;
	}
}
