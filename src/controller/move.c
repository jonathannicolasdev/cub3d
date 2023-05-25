/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:06:06 by jnicolas          #+#    #+#             */
/*   Updated: 2023/05/25 18:05:28 by jnicolas         ###   ########.fr       */
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
	game->player->pos_x = x;
	game->player->pos_y = y;
}

void	move_horizontal(t_game *game, int direction)
{
	double	x;
	double	y;

	x = game->player->pos_x + direction * game->player->vector_dir_y
		* move_speed;
	y = game->player->pos_y - direction * game->player->vector_dir_x
		* move_speed;
	game->player->pos_x = x;
	game->player->pos_y = y;
}

void	rotate_right(t_player *player)
{
	double		vector_dir_x_old;
	double		camera_plane_x_old;
	t_camera	*camera;

	camera = player->camera;
	vector_dir_x_old = player->vector_dir_x;
	player->vector_dir_x = player->vector_dir_x * cos(-rotation_speed)
		- player->vector_dir_y * sin(-rotation_speed);
	player->vector_dir_y = vector_dir_x_old * sin(-rotation_speed)
		+ player->vector_dir_y * cos(-rotation_speed);
	camera_plane_x_old = camera->camera_plane_x;
	camera->camera_plane_x = camera->camera_plane_x * cos(-rotation_speed)
		- camera->camera_plane_y * sin(-rotation_speed);
	camera->camera_plane_y = camera_plane_x_old * sin(-rotation_speed)
		+ camera->camera_plane_y * cos(-rotation_speed);
}

void	rotate_left(t_player *player)
{
	double		vector_dir_x_old;
	double		camera_plane_x_old;
	t_camera	*camera;

	camera = player->camera;
	vector_dir_x_old = player->vector_dir_x;
	player->vector_dir_x = player->vector_dir_x * cos(rotation_speed)
		- player->vector_dir_y * sin(rotation_speed);
	player->vector_dir_y = vector_dir_x_old * sin(rotation_speed)
		+ player->vector_dir_y * cos(rotation_speed);
	camera_plane_x_old = camera->camera_plane_x;
	camera->camera_plane_x = camera->camera_plane_x * cos(rotation_speed)
		- camera->camera_plane_y * sin(rotation_speed);
	camera->camera_plane_y = camera_plane_x_old * sin(rotation_speed)
		+ camera->camera_plane_y * cos(rotation_speed);
}

int	move(t_game *game)
{
	if (game->key.w == true)
	{
		move_vertical(game, 1);
		return (1);
	}
	else if (game->key.s == true)
	{
		move_vertical(game, -1);
		return (1);
	}
	else if (game->key.a == true)
	{
		move_horizontal(game, -1);
		return (1);
	}
	else if (game->key.d == true)
	{
		move_horizontal(game, 1);
		return (1);
	}
	else if (game->key.left == true)
	{
		rotate_left(game->player);
		return (1);
	}
	else if (game->key.right == true)
	{
		rotate_right(game->player);
		return (1);
	}
	else
		return (0);
}
