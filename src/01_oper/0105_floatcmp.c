#include "minirt.h"

int	ft_floatcmp(double num1, double num2) //p5
{
	if (fabs(num1 - num2) < ROUND_ERROR)
		return (1);
	else
		return (0);
}
