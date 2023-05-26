/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:53:46 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/26 16:53:47 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_map_lost(char c)
{
	if (c != '\0' && c != '1' && c != '0' && c != ' ')
		return (1);
	return (0);
}

char	*ft_file_path(const char *line)
{
	char	*start;
	char	*end;
	size_t	filepath_length;
	char	*filepath;

	start = strchr(line, '.');
	if (start != NULL)
	{
		end = strstr(start, ".xpm");
		if (end != NULL && end > start)
		{
			filepath_length = end - start + 4;
			filepath = (char *)malloc((filepath_length + 1) * sizeof(char));
			strncpy(filepath, start, filepath_length);
			filepath[filepath_length] = '\0';
			return (filepath);
		}
	}
	return (NULL);
}

int	ft_file(char *str)
{
	int	i;

	i = 0;
	if (str && str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
			return (1);
		else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
			return (2);
		else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
			return (3);
		else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
			return (4);
		else if (str[i] == 'F' && str[i + 1] == ' ')
			return (5);
		else if (str[i] == 'C' && str[i + 1] == ' ')
			return (6);
		else if (ft_map_lost(str[i]) == 1)
			return (7);
	}
	return (0);
}

int	ft_check_file(char *str)
{
	char	*new;
	int		fd;

	new = ft_file_path(str);
	if (new == NULL)
	{
		printf("Invalid file path.\n");
		return (3);
	}
	fd = open(new, O_RDONLY);
	free(new);
	if (fd == -1)
	{
		printf("Failed to open file.\n");
		return (3);
	}
	if (fd == 3)
	{
		close(fd);
		return (1);
	}
	return (3);
}
