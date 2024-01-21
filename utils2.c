#include "cub3D.h"

void	**ft_realloc2d(char **ptr, size_t size)
{
	size_t	i;
	char	**temp;

	i = 0;
	temp = (char *)malloc(sizeof(char *) * size);
	if (!temp)
		return (NULL);
	while (ptr[i])
	{
		temp[i] = ptr[i];
		i++;
	}
	temp[size - 1] = NULL;
	temp[size - 2] = NULL;
	ft_free_str2d(ptr);
}
