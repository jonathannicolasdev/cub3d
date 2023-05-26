/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:04:43 by jnicolas          #+#    #+#             */
/*   Updated: 2023/05/02 17:04:46 by jnicolas         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map		*map;
	t_game		*game;
	t_player	*player;
	void		*mlx;
	void		*win_ptr;
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
	win_ptr = mlx_new_window(mlx, screen_width, screen_height, "cub3d");
	player = init_player(map->player_y, map->player_x, -1, 0);
	player->camera=init_camera(player);
	game = malloc(sizeof(t_game));
	game->map = map;
	game->mlx = mlx;
	game->win = win_ptr;
	game->player = player;
	game->img.img = mlx_new_image(game->mlx, screen_width, screen_height);
	game->img.addr = mlx_get_data_addr(game->img.img, &(game->img.bpp), \
	&(game->img.len), &(game->img.endian));
	init_key_press(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, key_release, game);
	mlx_loop_hook(mlx, game_loop, game);
	mlx_loop(mlx);
	return (0);
}
