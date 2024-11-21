/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:27:20 by joao-pol          #+#    #+#             */
/*   Updated: 2024/11/21 13:27:20 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *str)
{
	double	dec;
	double	fractional;
	long	integer;
	int		neg;

	if (ft_strisdigit(str) == 0)
		return (-43.42);
	neg = 1;
	integer = 0;
	fractional = 0;
	dec = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	while (*str && *str != '.')
		integer = (integer * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str)
	{
		dec /= 10;
		fractional = fractional + (*str++ - 48) * dec;
	}
	return ((integer + fractional) * neg);
}
