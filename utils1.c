#include "cub3D.h"

void	ft_free_str2d(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}

size_t	ft_str2dlen(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
