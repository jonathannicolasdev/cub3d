#include "../../cub3d.h"

int	is_non_map_char(char c)
{
	if (c != '\0' && c != '1' && c != '0' && c != ' ')
	{
		return (1);
	}
	return (0);
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

int			is_double(int a)
{
	if (a == 1 || a == 2)
		return (2);
	return (1);
}

int	check_file_readability(char *str, int i)
{
	int	fd;

	fd = open(str + i, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (3);
	}
	close(fd);
	return (1);
}

int	validate_color_string(char *str, int i)
{
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if (str[i] == '\0')
	{
		return (1);
	}
	return (3);
}

int	validate_rgb_color(char *str, int i)
{
	if (str && str[i])
	{
		if (ft_patoi(str + i) >= 0 && ft_patoi(str + i) <= 255)
		{
			while (str[i] && str[i] >= '0' && str[i] <= '9')
			{
				i++;
			}
			if (str[i] && str[i] == ',')
			{
				i++;
				if (ft_patoi(str + i) >= 0 && ft_patoi(str + i) <= 255)
				{
					while (str[i] && str[i] >= '0' && str[i] <= '9')
					{
						i++;
					}
					if (str[i] && str[i] == ',')
					{
						i++;
						if (ft_patoi(str + i) >= 0 && ft_patoi(str + i) <= 255)
						{
							return (validate_color_string(str, i));
						}
					}
				}
			}
		}
	}
	return (3);
}

int check_string_position(char *s1, char *s, char *s2)
{
    char *ptr = s;

    while (*ptr)
        ptr++;
    while (ptr != s && *ptr != '0')
        ptr--;
    if ((unsigned long)(ptr - s) >= ft_strlen(s1))
    {
		printf("Error! *check_string_position*\n");
        return 1;
    }
    if ((unsigned long)(ptr - s) >= ft_strlen(s2))
    {
		printf("Error! *check_string_position*\n");
        return 1;
    }
    return 0;
}

int	ft_space(char *str)
{
	char	*ptr = str;

	if (*ptr == ' ')
	{
		while (*ptr == ' ')
		{
			ptr++;
		}
	}
	return (*ptr == '1' || *ptr == '0');
}
