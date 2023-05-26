#include "../../cub3d.h"

void print_data(const t_data *data)
{
    printf("file_north: %s\n", data->file_north);
    printf("file_south: %s\n", data->file_south);
    printf("file_west: %s\n", data->file_west);
    printf("file_east: %s\n", data->file_east);
    printf("color_floor: %s\n", data->color_floor);
    printf("color_ceiling: %s\n", data->color_ceiling);
}

void print_struct(t_parse *parse)
{
    printf("parse->map_wg_player = %d\n", parse->map_wg_player);
    printf("parse->map_wg_player_number = %d\n", parse->map_wg_player_number);
    printf("parse->map_wg_space = %d\n", parse->map_wg_space);
    printf("parse->map_wg_zero = %d\n", parse->map_wg_zero);
    printf("parse->map_wg_character = %d\n", parse->map_wg_character);
    printf("parse->file_north = %d\n", parse->file_north);
    printf("parse->file_south = %d\n", parse->file_south);
    printf("parse->file_west = %d\n", parse->file_west);
    printf("parse->file_east = %d\n", parse->file_east);
    printf("parse->file_floor = %d\n", parse->file_floor);
    printf("parse->file_ceiling = %d\n", parse->file_ceiling);
    printf("parse->file_wrong_line = %d\n", parse->file_wrong_line);
}