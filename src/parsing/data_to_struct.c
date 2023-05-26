#include "../../cub3d.h"

t_data	*ft_add_to_data(t_data *data, char **tab, int i)
{
	while (tab && tab[i])
	{
		if (ft_file(tab[i]) == 1)
			data->file_north = ft_file_path(tab[i]);
		if (ft_file(tab[i]) == 2)
			data->file_south = ft_file_path(tab[i]);
		if (ft_file(tab[i]) == 3)
			data->file_west = ft_file_path(tab[i]);
		if (ft_file(tab[i]) == 4)
			data->file_east = ft_file_path(tab[i]);
		if (ft_file(tab[i]) == 5)
			data->color_floor = ft_file_color(tab[i]);
		if (ft_file(tab[i]) == 6)
			data->color_ceiling = ft_file_color(tab[i]);
		i++;
	}
	data->map = ft_add_to_map(tab);
	return (data);
}

char	**ft_add_value_to_data(char **tab, t_parse *parse, char **data, int i)
{
	int	k;
	int	type;

	k = 0;
	while (tab[i])
	{
		type = ft_file(tab[i]);
		if (((type == 1 && parse->file_north)
				|| (type == 2 && parse->file_south)
				|| (type == 3 && parse->file_west)
				|| (type == 4 && parse->file_east)
				|| (type == 5 && parse->file_floor)
				|| (type == 6 && parse->file_ceiling)))
		{
			data[k++] = ft_pstrdup(tab[i], '\0');
		}
		i++;
	}
	data[k] = 0;
	return (data);
}

char	**ft_add_to_map(char **tab)
{
	char	**map;
	int		i;
	int		k;

	i = 0;
	k = 0;
	map = malloc(sizeof(char *) * 100);
	if (!(map))
		return (NULL);
	while (tab && tab[i])
	{
		if (ft_space(tab[i]) == 1)
		{
			while (tab[i])
				map[k++] = ft_pstrdup(tab[i++], '\0');
			break ;
		}
		i++;
	}
	map[k] = 0;
	return (map);
}

int	ft_space(char *str)
{
	char	*ptr;

	ptr = str;
	if (*ptr == ' ')
	{
		while (*ptr == ' ')
			ptr++;
	}
	return (*ptr == '1' || *ptr == '0');
}