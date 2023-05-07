/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:19:21 by jnicolas          #+#    #+#             */
/*   Updated: 2023/05/02 16:19:24 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	game_loop(t_game *game)
{
	if (move(game))
	{
		draw_background(game);
		perform_raycasting(game->player, game);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	}
	return (0);
}
