/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _01_005_is_float_equal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:13:29 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_is_float_equal(double num1, double num2)
{
	if (fabs(num1 - num2) < ROUND_ERROR)
		return (1);
	else
		return (0);
}
