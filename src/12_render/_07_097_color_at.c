/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _07_097_color_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_color_at(t_canvas *canvas, t_ray ray)
{
	t_color		color;
	t_interlst	*lst;
	t_inter		*hit;
	t_comp		comp;
	t_interlst	*head;

	lst = ft_intersect_world(canvas, ray);
	head = lst;
	hit = ft_hit_inter(&lst);
	if (!hit)
		return (ft_free_objects(head), (t_color){0, 0, 0, 3});
	comp = ft_prepare_comp(hit, ray, canvas);
	color = ft_lighting_shadow(canvas, comp);
	return (ft_free_objects(head), color);
}
