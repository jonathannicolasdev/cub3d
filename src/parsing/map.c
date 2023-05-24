#include "../../cub3d.h"

int	ft_map_space(char **map, int actual, int i, int y)
{
	if (map[actual][i] == ' ')
	{
		if (i - 1 >= 0 && map[actual][i - 1] == '0')
			return (1);
		if (map[actual][i + 1] == '0')
			return (1);
		if (actual + 1 != y && map[actual + 1][i] == '0')
			return (1);
		if (actual != 0 && map[actual - 1][i] == '0')
			return (1);
	}
	return (0);
}

int	ft_map_player(char **map, int actual, int i, int y)
{
	if (map[actual][i] == 'N' || map[actual][i] == 'S' || map[actual][i] == 'E' || map[actual][i] == 'W')
	{
		if (i - 1 >= 0 && (map[actual][i - 1] != '0' && map[actual][i - 1] != '1'))
			return (1);
		if (map[actual][i + 1] != '0' && map[actual][i + 1] != '1')
			return (1);
		if (actual + 1 != y && (map[actual + 1][i] != '0' && map[actual + 1][i] != '1'))
			return (1);
		if (actual != 0 && (map[actual - 1][i] != '0' && map[actual - 1][i] != '1'))
			return (1);
		if (actual + 1 == y)
			return (1);
	}
	return (0);
}

int	ft_map_char(char **map, int actual, int i)
{
	if (map[actual][i] != ' ' && map[actual][i] != '1' && map[actual][i] != '0' && map[actual][i] != 'N' && map[actual][i] != 'S' && map[actual][i] != 'W' && map[actual][i] != 'E')
		return (1);
	return (0);
}

int	ft_map_zero(char **map, int actual, int i, int y)
{
	if (map[actual][i] == '0')
	{
		if (map[actual][i + 1] != '1')
		{
			if (map[actual][i + 1] != '0' && map[actual][i + 1] != 'N' && map[actual][i + 1] != 'S' && map[actual][i + 1] != 'E' && map[actual][i + 1] != 'W')
				return (1);
		}
		if (map[actual][i - 1] != '1')
		{
			if (map[actual][i - 1] != '0' && map[actual][i - 1] != 'N' && map[actual][i - 1] != 'S' && map[actual][i - 1] != 'E' && map[actual][i - 1] != 'W')
				return (1);
		}
		if (actual + 1 != y && map[actual + 1][i] != '1')
		{
			if (map[actual + 1][i] != '0' && map[actual + 1][i] != 'N' && map[actual + 1][i] != 'S' && map[actual + 1][i] != 'E' && map[actual + 1][i] != 'W')
				return (1);
		}
		if (actual != 0 && map[actual - 1][i] != '1')
		{
			if (map[actual - 1][i] != '0' && map[actual - 1][i] != 'N' && map[actual - 1][i] != 'S' && map[actual - 1][i] != 'E' && map[actual - 1][i] != 'W')
				return (1);
		}
		if (actual + 1 == y)
			return (1);
	}
	return (0);
}

int	ft_map_total_position(char **map)
{
	int	actual;
	int	i;
	int	total_position;

	actual = 0;
	i = 0;
	total_position = 0;
	while (map[actual])
	{
		i = 0;
		while (map[actual][i] != '\0')
		{
			if (map[actual][i] == 'N' || map[actual][i] == 'S' || map[actual][i] == 'W' || map[actual][i] == 'E')
			{
				total_position++;
			}
			i++;
		}
		actual++;
	}
	if (total_position == 1)
	{
		return (0);
	}
	return (1);
}

int	ft_map_wall_error(char **map, int actual, int i, int y)
{
	if (map[actual][i] == '1')
	{
		if (map[actual][i + 1] != ' ' && map[actual][i + 1] != '1' && map[actual][i + 1] != '\0')
		{
			if (map[actual][i + 1] != '0' && map[actual][i + 1] != 'N' && map[actual][i + 1] != 'S' && map[actual][i + 1] != 'E' && map[actual][i + 1] != 'W')
			{
				printf("Erreur! Mur manquant à droite du vide. Le résultat : map[actual][i + 1] = [%c] et debug x [%d] y [%d]\n", map[actual][i + 1], actual, i + 1);
			}
		}
		if (i - 1 > -1 && map[actual][i - 1] != ' ' && map[actual][i - 1] != '1' && map[actual][i - 1] != '\0')
		{
			if (map[actual][i - 1] != '0' && map[actual][i - 1] != 'N' && map[actual][i - 1] != 'S' && map[actual][i - 1] != 'E' && map[actual][i - 1] != 'W')
			{
				printf("Erreur! Mur manquant à gauche du vide. Le résultat : map[actual][i - 1] = [%c] et debug x [%d] y [%d]\n", map[actual][i - 1], actual, i - 1);
			}
		}
		if (actual + 1 != y && map[actual + 1][i] != ' ' && map[actual + 1][i] != '1' && map[actual + 1][i] != '\0')
		{
			if (map[actual + 1][i] != '0' && map[actual + 1][i] != 'N' && map[actual + 1][i] != 'S' && map[actual + 1][i] != 'E' && map[actual + 1][i] != 'W')
			{
				printf("Erreur! Mur manquant sur la ligne suivante du vide. Le résultat : map[actual + 1][i] = [%c] et debug x [%d] y [%d]\n", map[actual + 1][i], actual + 1, i);
			}
		}
		if (actual != 0  && map[actual - 1][i] != ' ' && map[actual - 1][i] != '1' && map[actual - 1][i] != '\0')
		{
			if (map[actual - 1][i] != '0' && map[actual - 1][i] != 'N' && map[actual - 1][i] != 'S' && map[actual - 1][i] != 'E' && map[actual - 1][i] != 'W')
			{
				printf("Erreur ! Mur manquant sur la ligne avant du vide. Le résultat : map[actual - 1][i] = [%c] et debug x [%d] y [%d]\n", map[actual - 1][i], actual - 1, i);
			}
		}
	}
	return (0);
}

t_parse	*ft_map(t_parse *parse, char **map)
{
	int	i = 0;
	int actual = 0;
	int	y = 0;

	if (ft_map_total_position(map) == 1)
		parse->map_wg_player_number = 1;
	while (map[y] != NULL)
		y++;
	while (map[actual])
	{
		i = 0;
		while (map[actual][i] != '\0')
		{
			//if (ft_map_zero_error(map, actual, i, y) == 1)
			//{
			//}
			if (ft_map_char(map, actual, i) == 1)
				parse->map_wg_character = 1;
			if (ft_map_space(map, actual, i, y) == 1)
				parse->map_wg_space = 1;
			if (ft_map_player(map, actual, i, y) == 1)
				parse->map_wg_player = 1;
			if (ft_map_zero(map, actual, i, y) == 1)
				parse->map_wg_zero = 1;
			i++;
		}
		actual++;
	}
	return (parse);
}