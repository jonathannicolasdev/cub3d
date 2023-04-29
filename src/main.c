#include "../cub3d.h"
#include <math.h>
#include <string.h>

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
	printf("hello");
	// start here

	double position_x = 22, position_y = 12;      // x and y start position
	double dirX = -1, dirY = 0;       // initial direction vector
	double planeX = 0, planeY = 0.66;
	// the 2d raycaster version of camera plane
	double cameraX, rayDirX, rayDirY, deltaDistX, deltaDistY;
	void *mlx;
	mlx_new_window(mlx, screenWidth, screenHeight, "cub3d");
	// Camera *camera =init_camera();
	// game loop
	for (int x = 0; x < screenWidth; x++)
	{
		// calculate ray position and direction
		cameraX = 2 * x / (double)screenWidth - 1;
		// x-coordinate in camera space
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
	}

	return (0);
}