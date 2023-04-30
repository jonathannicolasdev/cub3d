/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:05:46 by jnicolas          #+#    #+#             */
/*   Updated: 2023/04/29 19:05:47 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Raycasting goes here

#include "../../cub3d.h"

void	perform_raycasting(t_data *data)
{
	int         x;
	t_camera    *camera;

	camera = init_camera(data);
	x = 0;
	while (x < screenWidth)
	{
		perform_column_raycasting(camera, x);
	}
}