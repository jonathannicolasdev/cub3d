/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:05:37 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/19 13:05:38 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_buffer(char **buffer, char **line, char c)
{
	void	*tmp;

	tmp = *buffer;
	*line = gnl_strdup(*buffer, c);
	*buffer = gnl_strcut(*buffer, c);
	free(tmp);
	if (c == '\n')
	{
		return (1);
	}
	else if (c == '\0')
	{
		return (0);
	}
	return (-1);
}

int	read_file(char **buffer, char **line, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (ret == -1)
		{
			break ;
		}
		buff[ret] = '\0';
		*buffer = gnl_strjoin(*buffer, buff);
		if (gnl_check_new_line(buff, '\n') == 1)
		{
			break ;
		}
	}
	if (ret >= 0 && gnl_check_new_line(*buffer, '\n') == 1)
	{
		return (read_buffer(buffer, line, '\n'));
	}
	if (ret == 0 && BUFFER_SIZE > 0)
	{
		return (read_buffer(buffer, line, '\0'));
	}
	return (-1);

}

int	gnl(int fd, char **line)
{
	static char	*buffer[200000];

	if (line == NULL)
	{
		return (-1);
	}
	if (fd >= 0 && !(buffer[fd]))
	{
		if (!(buffer[fd] = malloc(1)))
		{
			return (-1);
		}
		buffer[fd][0] = '\0';
	}
	if (fd >= 0 && gnl_check_new_line(buffer[fd], '\n') == 1)
	{
		return (read_buffer(&buffer[fd], line, '\n'));
	}
	if (fd >= 0)
	{
		return (read_file(&buffer[fd], line, fd));
	}
	return (-1);
}
