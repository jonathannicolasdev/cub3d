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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	convert_to_hexa(const char *rgb)
{
	char			*token;
	char			*rgbCopy;
	unsigned int	hexValue;

	rgbCopy = ft_strdup(rgb);
	unsigned int r, g, b;
	token = ft_strtok(rgbCopy, ",");
	r = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	g = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	b = ft_atoi(token);
	free(rgbCopy);
	hexValue = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
	return (hexValue);
}

void	draw_background(t_game *game)
{
	unsigned int	*sss;
	int				i;
	int				j;
	char			*dst;

	sss = malloc(sizeof(unsigned int));
	if (sss == NULL)
	{
		return ;
	}
	*sss = convert_to_hexa(game->color_floor);
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT)
		{
			dst = game->img.addr + j * game->img.len + i * (game->img.bpp / 8);
			*(unsigned int *)dst = *sss;
			j++;
		}
		i++;
	}
	free(sss);
}

void	draw_floor(t_game *game)
{
	unsigned int	*sss;
	int				i;
	int				j;
	char			*dst;

	sss = malloc(sizeof(unsigned int));
	if (sss == NULL)
	{
		return ;
	}
	*sss = convert_to_hexa(game->color_floor);
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT / 2;
		while (j < SCREEN_HEIGHT)
		{
			dst = game->img.addr + j * game->img.len + i * (game->img.bpp / 8);
			*(unsigned int *)dst = *sss;
			j++;
		}
		i++;
	}
	free(sss);
}

void	draw_ceiling(t_game *game)
{
	unsigned int	*sss;
	int				i;
	int				j;
	char			*dst;

	sss = malloc(sizeof(unsigned int));
	if (sss == NULL)
	{
		return ;
	}
	*sss = convert_to_hexa(game->color_ceiling);
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT / 2)
		{
			dst = game->img.addr + j * game->img.len + i * (game->img.bpp / 8);
			*(unsigned int *)dst = *sss;
			j++;
		}
		i++;
	}
	free(sss);
}

/*
void	draw_background(t_game *game)
{
	char	*dst;
	int		i;
	int		j;

	
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT)
		{
			dst = game->img.addr + j * game->img.len + i * (game->img.bpp / 8);
			*(unsigned int *)dst = BLACK;
			j++;
		}
		i++;
	}
}
*/

void	calculate_column_param(t_ray *ray, t_game *game)
{
	if (ray->side == 1)
		ray->direction = (ray->step_y < 0) ? 0 : 1;
	else
		ray->direction = (ray->step_x > 0) ? 2 : 3;
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
	int		color;
	int		j;
	char	*dst;

	int tex_x, tex_y;
	int TEX_WID, TEX_HEI;
	double step, tex_pos;
	calculate_column_param(ray, game);
	TEX_WID = map->img->wid;
	TEX_HEI = map->img->hei;
	j = ray->draw_start;
	tex_x = (int)(ray->wall_x * (double)TEX_WID);
	step = 1.0 * TEX_HEI / ray->line_height;
	tex_pos = (ray->draw_start - (SCREEN_HEIGHT / 2 - ray->line_height / 2))
		* step;
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		tex_x = TEX_WID - tex_x - 1;
	while (j <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEI - 1);
		tex_pos += step;
		color = *(unsigned int *)(game->map->img[ray->direction].addr + tex_y
				* game->map->img[ray->direction].len + tex_x
				* (game->map->img[ray->direction].bpp / 8));
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
		if (map->map[ray->map_x][ray->map_y] != '0' && map->map[ray->map_x][ray->map_y] != 'N'
			 && map->map[ray->map_x][ray->map_y] != 'S'  && map->map[ray->map_x][ray->map_y] != 'E'
			  && map->map[ray->map_x][ray->map_y] != 'W')
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
	while (x < SCREEN_WIDTH)
	{
		perform_column_raycasting(player, camera, game, x);
		x++;
	}
}
