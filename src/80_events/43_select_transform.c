/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   43_select_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:00:25 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/08 02:07:08 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_sel_transform(int keysym, t_matrix transform)
{
	if (keysym == XK_w)
		return (ft_matrix_mult(transform,
				ft_translation_matrix(0, 0.3, 0)));
	else if (keysym == XK_s)
		return (transform = ft_matrix_mult(transform,
				ft_translation_matrix(0, -0.3, 0)));
	else if (keysym == XK_a)
		return (transform = ft_matrix_mult(transform,
				ft_translation_matrix(-0.3, 0, 0)));
	else if (keysym == XK_d)
		return (transform = ft_matrix_mult(transform,
				ft_translation_matrix(0.3, 0, 0)));
	else if (keysym == XK_q)
		return (transform = ft_matrix_mult(transform,
				ft_translation_matrix(0, 0, -0.3)));
	else if (keysym == XK_e)
		return (transform = ft_matrix_mult(transform,
				ft_translation_matrix(0, 0, 0.3)));
	else
		return (ft_create_matrix(1, 1, 1));
}
