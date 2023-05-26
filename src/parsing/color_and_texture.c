/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:35:07 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/24 18:35:16 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int validate_color_string(char *str, int i)
{
    while (str[i] && str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] == '\0')
        return 1;
    return 3;
}

int validate_rgb_color(char *str, int i)
{
    if (str && str[i])
    {
        while (str[i] && str[i] == ' ')
            i++;
        if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
        {
            while (str[i] && str[i] >= '0' && str[i] <= '9')
                i++;
            while (str[i] && str[i] == ' ')
                i++;
            if (str[i] && str[i] == ',')
            {
                i++;
                while (str[i] && str[i] == ' ')
                    i++;
                if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
                {
                    while (str[i] && str[i] >= '0' && str[i] <= '9')
                        i++;
                    while (str[i] && str[i] == ' ')
                        i++;
                    if (str[i] && str[i] == ',')
                    {
                        i++;
                        while (str[i] && str[i] == ' ')
                            i++;
                        if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
                        {
                            while (str[i] && str[i] >= '0' && str[i] <= '9')
                                i++;
                            while (str[i] && str[i] == ' ')
                                i++;
                            if (!str[i])
                                return (validate_color_string(str, i));
                        }
                    }
                }
            }
        }
    }
    return (3);
}

