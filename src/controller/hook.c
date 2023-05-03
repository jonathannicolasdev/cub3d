/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:19:07 by jnicolas          #+#    #+#             */
/*   Updated: 2023/05/02 16:19:09 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key.w = true;
	else if (keycode == KEY_A)
		game->key.a = true;
	else if (keycode == KEY_S)
		game->key.s = true;
	else if (keycode == KEY_D)
		game->key.d = true;
	else if (keycode == KEY_LEFT)
		game->key.left = true;
	else if (keycode == KEY_RIGHT)
		game->key.right = true;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key.w = false;
	else if (keycode == KEY_A)
		game->key.a = false;
	else if (keycode == KEY_S)
		game->key.s = false;
	else if (keycode == KEY_D)
		game->key.d = false;
	else if (keycode == KEY_LEFT)
		game->key.left = false;
	else if (keycode == KEY_RIGHT)
		game->key.right = false;
	return (0);
}
