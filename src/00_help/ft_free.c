#include "minirt.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (NULL);
}

void	*ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		split[i] = ft_free(split[i]);
		i++;
	}
	if (split)
		split = ft_free(split);
	return (NULL);
}

