/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:40:27 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/25 16:43:04 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Initializes the t_shape struct while creating a shape. This shape can be a
// sphere, plane, cylinder, cone, cube or triangle.
t_shapes	*ft_create_shape(int type)
{
	t_shapes	*shapes;

	shapes = malloc(sizeof(t_shapes));
	if (!shapes)
		return (NULL);
	shapes->type = type;
	shapes->transform = ft_create_matrix(4, 4, YES);
	shapes->inverted = ft_create_matrix(4, 4, YES);
	shapes->transposed = ft_create_matrix(4, 4, YES);
	shapes->material = ft_create_material();
	return (shapes);
}

// Creates a material with default values.
t_material	ft_create_material(void)
{
	t_material	material;

	material.color = (t_color){0.7, 0.7, 0.7, 3};
	material.ambient = (t_color){0.1, 0.1, 0.1, 3};
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200;
	material.reflective = 0;
	material.transparency = 0;
	material.refractive_index = 1;
	material.pattern = ft_create_pattern('N',
			(t_color){1, 1, 1, 3}, (t_color){0, 0, 0, 3});
	return (material);
}

// Adds a shape to the list of shapes.
void	ft_add_shapes(t_list **lst, t_shapes *shapes)
{
	t_list	*new;

	new = ft_lstnew(shapes);
	if (!*lst)
		*lst = new;
	else
		ft_lstadd_back(lst, new);
}

// Returns the discriminant of the specified shape and ray. It will also fill in
// the values of a, b and c in the t_aux struct.
double	ft_get_discriminant(int type, t_ray r, t_aux *a)
{
	if (type == CYLINDER)
	{
		a->a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
		a->b = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
		a->c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	}
	else if (type == CONE)
	{
		a->a = r.direction.x * r.direction.x
			- r.direction.y * r.direction.y
			+ r.direction.z * r.direction.z;
		a->b = 2 * r.origin.x * r.direction.x
			- 2 * r.origin.y * r.direction.y
			+ 2 * r.origin.z * r.direction.z;
		a->c = r.origin.x * r.origin.x
			- r.origin.y * r.origin.y
			+ r.origin.z * r.origin.z;
	}
	else
		return (0);
	return (a->b * a->b - 4 * a->a * a->c);
}
