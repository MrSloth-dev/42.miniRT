#include "minirt.h"

int	ft_is_float_equal(double num1, double num2)
{
	if (fabs(num1 - num2) < ROUND_ERROR)
		return (1);
	else
		return (0);
}
