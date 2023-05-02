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
	t_map		*map;
	//t_player	*player;
	printf("hello");
	map = read_map("");
	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, screen_width, screen_height, "cub3d");
	t_player	*player = init_player(10, 12, -1, 0);
	perform_raycasting(player, map);
	mlx_loop(mlx);
	return (0);
}