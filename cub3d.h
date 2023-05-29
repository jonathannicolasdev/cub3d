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

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx_opengl/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define BUFFER_SIZE 4096
# define SUCCESS 0
# define FAIL 1
# define FAIL_FD -1
# define FAIL_CUB -2
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define MOVE_SPEED 0.03
# define ROTATION_SPEED 0.05
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
//# define SCREEN_WIDTH 640
//# define SCREEN_HEIGHT 480
# define GREEN 0x00FF00
# define RED 0xFF0000
# define BLUE 0x0000FF
# define BLACK 0x00000

typedef struct s_img
{
	void			*img;
	int				wid;
	int				hei;
	char			*addr;
	int				bpp;
	int				len;
	int				endian;
}					t_img;

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
	double			vector_dir_x;
	double			vector_dir_y;
	double			pos_x;
	double			pos_y;
	t_camera		*camera;
}					t_player;

typedef struct s_key
{
	bool			w;
	bool			a;
	bool			s;
	bool			d;
	bool			left;
	bool			right;
}					t_key;

typedef struct s_map
{
	int				rows;
	int				columns;
	char			**map;
	int				width;
	int				height;
	t_img			img[4];
	float			player_x;
	float			player_y;
	char			*file_north;
	char			*file_south;
	char			*file_west;
	char			*file_east;
	char			*color_floor;
	char			*color_ceiling;
	char			nswe;
}					t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_player		*player;
	t_camera		*camera;
	t_map			*map;
	t_key			key;
	t_img			img;
	char			*color_floor;
	char			*color_ceiling;
}					t_game;

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
	double			perp_wall_dist;
	int				side;
	int				direction;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				line_height;
}					t_ray;

typedef struct s_color
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	blank;
}					t_color;

typedef struct s_parse
{
	int	file_north;
	int	file_south;
	int	file_west;
	int	file_east;
	int	file_floor;
	int	file_ceiling;
	int	file_wrong_line;
	int	map_wg_player;
	int	map_wg_player_number;
	int	map_wg_space;
	int map_wg_zero;
	int	map_wg_character;
	int	map_wg_corner;
}				t_parse;

typedef struct s_data
{
	char			*file_north;
	char			*file_south;
	char			*file_west;
	char			*file_east;
	char			*color_floor;
	char			*color_ceiling;
	char			**map;
}					t_data;

typedef struct tex
{
	int				x;
	int				y;
	int				tex_width;
	int				tex_height;
	double			tex_pos;
}					t_tex;

t_map				*read_map(char *filename);
t_camera			*init_camera(t_player *player);
t_player			*init_player(double pos_x, double pos_y, double dir_x,
						double dir_y);
t_ray				*init_ray(t_player *player, t_camera *camera, int x_screen);
void				perform_raycasting(t_player *player, t_game *game);
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
//int					move(t_game *game);
void				move(t_game *game);

void				draw_background(t_game *game);
int					game_loop(t_game *game);
void				reset_camera(t_player *player);
void				load_bitmap(t_game *info, int idx, char *path);
void				draw_floor(t_game *game);
void				draw_ceiling(t_game *game);

/*	[map_struct_funct.c]	- */
void				ft_map_player_position(t_map *data, char **map);
t_map				*create_map_from_data(t_data *data);

/*	[parse_step.c]	- */
int					ft_parsing_second(t_parse *parse, char **data, char **map);
int					ft_parsing(char **tab);

/*	[parse_data_start.c]	- */
int					parse_file_and_tab(char *filename, char ***tab);
int					ft_parse_file(char *filename, char ***tab_ptr);
int					ft_parse(char **argv, t_map **map);
t_data				*create_data_from_tab(char **tab);

/*	[parse_data_file.c]	- */
char				*ft_file_path(const char *line);
int					ft_check_file(char *str);
int					ft_map_lost(char c);
int					ft_file(char *str);

/*	[parse_error.c]	- */
t_parse				*ft_check_error(char **data, t_parse *parse);
t_parse				*ft_get_error(t_parse *parse, char **tab);
int					ft_error(t_parse *parse);

/*	[parse_color.c]	- */
int					validate_color_string(char *str, int i);
int					validate_rgb_color(char *str, int i);
char				*ft_file_color(char *str);
int					is_valid_character(char c);
int					is_valid_number(char *str, int i);

/*	[parse_data_init_and_free.c]	- */
t_parse	*init_struct(t_parse *parse);
t_data	*ft_free_data(t_data *data);
char	**ft_free_tab(char **tab);
void	ft_free_map(char **tab);

/*	[parse_cub.c]	- */
int					ft_fd_cub(char *file);
int					ft_cub(char *argv);

/*	[parse_map.c]	-	*/
void				ft_map_check(t_parse *parse, char **map, int actual, int y);
t_parse				*ft_map(t_parse *parse, char **map);

/*	[parse_map_corner.c] - */
int	ft_map_corner(char **map, int actual, int i);
int	ft_map_corner_top_left(char **map, int actual, int i);
int	ft_map_corner_bot_left(char **map, int actual, int i);
int	ft_map_corner_bot_rigth(char **map, int actual, int i);
int	ft_map_corner_top_rigth(char **map, int actual, int i);

/*	[parse_map_funct.c]	-	*/
int					ft_map_player(char **map, int actual, int i, int y);
int					ft_map_space(char **map, int actual, int i, int y);
int					ft_map_zero(char **map, int actual, int i, int y);
int					ft_map_char(char **map, int actual, int i);
int					ft_map_total_position(char **map);

/*	[data_to_struct.c]	- */
char				**ft_add_value_to_data(char **tab, t_parse *parse,
						char **data, int i);
t_data				*ft_add_to_data(t_data *data, char **tab, int i);
char				**ft_add_to_map(char **tab);
int					ft_space(char *str);

/*	[parse_data_print_struct.c]	- */
void				print_struct(t_parse *parse);
void				print_data(const t_data *data);

/*	[parse_data_file_utils.c] -	*/
char	ft_isalpha_or_point(const char *line);
int	ft_after_line(const char *line);

void				calculate_texture_coordinates(t_ray *ray, t_tex *tex,
						t_map *map, double *step);
void				draw_ceiling(t_game *game);
void				draw_floor(t_game *game);
void				draw_background(t_game *game);
unsigned int		convert_to_hexa(const char *rgb);
void				free_game(t_game *game);

#endif