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
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*	----- PARSING DEFINE INCLUDE ----- */
# include "src/parsing/get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define BUFFER_SIZE 4096
# define SUCCESS 0
# define FAIL 1
# define FAIL_FD -1
# define FAIL_CUB -2
/*	----- PARSING DEFINE INCLUDE END ----- */


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
# define move_speed 0.03
# define rotation_speed 0.05
# define screen_width 640
# define screen_height 480
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

/*
typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}					t_map;
*/

/*	----- PARSING STRUCT MODIFY MAP ----- */
typedef struct s_map
{
	    int rows;
    int columns;
	char			**map;
	int				width;
	int				height;
    float x;
    float y;
}					t_map;
/*	----- PARSING STRUCT MODIFY MAP END ----- */

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_player		*player;
	t_camera		*camera;
	t_map			*map;
	t_key			key;
	t_img			img;
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
	double			perpWallDist;
}					t_ray;

typedef struct s_color
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	blank;
}					t_color;

/*	----- PARSING STRUCT ----- */
typedef struct	s_parse
{
	int north;
	int south;
	int west;
	int east;
	int floor;
	int ceiling;
	int map_wg_char;
	int map_end;
	int map_wall;
	int map_dup;
	int map_no_pos;
	int no_map;
	int wrong_line;

}				t_parse;

typedef struct	s_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	char	**map;
}				t_data;
/*	----- PARSING STRUCT END ----- */
/*	----- PARSING ----- */
/*	--- parse.c --- Obligatoire */
int 	ft_parse(char **argv, t_map **map);
int 	ft_parse_file(char *filename, char ***tab_ptr);
int		ft_parsing(char **tab);
t_parse	*ft_parse_map(char **map, t_parse *parse, int i, int dup);
t_parse	*ft_parse_map_continue(t_parse *parse, int dup, char *str);

/*	--- init_free.c --- Obligatoire */
t_parse	*init_struct(t_parse *parse);
char	**ft_free_tab(char **tab);
t_data	*ft_free_data(t_data *data);

/*	--- cub.c --- Obligatoire */
int		ft_cub(char *argv);
int		ft_fd_cub(char *file);

/*	--- map.c --- Obligatoire */
int		check_orientation(char *str);
int		is_non_map_char(char c);
int		ft_unwanted_character(char *str);
int		ft_wall(char *str);
int		ft_is_a_wall_around(char *str);

/*	--- add.c --- Obligatoire à modifier */
t_data	*ft_add_to_data(t_data *data, char **tab, int i);
char	**ft_add_to_map(char **tab);
char	**ft_add_value_to_data(char **tab, t_parse *parse, char **data, int i);

/*	--- error.c --- Obligatoire à modifier */
int		tinder(char *str);
int		ft_error(t_parse *parse);
t_parse	*get_error(t_parse *parse, char **tab, int i);
t_parse	*check_error(char **data, t_parse *parse);
void	print_error(t_parse *parse);

/*	--- other.c --- Obligatoire à modifier */
void	getPositionOfN(t_map *map);
int		is_double(int a);
int		check_file_readability(char *str, int i);
int		validate_color_string(char *str, int i);
int		validate_rgb_color(char *str, int i);
int		check_string_position(char *s1, char *s, char *s2);
int		ft_space(char *str);

/*	--- other_libft.c --- Obligatoire à modifier */
int		ft_pstrlen(char *str, char c);
char	*ft_pstrjoin(char *s1, char *s2);
char 	*ft_pstrdup(char *buffer, char c);
int		check_new_line(char *str, char c);
char	*ft_pstrcut(char *buffer, char c);
void    ft_pputchar(char c);
void    ft_pputstr(char *str);
int		ft_patoi(char *str);

/*	--- test_print.c --- On peu supprimer à la fin du projet - Ne pas norminette */
void    ft_all_data(t_data *data);
void	print_map(char **map);
void    ft_all_parse(t_parse *parse);
/*	----- PARSING END ----- */

t_map				*read_map(char *filename);
t_camera			*init_camera(t_player *player);
t_player			*init_player(double pos_x, double pos_y, double dir_x, \
					double dir_y);
t_ray				*init_ray(t_player *player, t_camera *camera, int x_screen);
void				perform_raycasting(t_player *player, t_game *game);
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
int					move(t_game *game);
void				draw_background(t_game	*game);
int					game_loop(t_game *game);
void				reset_camera(t_player *player);
#endif