/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:37:47 by ylabbe            #+#    #+#             */
/*   Updated: 2023/05/28 15:47:17 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_token(char **nexttoken, const char *delim)
{
	char	*currenttoken;

	currenttoken = *nexttoken;
	while (**nexttoken != '\0' && ft_strchr(delim, **nexttoken) != NULL)
		(*nexttoken)++;
	if (**nexttoken == '\0')
	{
		*nexttoken = NULL;
		return (NULL);
	}
	currenttoken = *nexttoken;
	while (**nexttoken != '\0' && ft_strchr(delim, **nexttoken) == NULL)
		(*nexttoken)++;
	if (**nexttoken == '\0')
		*nexttoken = NULL;
	else
	{
		**nexttoken = '\0';
		(*nexttoken)++;
	}
	return (currenttoken);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*nexttoken = NULL;

	if (str != NULL)
		nexttoken = str;
	if (nexttoken == NULL)
		return (NULL);
	return (get_next_token(&nexttoken, delim));
}
