/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:57:52 by jnicolas          #+#    #+#             */
/*   Updated: 2023/05/28 19:57:57 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

unsigned int	convert_to_hexa(const char *rgb)
{
	char			*token;
	char			*rgb_copy;
	unsigned int	hex_value;
	t_rgb			color;

	rgb_copy = ft_strdup(rgb);
	token = ft_strtok(rgb_copy, ",");
	color.r = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	color.g = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	color.b = ft_atoi(token);
	free(rgb_copy);
	hex_value = ((color.r & 0xFF) << 16) | \
	((color.g & 0xFF) << 8) | (color.b & 0xFF);
	return (hex_value);
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

void	calculate_texture_coordinates(t_ray *ray, t_tex *tex, t_map *map,
		double *step)
{
	tex->tex_width = map->img->wid;
	tex->tex_height = map->img->hei;
	tex->x = (int)(ray->wall_x * (double)tex->tex_width);
	*step = 1.0 * tex->tex_height / ray->line_height;
	tex->tex_pos = (ray->draw_start - (SCREEN_HEIGHT / 2 - ray->line_height
				/ 2)) * (*step);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		tex->x = tex->tex_width - tex->x - 1;
}
