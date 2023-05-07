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
# include <stdbool.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT 17
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define move_speed 0.03
# define rotation_speed 0.05


# define screen_width 640
# define screen_height 480
# define GREEN 0x00FF00
# define RED 0xFF0000
# define BLUE 0x0000FF

typedef struct	s_img
{
	void		*img;
	int			wid;
	int			hei;

	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}	t_img;

typedef struct s_player
{
	double			vector_dir_x;
	double			vector_dir_y;
	double			pos_x;
	double			pos_y;
}					t_player;

typedef struct s_key
{
	bool		w;
	bool		a;
	bool		s;
	bool		d;

	bool		left;
	bool		right;
}	t_key;

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

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}					t_map;

typedef struct s_camera
{
	double			camera_x;
	double			camera_y;
	double			camera_dir_x;
	double			camera_dir_y;
	double			camera_plane_x;
	double			camera_plane_y;
}					t_camera;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_player		*player;
	t_camera		*camera;
	t_map			*map;
	t_key			key;
	t_img		img;
}	t_game;

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
	int				map_x;
	int				map_y;
	double			perpWallDist;
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



t_map				*read_map(char *filename);
t_camera			*init_camera(t_player *player);
t_player			*init_player(double pos_x, double pos_y, double dir_x,
						double dir_y);
t_ray				*init_ray(t_player *player, t_camera *camera, int x_screen);
void				perform_raycasting(t_player *player, t_game *game);
//void				perform_raycasting(t_player *player, t_map *map);
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
int					game_loop(t_game *game);
void				move(t_game *game);

#endif