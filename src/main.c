/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:04:43 by jnicolas          #+#    #+#             */
/*   Updated: 2023/05/24 20:42:34 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>
#include <string.h>

t_map	*read_map(char *filename)
{
	t_map	*m;
	int		i;

	(void)filename;
	m = malloc(sizeof(t_map));
	m->width = 24;
	m->height = 24;
	m->map = malloc(sizeof(char *) * m->height);
	i = 0;
	m->map[i++] = strdup("111111111111111111111111");
	m->map[i++] = strdup("100000000000000000000001");
	m->map[i++] = strdup("100000000000000000000001");
	m->map[i++] = strdup("100000000000000000000001");
	m->map[i++] = strdup("100000222220000303030001");
	m->map[i++] = strdup("100000200020000000000001");
	m->map[i++] = strdup("100000200020000300030001");
	m->map[i++] = strdup("100000200020000000000001");
	m->map[i++] = strdup("100000220220000303030001");
	m->map[i++] = strdup("100000000000000000000001");
	m->map[i++] = strdup("100000000000000000000001");
	m->map[i++] = strdup("100000000000000000000001");
	m->map[i++] = strdup("100000000000000000000001");
	m->map[i++] = strdup("100000000000000000000001");
	m->map[i++] = strdup("100000000000000000000001");
	m->map[i++] = strdup("100000000000000000000001");
	m->map[i++] = strdup("144444444000000000000001");
	m->map[i++] = strdup("140400004000000000000001");
	m->map[i++] = strdup("140000504000000000000001");
	m->map[i++] = strdup("140400004000000000000001");
	m->map[i++] = strdup("140444444000000000000001");
	m->map[i++] = strdup("140000000000000000000001");
	m->map[i++] = strdup("144444444000000000000001");
	m->map[i++] = strdup("111111111111111111111111");
	return (m);
}

int	init_key_press(t_game *game)
{
	game->key.w = false;
	game->key.a = false;
	game->key.s = false;
	game->key.d = false;
	game->key.left = false;
	game->key.right = false;
	return (0);
}

t_game	*init_game(void *mlx)
{
	t_game		*game;
	t_map		*map;
	t_player	*player;

	game = malloc(sizeof(t_game));
	map = read_map("");
	game->map = map;
	game->mlx = mlx;
	player = init_player(10, 12, -1, 0);
	game->player = player;
	game->player->camera = init_camera(player);
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &(game->img.bpp),
			&(game->img.len), &(game->img.endian));
	load_bitmap(game, 0, "./bitmaps/north_test.xpm");
	load_bitmap(game, 1, "./bitmaps/south_test.xpm");
	load_bitmap(game, 2, "./bitmaps/east_test.xpm");
	load_bitmap(game, 3, "./bitmaps/west_test.xpm");
	return (game);
}

int	main(void)
{
	t_game	*game;
	void	*mlx;
	void	*win_ptr;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game = init_game(mlx);
	game->win = win_ptr;
	init_key_press(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, key_release, game);
	mlx_loop_hook(mlx, game_loop, game);
	mlx_loop(mlx);
	return (0);
}
