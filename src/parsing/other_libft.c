#include "../../cub3d.h"

int	ft_pstrlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

char	*ft_pstrjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(new = malloc(sizeof(char) * ft_pstrlen(s1, '\0') + ft_pstrlen(s2, '\0') + 1)))
	{
		return (NULL);
	}
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[k])
	{
		new[i++] = s2[k++];
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

char *ft_pstrdup(char *buffer, char c)
{
    char *new;
    int i;

    i = 0;
    if (!(new = malloc(sizeof(char) * ft_pstrlen(buffer, c) + 1)))
    {
        return (NULL);
    }
    while (buffer && buffer[i] && buffer[i] != c)
    {
        new[i] = buffer[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}


int	check_new_line(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_pstrcut(char *buffer, char c)
{
	int	i;

	i = 0;
	if (!(buffer))
	{
		return (NULL);
	}
	if (check_new_line(buffer, c) == 0)
	{
		return (NULL);
	}
	while (buffer[i] != c)
	{
		i++;
	}
	i++;
	return (ft_pstrdup(buffer + i, '\0'));
}

void    ft_pputchar(char c)
{
    write(1, &c, 1);
}

void    ft_pputstr(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        ft_pputchar(str[i++]);
    }
}

int	ft_patoi(char *str)
{
	long	result;
	int		neg;
	int		i;

	result = 0;
	neg	= 1;
	i = 0;
	if (!str)
	{
		return (0);
	}
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
	}
	if ((unsigned)result > 2147483647 && neg == 1)
	{
		return (-1);
	}
	return (result * neg);
}