#include "minirt.h"
#include <assert.h>
#include <stdio.h>

void	ft_assert(int condition, char *message)
{
	if (!condition)
	{
		ft_printf(2, RED"%s\n"RESET, message);
		exit(1);
	}
}
