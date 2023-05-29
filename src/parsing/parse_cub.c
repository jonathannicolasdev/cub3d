/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:52:49 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/26 16:52:50 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_fd_cub(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nFile problem\n");
		return (-1);
	}
	else if (ft_cub(file) == 1)
		return (-1);
	return (fd);
}

int	ft_cub(char *argv)
{
	int	i;

	i = 0;
	while (argv && argv[i])
	{
		if (argv[i] == '.' && argv[i + 1] == 'c' && argv[i + 2] == 'u'
			&& argv[i + 3] == 'b' && argv[i + 4] == '\0')
		{
			return (SUCCESS);
		}
		i++;
	}
	printf("Error\nExtension problem\n");
	return (FAIL);
}
