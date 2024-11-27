/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:34:45 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/16 16:59:05 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_get_sphere(char *line, t_world *w)
{
	t_shapes	*s;

	line += 2;
	w->ui.n_objs[0]++;
	s = ft_create_shape(SPHERE);
	s->sphere.coordinates = ft_get_tuple(w, s, &line, 1);
	s->sphere.diameter = ft_get_double(w, s, &line, ' ');
	if (s->sphere.diameter < 0)
		ft_perror(w, s, "Sphere diameter is out of range");
	ft_get_texture(w, s, &line);
	s->material.ambient = ft_ops(w->ambient.color, '*', w->ambient.ratio);
	ft_get_transform(s, s->sphere.coordinates, (t_vec3){0, 0, 0, 0},
		s->sphere.diameter / 2);
	ft_add_shapes(&w->objects, s);
}

void	ft_get_plane(char *line, t_world *w)
{
	t_shapes	*s;

	line += 2;
	w->ui.n_objs[1]++;
	s = ft_create_shape(PLANE);
	s->plane.coordinates = ft_get_tuple(w, s, &line, 1);
	s->plane.orientation = ft_get_tuple(w, s, &line, 0);
	if (ft_in_range(s->plane.orientation, -1, 1) == false)
		ft_perror(w, s, "Plane orientation is out of range");
	ft_get_texture(w, s, &line);
	s->material.ambient = ft_ops(w->ambient.color, '*', w->ambient.ratio);
	ft_get_transform(s, s->plane.coordinates, s->plane.orientation, 0);
	ft_add_shapes(&w->objects, s);
}

void	ft_get_cylinder(char *line, t_world *w)
{
	t_shapes	*s;

	line += 2;
	w->ui.n_objs[2]++;
	s = ft_create_shape(CYLINDER);
	s->cylinder.coordinates = ft_get_tuple(w, s, &line, 1);
	s->cylinder.orientation = ft_get_tuple(w, s, &line, 0);
	if (ft_in_range(s->cylinder.orientation, -1, 1) == false)
		ft_perror(w, s, "Cylinder orientation is out of range");
	s->cylinder.diameter = ft_get_double(w, s, &line, ' ');
	s->cylinder.height = ft_get_double(w, s, &line, ' ');
	if (s->cylinder.diameter <= 0 || s->cylinder.height <= 0)
		ft_perror(w, s, "Cylinder diameter and/or height are not valid");
	ft_get_texture(w, s, &line);
	s->material.ambient = ft_ops(w->ambient.color, '*', w->ambient.ratio);
	ft_get_transform(s, s->cylinder.coordinates, s->cylinder.orientation,
		s->cylinder.diameter / 2);
	s->cylinder.minimum = -s->cylinder.height / 2;
	s->cylinder.maximum = s->cylinder.height / 2;
	s->cylinder.closed = true;
	ft_add_shapes(&w->objects, s);
}

void	ft_get_cone(char *line, t_world *w)
{
	t_shapes	*s;

	line += 2;
	w->ui.n_objs[3]++;
	s = ft_create_shape(CONE);
	s->cone.coordinates = ft_get_tuple(w, s, &line, 1);
	s->cone.orientation = ft_get_tuple(w, s, &line, 0);
	if (ft_in_range(s->cone.orientation, -1, 1) == false)
		ft_perror(w, s, "Cone orientation is out of range");
	s->cone.diameter = ft_get_double(w, s, &line, ' ');
	if (s->cone.diameter <= 0)
		ft_perror(w, s, "Cone diameter is not valid");
	ft_get_texture(w, s, &line);
	s->material.ambient = ft_ops(w->ambient.color, '*', w->ambient.ratio);
	ft_get_transform(s, s->cone.coordinates, s->cone.orientation,
		s->cone.diameter / 2);
	s->cone.minimum = -1;
	s->cone.maximum = 0;
	s->cone.closed = true;
	ft_add_shapes(&w->objects, s);
}

void	ft_get_cube(char *line, t_world *w)
{
	t_shapes	*s;

	line += 2;
	w->ui.n_objs[4]++;
	s = ft_create_shape(CUBE);
	s->cube.coordinates = ft_get_tuple(w, s, &line, 1);
	s->cube.orientation = ft_get_tuple(w, s, &line, 0);
	if (ft_in_range(s->cube.orientation, -1, 1) == false)
		ft_perror(w, s, "Cube orientation is out of range");
	s->cube.size = ft_get_double(w, s, &line, ' ');
	if (s->cube.size <= 0)
		ft_perror(w, s, "Cube size is not valid");
	ft_get_texture(w, s, &line);
	s->material.ambient = ft_ops(w->ambient.color, '*', w->ambient.ratio);
	ft_get_transform(s, s->cube.coordinates, s->cube.orientation,
		s->cube.size / 2);
	ft_add_shapes(&w->objects, s);
}
