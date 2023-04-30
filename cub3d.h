/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnicolas <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:48:42 by jnicolas          #+#    #+#             */
/*   Updated: 2022/10/25 17:10:44 by jnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx_opengl/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <string.h>
# include <math.h>

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2


#define screenWidth 640
#define screenHeight 480
#define RED 0Xff0000
#define GREEN 0X454B1B
#define BLUE 0X0000FF

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	pos_x;
	double	pos_y;
	double	player_dir_x;
	double	player_dir_y;
}	t_data;

typedef struct s_camera {
	double	camera_x;
	double	camera_y;
	double	camera_dir_x;
	double	camera_dir_y;
	double	camera_plane_x;
	double	camera_plane_y;
} t_camera


typedef struct s_color
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	blank;
}	t_color;

typedef union u_rgb
{
	int		rgb;
	t_color	rgbs;
}	t_rgb;

typedef struct s_map {
	char	**map;
	int		width;
	int		height;
}	t_map;

t_map		*read_map(char *filename);
t_camera	*init_camera(t_data *data)

#endif
