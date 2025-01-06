/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_make_disco.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:59:24 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 09:59:37 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_backup_light_ambient(t_canvas *canvas, char to_do)
{
	if (to_do == 'b')
	{
		canvas->light.prev_color = canvas->light.color;
		canvas->light.prev_intensity = canvas->light.intensity;
		canvas->ambient.prev_color = canvas->ambient.color;
	}
	else
	{
		canvas->light.color = canvas->light.prev_color;
		canvas->light.intensity = canvas->light.prev_intensity;
		canvas->ambient.color = canvas->ambient.prev_color;
	}
}

static void	ft_strob_disco(t_canvas *canvas,
			t_color *up_color, t_color *up_inten)
{
	*up_color = ft_neg_tuple(*up_color);
	*up_inten = ft_neg_tuple(*up_inten);
	canvas->light.color = ft_add_tuple(canvas->light.color, *up_color);
	canvas->light.intensity = ft_add_tuple(canvas->light.intensity, *up_inten);
	ft_refreshframe(canvas);
}

static bool	ft_set_local_step(t_canvas *canvas, unsigned int *local_step)
{
	if (canvas->step == 1 || canvas->shift_press == 1)
		return (false);
	else if (canvas->step > 10)
		*local_step = canvas->step * 8000000;
	else if (canvas->step > 2)
		*local_step = canvas->step * 16000000;
	else
		*local_step = canvas->step * 5000000;
	return (true);
}

void	ft_make_disco_dancing(t_canvas *canvas,
			unsigned int strob, unsigned int local_step)
{
	unsigned int	change;
	t_color			up_color;
	t_color			up_inten;
	int				type;
	int				done;

	up_color = (t_tuple){3, 3, 3, 3};
	up_inten = (t_tuple){0.06, 0.06, 0.06, 3};
	change = 0;
	type = 0;
	done = 0;
	while (1)
	{
		if (change++ == 0)
			ft_change_color_disco(canvas, &type);
		if (canvas->step > 2 && change == strob)
			ft_strob_disco(canvas, &up_color, &up_inten);
		if (change == local_step)
		{
			if (++done == 40)
				break ;
			change = 0;
			ft_refreshframe(canvas);
		}
	}
}

bool	ft_make_disco(int key, t_canvas *canvas)
{
	unsigned int		local_step;
	unsigned int		strob;

	if (!ft_set_local_step(canvas, &local_step))
		return (false);
	strob = local_step / 6;
	ft_backup_light_ambient(canvas, 'b');
	if (key == XK_0)
	{
		ft_make_disco_dancing(canvas, strob, local_step);
		ft_backup_light_ambient(canvas, 'r');
	}
	else
		return (false);
	return (true);
}
