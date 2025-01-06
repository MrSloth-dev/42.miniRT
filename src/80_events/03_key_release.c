/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:59:02 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 09:59:03 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_release(int keysym, t_canvas *canvas)
{
	mlx_do_key_autorepeaton(canvas->mlx);
	if (keysym == XK_Shift_L)
		canvas->shift_press = 1;
	return (0);
}
