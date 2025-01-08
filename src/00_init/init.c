/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:28:42 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_init_canvas(t_canvas *canvas)
{
	*canvas = (t_canvas){0};
	if (STEP > 19 || STEP < 1)
		canvas->step = 2;
	else
		canvas->step = STEP;
	if (DEBUG != 1)
		canvas->debug = 0;
	else
		canvas->debug = 1;
	canvas->mouse_prev_x = -1;
	canvas->mouse_prev_y = -1;
	canvas->shift_press = 1;
	canvas->disco_dance = 0.5;
}
