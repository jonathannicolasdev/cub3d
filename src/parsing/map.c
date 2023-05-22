#include "../../cub3d.h"

int	check_orientation(char *str)
{
	int		number;
	char	c;

	number = 0;
	while ((c = *str++))
	{
		if (c == NORTH || c == SOUTH || c == EAST || c == WEST)
			number++;
	}
	return (number);
}

int	is_non_map_char(char c)
{
	if (c != '\0' && c != '1' && c != '2' && c != '0' && c != ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_unwanted_character(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != '1' && str[i] != '0' && str[i] != 'N' &&
			str[i] != 'W' && str[i] != 'E' && str[i] != 'S' && str[i] != 32)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_wall(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
	{
		i++;
	}
	while (str && str[i] && str[i] == '1')
	{
		i++;
	}
	if (str && str[i] == '\0')
	{
		return (0);
	}
	return (1);
}

int	ft_is_a_wall_around(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
	{
		i++;
	}
	if (str && str[i] && str[i] != '1')
	{
		return (1);
	}
	while (str && str[i])
	{
		i++;
	}
	i--;
	if (str && str[i] != '1')
	{
		return (1);
	}
	return (0);
}