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

t_game	*init_game(void *mlx, t_map *map)
{
	t_game		*game;
	t_player	*player;

	game = malloc(sizeof(t_game));
	//map = read_map("");
	game->map = map;
	game->mlx = mlx;
	player = init_player(map->player_y, map->player_x, -1, 0);
	game->player = player;
	game->player->camera = init_camera(player);
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &(game->img.bpp), &(game->img.len), &(game->img.endian));
	load_bitmap(game, 0, "./bitmaps/north_test.xpm");
	load_bitmap(game, 1, "./bitmaps/south_test.xpm");
	load_bitmap(game, 2, "./bitmaps/east_test.xpm");
	load_bitmap(game, 3, "./bitmaps/west_test.xpm");
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	void	*mlx;
	void	*win_ptr;
	t_map	*map;

	if (argc == 1)
	{
		printf("Error! *main return*\n");
		return (1);
	}
	if (ft_parse(argv, &map) != 0)
	{
		printf("Error! *main return*\n");
		return (1);
	}
	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game = init_game(mlx, map);
	game->win = win_ptr;
	init_key_press(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, key_release, game);
	mlx_loop_hook(mlx, game_loop, game);
	mlx_loop(mlx);
	return (0);
}
