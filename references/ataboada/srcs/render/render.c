/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:09:19 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/29 17:07:40 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Renders the world pixel by pixel using the camera's view. Not used in bonus.
void	ft_render(t_camera *c, t_world *w)
{
	int			x;
	int			y;
	t_ray		r;
	t_color		color;
	char		*dst;

	y = -1;
	while (++y < c->vsize)
	{
		x = -1;
		while (++x < c->hsize)
		{
			r = ft_ray_for_pixel(c, x, y);
			color = ft_color_at(w, r, 5);
			if ((x > 0 && x < c->hsize) && (y > 0 && y < c->vsize))
			{
				dst = w->img.addr
					+ (y * w->img.line_length + x * (w->img.bpp / 8));
				*(unsigned int *)dst = ft_int_to_rgb(color);
			}
		}
	}
}

// Returns a ray that starts at the camera and goes through the pixel at the
// specified coordinates.
t_ray	ft_ray_for_pixel(t_camera *c, int x, int y)
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_ray	r;

	xoffset = (x + 0.5) * c->pixel_size;
	yoffset = (y + 0.5) * c->pixel_size;
	world_x = c->half_width - xoffset;
	world_y = c->half_height - yoffset;
	r.origin = ft_multiply_matrix_tuple(c->inverted, (t_point){0, 0, 0, 1});
	r.direction = ft_normalize(ft_op(ft_multiply_matrix_tuple(c->inverted,
					(t_point){world_x, world_y, -1, 1}), '-', r.origin));
	return (ft_create_ray(r.origin, r.direction));
}

// Returns the color of the pixel at the intersection point of the ray.
t_color	ft_color_at(t_world *world, t_ray r, int remaining)
{
	t_intrs	*i;
	t_intr	*hit;
	t_comps	comps;
	t_color	c;

	i = NULL;
	ft_world_intersections(&i, world, r);
	hit = ft_hit(i);
	if (hit)
	{
		comps = ft_prepare_computations(&i, hit, r);
		c = ft_shade_hit(world, &comps, comps.object->material, remaining);
	}
	else
		c = (t_color){0, 0, 0, 3};
	ft_free_intersections(&i);
	return (c);
}
