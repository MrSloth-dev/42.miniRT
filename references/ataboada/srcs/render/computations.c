/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:39:26 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/24 11:19:19 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Initializes the t_comps structure.
t_comps	ft_prepare_computations(t_intrs **lst, t_intr *hit, t_ray r)
{
	t_comps	comps;

	comps.t = hit->t;
	comps.object = hit->object;
	comps.point = ft_op(r.origin, '+', ft_ops(r.direction, '*', comps.t));
	comps.eyev = ft_ops(r.direction, '*', -1);
	comps.normalv = ft_normal_at(comps.object, comps.point);
	if (ft_dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = ft_ops(comps.normalv, '*', -1);
	}
	else
		comps.inside = false;
	comps.over_point = ft_op(comps.point, '+', ft_ops(comps.normalv,
				'*', EPSILON));
	comps.under_point = ft_op(comps.point, '-', ft_ops(comps.normalv,
				'*', EPSILON));
	comps.reflectv = ft_reflect(r.direction, comps.normalv);
	ft_calculate_refracted_indices(&comps, lst, hit);
	return (comps);
}

// Calculates the normal vector at the specified point on the shape.
t_vec3	ft_normal_at(t_shapes *s, t_point world_point)
{
	t_point		object_point;
	t_vec3		object_normal;
	t_vec3		world_normal;

	object_point = ft_multiply_matrix_tuple(s->inverted, world_point);
	object_normal = (t_vec3){0, 0, 0, 0};
	if (s->type == SPHERE)
		object_normal = ft_op(object_point, '-', (t_point){0, 0, 0, 1});
	else if (s->type == PLANE)
		object_normal = (t_vec3){0, 1, 0, 0};
	else if (s->type == CYLINDER)
		object_normal = ft_cylinder_normal_at(s, object_point);
	else if (s->type == CONE)
		object_normal = ft_cone_normal_at(s, object_point);
	else if (s->type == CUBE)
		object_normal = ft_cube_normal_at(object_point);
	else if (s->type == TRIANGLE)
		return (s->triangle.normal);
	world_normal = ft_multiply_matrix_tuple(s->transposed, object_normal);
	world_normal.w = 0;
	return (ft_normalize(world_normal));
}

// Calculates the refracted indices of the objects (comps->n1, comps->n2).
void	ft_calculate_refracted_indices(t_comps *c, t_intrs **xs, t_intr *hit)
{
	t_intrs		*i;
	t_shapes	*shape;
	t_list		*containers;

	i = *xs;
	containers = NULL;
	while (i)
	{
		if (i->content == hit)
			ft_set_refracted_index('1', c, containers);
		shape = ((t_intr *)i->content)->object;
		if (ft_lst_contains(containers, shape) == true)
			ft_lst_remove(&containers, shape);
		else
			ft_lstadd_back(&containers, ft_lstnew(shape));
		if (i->content == hit)
		{
			ft_set_refracted_index('2', c, containers);
			ft_free_lst(&containers);
			return ;
		}
		i = i->next;
	}
}

void	ft_set_refracted_index(char n, t_comps *c, t_list *containers)
{
	t_shapes	*last;

	if (containers)
		last = ft_lst_last(containers)->content;
	if (n == '1')
	{
		if (!containers)
			c->n1 = 1.0;
		else
			c->n1 = last->material.refractive_index;
	}
	else
	{
		if (!containers)
			c->n2 = 1.0;
		else
			c->n2 = last->material.refractive_index;
	}
}
