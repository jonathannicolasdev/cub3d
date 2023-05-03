/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:06:06 by jnicolas          #+#    #+#             */
/*   Updated: 2023/05/02 17:06:08 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_vertical(t_game *game, int direction)
{
	double	x;
	double	y;

	x = game->player->pos_x + direction * game->player->vector_dir_x
		* move_speed;
	y = game->player->pos_y + direction * game->player->vector_dir_y
		* move_speed;
	if (game->map->map[(int)game->player->pos_y][(int)x] != '1')
		game->player->pos_x = x;
	if (game->map->map[(int)y][(int)game->player->pos_x] != '1')
		game->player->pos_y = y;
}

void	move_horizontal(t_game *game, int direction)
{
	double	x;
	double	y;

	x = game->player->pos_x + direction * game->camera->camera_dir_x
		* move_speed;
	y = game->player->pos_y + direction * game->camera->camera_dir_y
		* move_speed;
	if (game->map->map[(int)game->player->pos_y][(int)x] != '1')
		game->player->pos_x = x;
	if (game->map->map[(int)y][(int)game->player->pos_x] != '1')
		game->player->pos_y = y;
}

void	rotate(t_player *player, t_camera *camera, int direction)
{
	double	vector_dir_x_old;
	double	camera_plane_x_old;

	vector_dir_x_old = player->vector_dir_x;
	player->vector_dir_x = player->vector_dir_x * cos(direction
			* rotation_speed) - player->vector_dir_y * sin(direction
			* rotation_speed);
	player->vector_dir_y = vector_dir_x_old * sin(direction * rotation_speed)
		+ player->vector_dir_y * cos(direction * rotation_speed);
	camera_plane_x_old = camera->camera_plane_y;
	camera->camera_plane_x = camera->camera_plane_x * cos(direction
			* rotation_speed) - camera->camera_plane_y * sin(direction
			* rotation_speed);
	camera->camera_plane_y = camera_plane_x_old * sin(direction
			* rotation_speed) + camera->camera_plane_y * cos(direction
			* rotation_speed);
}

void	move(t_game *game)
{
	if (game->key.w == true)
		move_vertical(game, 1);
	else if (game->key.s == true)
		move_vertical(game, -1);
	else if (game->key.a == true)
		move_horizontal(game, -1);
	else if (game->key.d == true)
		move_horizontal(game, 1);
	else if (game->key.left == true)
		rotate(game->player, game->camera, -1);
	else if (game->key.right == true)
		rotate(game->player, game->camera, 1);
}
