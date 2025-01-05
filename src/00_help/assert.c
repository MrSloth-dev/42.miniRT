#include "minirt.h"
#include <assert.h>

void	ft_assert(int condition, char *message)
{
	if (!condition)
	{
		ft_printf(2, RED"%s"RESET, message);
	}
}
