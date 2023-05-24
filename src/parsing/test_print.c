#include "../../cub3d.h"

void    ft_all_data(t_data *data)
{
    printf("\nTous ce que data contient:\n");
    printf("data->north = %s\n", data->north);
    printf("data->south = %s\n", data->south);
    printf("data->west = %s\n", data->west);
    printf("data->east = %s\n", data->east);
    printf("data->floor = %s\n", data->floor);
    printf("data->ceiling = %s\n\n", data->ceiling);
}

void print_map(char **map)
{
    int i, j;

    for (i = 0; map[i] != NULL; i++) {
        for (j = 0; map[i][j] != '\0'; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void    ft_all_parse(t_parse *parse)
{
    printf("\nTous ce que parse contient:\n");
    printf("parse->north = %d\n", parse->north);
    printf("parse->south = %d\n", parse->south);
    printf("parse->west = %d\n", parse->west);
    printf("parse->east = %d\n", parse->east);
    printf("parse->floor = %d\n", parse->floor);
    printf("parse->map_wg_char = %d\n", parse->map_wg_char);
    printf("parse->map_end = %d\n", parse->map_end);
    printf("parse->map_wall = %d\n", parse->map_wall);
    printf("parse->map_dup = %d\n", parse->map_dup);
    printf("parse->map_no_pow = %d\n", parse->map_no_pos);
    printf("parse->no_map = %d\n", parse->no_map);
    printf("parse->wrong_line = %d\n\n", parse->wrong_line);
}

void getPositionOfN(t_map *map) {
    int rows = 1;
    int columns = 1;
    int x = -1;
    int y = -1;

    while (map->map[rows] != NULL) {
        int currentColumns = 0;
        while (map->map[rows][currentColumns] != '\0') {
            currentColumns++;
        }
        if (currentColumns > columns) {
            columns = currentColumns;
        }
        rows++;
    }

	int i = 1;
	while (i < rows)
	{
    	int currentColumns = 0;
    	while (map->map[i][currentColumns] != '\0') 
		{
        	if (map->map[i][currentColumns] == 'N' || map->map[i][currentColumns] == 'S' ||
				map->map[i][currentColumns] == 'W' || map->map[i][currentColumns] == 'E' )
			{
            	x = currentColumns;
        		y = i;
            	break;
        	}
     		currentColumns++;
    	}
    	if (x != -1 && y != -1) {
    		break;
    	}
    	i++;
	}

double centerX = x + 0.5;
double centerY = y + 0.5;

map->x = centerX;
map->y = centerY;

}