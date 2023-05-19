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
	//if (game->map->map[(int)game->player->pos_y][(int)x] != '1')
	game->player->pos_x = x;
	//if (game->map->map[(int)y][(int)game->player->pos_x] != '1')
	game->player->pos_y = y;
}

void	move_horizontal(t_game *game, int direction)
{
	double	x;
	double	y;

	//printf("before update horizontal\n");
	x = game->player->pos_x + direction * game->player->vector_dir_y
		//game->camera->camera_dir_x
			* move_speed;
	//printf("player posx %f camera dirx %f\n", game->player->pos_x,
	//game->camera->camera_dir_x);
	y = game->player->pos_y - direction * game->player->vector_dir_x
		//* game->camera->camera_dir_y
			* move_speed;
	//printf("before update y\n");
	//if (game->map->map[(int)game->player->pos_y][(int)x] != '1')
	game->player->pos_x = x;
	//if (game->map->map[(int)y][(int)game->player->pos_x] != '1')
	game->player->pos_y = y;
}
/*
void	rotate(t_player *player, int direction)
{
	double		vector_dir_x_old;
	double		camera_plane_x_old;
	t_camera	*camera;

	reset_camera(player);
	printf("before it segs");
	camera = player->camera;
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
*/

void	rotate_right(t_player *player)
{
	double		vector_dir_x_old;
	double		camera_plane_x_old;
	t_camera	*camera;

	//reset_camera(player);
	printf("before it segs");
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

	//reset_camera(player);
	printf("before it segs");
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
		//printf("key is w %f %f\n", game->player->pos_x, game->player->pos_y);
		move_vertical(game, 1);
		return (1);
	}
	else if (game->key.s == true)
	{
		//printf("key is s %f %f\n", game->player->pos_x, game->player->pos_y);
		move_vertical(game, -1);
		return (1);
	}
	else if (game->key.a == true)
	{
		printf("key is a %f %f\n", game->player->pos_x, game->player->pos_y);
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
		//rotate(game->player, -1);
		return (1);
	}
	else if (game->key.right == true)
	{
		rotate_right(game->player);
		//rotate(game->player, 1);
		return (1);
	}
	else
	{
		return (0);
	}
}
