/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:34:20 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/03 15:35:25 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_change_resolution(int keysym, t_canvas *canvas)
{
	if (keysym == XK_p && canvas->step > 1)
		return (canvas->step--, true);
	if (keysym == XK_o && canvas->step < 19)
		return (canvas->step++, true);
	return (false);
}
