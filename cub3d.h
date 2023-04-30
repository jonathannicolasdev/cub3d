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

# include "libft/libft.h"
# include "minilibx_opengl/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define screen_width 640
# define screenHeight 480
# define RED 0Xff0000
# define GREEN 0X454B1B
# define BLUE 0X0000FF

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	t_player		*player;
}					t_data;

typedef struct s_camera
{
	double			camera_x;
	double			camera_y;
	double			camera_dir_x;
	double			camera_dir_y;
	double			camera_plane_x;
	double			camera_plane_y;
}					t_camera;

typedef struct s_player
{
	double	vector_dir_x;
	double	vector_dir_y;
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
}	t_player;

typedef struct s_ray
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
}					t_ray;

typedef struct s_color
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	blank;
}					t_color;

typedef union u_rgb
{
	int				rgb;
	t_color			rgbs;
}					t_rgb;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}					t_map;

t_map				*read_map(char *filename);
t_camera			*init_camera(t_player *player);

#endif
