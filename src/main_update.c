/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:30:13 by jnicolas          #+#    #+#             */
/*   Updated: 2023/04/28 22:31:26 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	*read_map(char *filename)
{
	t_map	*m;
	int		i;

	m = malloc(sizeof(t_map));
	m->width = 24;
	m->height = 24;
	m->map = malloc(sizeof(char *) * m->height);
	i = 0;
	m->map[i++] = strdup("444444444444444477777777");
	m->map[i++] = strdup("400000000000000070000007");
	m->map[i++] = strdup("401000000000000000000007");
	m->map[i++] = strdup("402000000000000000000007");
	m->map[i++] = strdup("403000000000000070000007");
	m->map[i++] = strdup("404000055555555577077777");
	m->map[i++] = strdup("405000050505050570007771");
	m->map[i++] = strdup("406000050000000570000008");
	m->map[i++] = strdup("407000000000000000007771");
	m->map[i++] = strdup("408000050000000570000008");
	m->map[i++] = strdup("400000050000000570007771");
	m->map[i++] = strdup("400000055550555577777771");
	m->map[i++] = strdup("666666666660666666666666");
	m->map[i++] = strdup("800000000000000000000004");
	m->map[i++] = strdup("666666066660666666666666");
	m->map[i++] = strdup("444444044460622222223333");
	m->map[i++] = strdup("400000000460620000020002");
	m->map[i++] = strdup("400000000000620050020002");
	m->map[i++] = strdup("400000000460620000022022");
	m->map[i++] = strdup("406060000460000050000002");
	m->map[i++] = strdup("400500000460620000022022");
	m->map[i++] = strdup("406060000460620050020002");
	m->map[i++] = strdup("400000000460620000020002");
	m->map[i++] = strdup("444444444411122222233333");
	return (m);
}

int	main(void)
{
	int		x;
	double	position_x;
	double	position_y;
	double	player_dir_x;
	double	player_dir_y;
	double	plane_x;
	double	plane_y;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	void	*mlx;
	void	*win_ptr;
	t_map	*map;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	perpWallDist;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	int		j;

	map = read_map("");
	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, screenWidth, screenHeight, "cub3d");
	position_x = 10;
	position_y = 12;
	player_dir_x = -1;
	player_dir_y = 0;
	plane_x = 0;
	plane_y = 0.66;
	x = 0;
	while (x < screenWidth)
	{
		cameraX = 2 * x / (double)screenWidth - 1;
		plane_x = player_dir_y * 0.66;
		plane_y = -player_dir_x * 0.66;
		rayDirX = player_dir_x + plane_x * cameraX;
		rayDirY = player_dir_y + plane_y * cameraX;
		mapX = (int)position_x;
		mapY = (int)position_y;
		deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		hit = 0;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (position_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - position_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (position_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - position_y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (map->map[mapX][mapY] != '0')
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		lineHeight = (int)(screenHeight / perpWallDist);
		drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		if (map->map[mapX][mapY] == '1' || map->map[mapX][mapY] == '2')
			color = RED ;
		else if (map->map[mapX][mapY] == '3' || map->map[mapX][mapY] == '4')
			color = BLUE;
		else if (map->map[mapX][mapY] == '5' || map->map[mapX][mapY] == '6')
			color = BLUE;
		else
			color = 0xFFFFFF;
		j = drawStart;
		while (j <= drawEnd)
			mlx_pixel_put(mlx, win_ptr, x, j++, color);
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
