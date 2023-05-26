#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char *nextToken = NULL;

	if (str != NULL)
		nextToken = str;
	if (nextToken == NULL)
		return (NULL);
	while (*nextToken != '\0' && ft_strchr(delim, *nextToken) != NULL)
		nextToken++;
	if (*nextToken == '\0')
	{
		nextToken = NULL;
		return (NULL);
	}
	char *currentToken = nextToken;
	while (*nextToken != '\0' && ft_strchr(delim, *nextToken) == NULL)
		nextToken++;
	if (*nextToken == '\0')
		nextToken = NULL;
	else
	{
		*nextToken = '\0';
		nextToken++;
	}
	return (currentToken);
}