/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_assert(int condition, char *message)
{
	if (!condition)
	{
		ft_printf(2, RED"%s"RESET, message);
	}
}
