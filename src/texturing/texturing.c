#include "../../cub3d.h"

void	load_bitmap(t_game *info, int idx, char *path)
{
	t_img	*simg;

	simg = &(info->map->img[idx]);
	printf("%s\n",path);
	simg->img = mlx_xpm_file_to_image(info->mlx, path, &(simg->wid)
		, &(simg->hei));
	simg->addr = mlx_get_data_addr(simg->img, &(simg->bpp), &(simg->len)
		, &(simg->endian));
}
