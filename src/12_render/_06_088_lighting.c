/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _06_088_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_set_ambient_and_efective_color(t_canvas *canvas, t_comp *comp)
{
	comp->efective_color = ft_operator(comp->shape->material.color,
			'*', canvas->light.color);
	comp->ambient_on_object = ft_add_tuple(ft_operator(comp->efective_color,
				'*', comp->shape->material.ambient_color),
			comp->ambient_on_object);
}

static void	ft_set_diffuse_and_specular_to_black(t_comp *comp)
{
	comp->diffuse = (t_color){0, 0, 0, 3};
	comp->specular = (t_color){0, 0, 0, 3};
}

static t_color	ft_get_final_specular(double reflect_dot_eye, t_canvas *canvas,
			t_comp *comp)
{
	double	factor;

	if (reflect_dot_eye <= 0)
	{
		return ((t_color){0, 0, 0, 3});
	}
	factor = pow(reflect_dot_eye, comp->shape->material.shininess);
	return (ft_scalar_tuple(canvas->light.intensity,
			comp->shape->material.specular
			* factor));
}

t_color	ft_lighting_shadow(t_canvas *canvas, t_comp comp)
{
	t_tuple	light_vector;
	double	light_dot_normal;
	double	reflect_dot_eye;

	ft_set_ambient_and_efective_color(canvas, &comp);
	if (comp.in_shadow == true)
		return (comp.ambient_on_object);
	light_vector = ft_norm_vector(
			ft_sub_tuple(canvas->light.coord, comp.over_point));
	light_dot_normal = ft_dotprod_vector(light_vector, comp.normalv);
	reflect_dot_eye = 0;
	if (light_dot_normal < 0)
		ft_set_diffuse_and_specular_to_black(&comp);
	else
	{
		comp.diffuse = ft_scalar_tuple(ft_scalar_tuple(comp.efective_color,
					comp.shape->material.diffuse), light_dot_normal);
		reflect_dot_eye = ft_dotprod_vector(
				ft_reflect(ft_neg_tuple(light_vector), comp.normalv),
				ft_neg_tuple(canvas->camera.norm));
	}
	comp.specular = ft_get_final_specular(reflect_dot_eye, canvas, &comp);
	return (ft_add_tuple(
			ft_add_tuple(comp.specular, comp.ambient_on_object),
			comp.diffuse));
}
