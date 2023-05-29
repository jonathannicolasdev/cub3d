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

void	free_img(t_img *image, t_game *game)
{
	if (image != NULL)
	{
		if (image->img != NULL)
			mlx_destroy_image(game, image->img);
		free(image);
	}
}
