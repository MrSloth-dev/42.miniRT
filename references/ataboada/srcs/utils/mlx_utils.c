/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:57:40 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/13 14:07:38 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

int	ft_int_to_rgb(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = ft_clamp((int)(255.999 * color.x), 0, 255);
	g = ft_clamp((int)(255.999 * color.y), 0, 255);
	b = ft_clamp((int)(255.999 * color.z), 0, 255);
	return (r << 16 | g << 8 | b);
}

t_color	ft_rgb_to_int(int color)
{
	t_color	c;

	c.x = (color >> 16) & 0xFF;
	c.y = (color >> 8) & 0xFF;
	c.z = color & 0xFF;
	c.x /= 255.999;
	c.y /= 255.999;
	c.z /= 255.999;
	c.w = 3;
	return (c);
}

void	ft_free_all_allocated_memory(t_world *w)
{
	t_list		*tmp;
	t_shapes	*shape;

	while (w->objects)
	{
		tmp = w->objects;
		w->objects = w->objects->next;
		shape = tmp->content;
		if (shape->material.pattern.type == XPM)
			ft_free_canvas(shape->material.pattern.xpm);
		free(shape);
		free(tmp);
	}
	while (w->lights)
	{
		tmp = w->lights;
		w->lights = w->lights->next;
		free(tmp->content);
		free(tmp);
	}
	if (w->camera)
		free(w->camera);
}
