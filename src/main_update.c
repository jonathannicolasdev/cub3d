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
	// start here

	double posX = 10, posY = 12;                // x and y start position
	double player_dir_x = -1, player_dir_y = 0; // initial direction vector
	double plane_x = 0, plane_y = 0.66;        
		// the 2d raycaster version of camera plane
	double cameraX, rayDirX, rayDirY, deltaDistX, deltaDistY;
	void *mlx;

	t_map *map = read_map("");
	mlx = mlx_init();

	void *win_ptr = mlx_new_window(mlx, screenWidth, screenHeight, "cub3d");

	// Camera *camera =init_camera();

	// game loop

	for (int x = 0; x < screenWidth; x++)
	{
		// calculate ray position and direction
		cameraX = 2 * x / (double)screenWidth - 1;
			// x-coordinate in camera space
		plane_x = player_dir_y * 0.66;
		plane_y = -player_dir_x * 0.66;
		rayDirX = player_dir_x + plane_x * cameraX;
		rayDirY = player_dir_y + plane_y * cameraX;
		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);

		// which box of the map we're in
		int mapX = (int)posX;
		int mapY = (int)posY;

		// length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		// length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		// what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; // was there a wall hit?
		int side;    // was a NS or a EW wall hit?

		// calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		// perform DDA
		while (hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
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
			// Check if ray has hit a wall
			if (map->map[mapX][mapY] != '0')
				hit = 1;
		}

		double perpWallDist;
		// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		// Calculate height of line to draw on screen
		int lineHeight = (int)(screenHeight / perpWallDist);

		// calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;

		// choose wall color
		int color;
		switch (map->map[mapX][mapY])
		{
		case '1':
		case '2':
			color = RED;
			break ; // red
		case '3':
		case '4':
			color = GREEN;
			break ; // green
		case '5':
		case '6':
			color = BLUE;
			break ; // blue
		case '7':
			color = 0xFFFF00;
			break ; // white
		default:
			color = 0xFFFFFF;
			break ; // yellow
		}
		for (int j = drawStart; j <= drawEnd; j++)
			mlx_pixel_put(mlx, win_ptr, x, j, color);
	}

	mlx_loop(mlx);

	return (0);
}