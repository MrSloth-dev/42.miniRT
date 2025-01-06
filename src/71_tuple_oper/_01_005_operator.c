/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _01_005_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:12:52 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 10:13:53 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_operator(t_tuple a, char op, t_tuple b)
{
	t_tuple	r;

	r = (t_tuple){0, 0, 0, a.w || b.w};
	if (a.w == 3)
		r.w = 3;
	if (op == '+')
		r = (t_tuple){a.x + b.x, a.y + b.y, a.z + b.z, r.w};
	else if (op == '-')
	{
		if (a.w && b.w && a.w != 3)
			r.w = 0;
		r = (t_tuple){a.x - b.x, a.y - b.y, a.z - b.z, r.w};
	}
	else if (op == '*')
		r = (t_tuple){a.x * b.x, a.y * b.y, a.z * b.z, r.w};
	return (r);
}
