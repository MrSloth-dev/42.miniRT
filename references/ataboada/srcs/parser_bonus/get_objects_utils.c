/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:56:01 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/18 12:23:16 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_get_transform(t_shapes *s, t_point coord, t_vec3 orien, double diam)
{
	t_matrix	translate;
	t_matrix	rotate;
	t_matrix	scale;

	translate = ft_translation_matrix(coord.x, coord.y, coord.z);
	scale = ft_create_matrix(4, 4, YES);
	if (s->type != PLANE)
		scale = ft_scaling_matrix(diam, diam, diam);
	s->transform = ft_multiply_matrix(translate, scale);
	rotate = ft_create_matrix(4, 4, YES);
	if (s->type != SPHERE)
		rotate = ft_get_rotate(orien);
	s->transform = ft_multiply_matrix(s->transform, rotate);
	s->inverted = ft_invert_matrix(s->transform);
	s->transposed = ft_transpose_matrix(s->inverted);
}

t_matrix	ft_get_rotate(t_vec3 orien)
{
	t_matrix	rotate_y;
	t_matrix	rotate_z;
	t_matrix	rotate;

	rotate = ft_create_matrix(4, 4, YES);
	if (orien.x)
		rotate = ft_rotation_matrix('z', orien.x * M_PI / 2);
	if (orien.y)
	{
		rotate_y = ft_rotation_matrix('y', orien.y * M_PI / 2);
		if (orien.x)
			rotate = ft_multiply_matrix(rotate, rotate_y);
		else
			rotate = rotate_y;
	}
	if (orien.z)
	{
		rotate_z = ft_rotation_matrix('x', orien.z * M_PI / 2);
		if (orien.x || orien.y)
			rotate = ft_multiply_matrix(rotate, rotate_z);
		else
			rotate = rotate_z;
	}
	return (rotate);
}

void	ft_get_texture(t_world *w, t_shapes *s, char **l)
{
	t_color	color_a;
	t_color	color_b;
	char	type;

	while (**l == ' ')
		(*l)++;
	if (ft_isdigit(**l) || **l == '-' || **l == '+')
		s->material.color = ft_get_tuple(w, s, l, 3);
	else if (**l == 'S' || **l == 'G' || **l == 'R' || **l == 'C')
	{
		type = **l;
		(*l)++;
		color_a = ft_get_tuple(w, s, l, 3);
		color_b = ft_get_tuple(w, s, l, 3);
		s->material.pattern = ft_create_pattern(type, color_a, color_b);
	}
	else
		s->material.pattern = ft_create_xpm_pat(w, s, XPM, ft_get_xpm(w, s, l));
	ft_get_optics(w, s, l);
}

char	*ft_get_xpm(t_world *w, t_shapes *s, char **line)
{
	char	*f;
	int		i;

	i = 0;
	while (**line == ' ')
		(*line)++;
	if (**line != '"')
		ft_perror(w, s, "Invalid texture path");
	(*line)++;
	if (!ft_strchr(*line, '"'))
		ft_perror(w, s, "Invalid texture path");
	while ((*line)[i] != '"')
		i++;
	f = ft_substr(*line, 0, i);
	if (ft_strlen(f) < 4 || ft_strncmp(f + ft_strlen(f) - 4, ".xpm", 4))
	{
		free(f);
		ft_perror(w, s, "Invalid texture file extension");
	}
	if (ft_strlen(f) < 5 || *(f + ft_strlen(f) - 5) == '/')
		ft_perror(w, s, "Invalid file name");
	*line += i + 1;
	return (f);
}

void	ft_get_optics(t_world *w, t_shapes *s, char **line)
{
	while (**line == ' ')
		(*line)++;
	if (**line == 'R' && *(*line + 1) == 'E')
	{
		(*line) += 2;
		s->material.reflective = ft_get_double(w, s, line, ' ');
		if (s->material.reflective < 0 || s->material.reflective > 1)
			ft_perror(w, s, "Invalid reflectivity value");
	}
	else if (**line == 'R' && *(*line + 1) == 'A')
	{
		(*line) += 2;
		s->material.transparency = ft_get_double(w, s, line, ' ');
		if (s->material.transparency < 0 || s->material.transparency > 1)
			ft_perror(w, s, "Invalid transparency value");
		s->material.refractive_index = ft_get_double(w, s, line, ' ');
		if (s->material.refractive_index < 1)
			ft_perror(w, s, "Invalid refractive index value");
	}
}
