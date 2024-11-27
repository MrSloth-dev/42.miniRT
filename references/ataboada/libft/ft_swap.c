/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:20:12 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/11 15:18:23 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Swaps the values of two ints. A will become B and B will become A.
/// @param a Address of integer to swap with B.
/// @param b Address to integer to swap with A.
void	ft_swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/// @brief Swaps the values of two doubles.
/// @param a Address of double to swap with B.
/// @param b Address to double to swap with A.
void	ft_swap_double(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
