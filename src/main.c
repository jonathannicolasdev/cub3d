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

int	ft_pos_ns(char pos)
{
	if (pos == 'N')
		return (-1);
	if (pos == 'S')
		return (1);
	return (0);
}

int	ft_pos_we(char pos)
{
	if (pos == 'W')
		return (-1);
	if (pos == 'E')
		return (1);
	return (0);
}

t_game	*init_game(void *mlx, t_map *map)
{
	t_game		*game;
	t_player	*player;

	game = malloc(sizeof(t_game));
	game->map = map;
	game->mlx = mlx;
	player = init_player(map->player_y, map->player_x, ft_pos_ns(map->nswe), ft_pos_we(map->nswe));
	game->player = player;
	game->player->camera = init_camera(player);
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &(game->img.bpp), &(game->img.len), &(game->img.endian));
	load_bitmap(game, 0, map->file_north);
	load_bitmap(game, 1, map->file_south);
	load_bitmap(game, 2, map->file_east);
	load_bitmap(game, 3, map->file_west);
	return (game);
}

void free_img(t_img *image, t_game *game) {
    if (image != NULL) {
        if (image->img != NULL)
            mlx_destroy_image(game, image->img);
        free(image);
    }
}

void free_game(t_game *game)
{
 //   free_img(&game->img, game->mlx);
    free(game->player);
    mlx_destroy_image(game->mlx, game->img.img);
    free(game->map->color_ceiling);
    free(game->map->color_floor);
    free(game->map->file_east);
    free(game->map->file_north);
    free(game->map->file_south);
    free(game->map->file_west);
    ft_free_map(game->map->map);
    free(game);
//	free(&game->img);
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
}

void map_to_game(t_map *map, t_game *game)
{
    game->color_ceiling = map->color_ceiling;
    game->color_floor = map->color_floor;
}

int close_window(t_game *game)
{
	free_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	void	*mlx;
	void	*win_ptr;
	t_map	*map;

	if (argc == 1)
	{
		printf("Error\nArgument problem\n");
		return (1);
	}
	if (ft_parse(argv, &map) != 0)
	{
		return (1);
	}
	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game = init_game(mlx, map);
	game->win = win_ptr;
	init_key_press(game);
	map_to_game(map, game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, key_release, game);
	mlx_loop_hook(mlx, game_loop, game);
	mlx_loop(mlx);
	return (0);
}
