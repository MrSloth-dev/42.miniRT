/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _13_177_intersection_cyl.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:18:44 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 10:18:46 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// verify if intersection is a cap of cylinder - page 186
static bool	ft_is_a_cyl_cap(t_ray ray, double intersect)
{
	double	x;
	double	z;

	x = ray.pos.x + intersect * ray.dir.x;
	z = ray.pos.z + intersect * ray.dir.z;
	return (x * x + z * z <= 1);
}

// verify if is a cap of cylinder, and add intersection to list - page 186
static void	ft_intersect_cyl_caps(t_interlst **lst, t_ray ray, t_shapes *shap)
{
	double	inter_one;
	double	inter_two;

	inter_one = (shap->cyl.size.min - ray.pos.y) / ray.dir.y;
	if (ft_is_a_cyl_cap(ray, inter_one))
		ft_lstadd_sort_inter(lst, inter_one, shap);
	inter_two = (shap->cyl.size.max - ray.pos.y) / ray.dir.y;
	if (ft_is_a_cyl_cap(ray, inter_two))
		ft_lstadd_sort_inter(lst, inter_two, shap);
}

//truncate cylinder - page 184
static void	ft_cyl_limits_and_intersect(t_interlst **lst, t_ray ray,
					t_shapes *shap, t_iter *h)
{
	double	temp;
	double	y_one;
	double	y_two;

	if (h->inter_one > h->inter_two)
	{
		temp = h->inter_one;
		h->inter_one = h->inter_two;
		h->inter_two = temp;
	}
	y_one = ray.pos.y + h->inter_one * ray.dir.y;
	if (shap->cyl.size.min < y_one && y_one < shap->cyl.size.max)
		ft_lstadd_sort_inter(lst, h->inter_one, shap);
	y_two = ray.pos.y + h->inter_two * ray.dir.y;
	if (shap->cyl.size.min < y_two && y_two < shap->cyl.size.max)
		ft_lstadd_sort_inter(lst, h->inter_two, shap);
}

// intersect cilinder circular wall, and caps - page 178 to 188
// if  h.a its aprox zero, the ray its paralel to cilinder wall
// if discriminnt is minor than zero, there is no wall intersection
// call to check if intersect a wall of cylinder
void	ft_intersection_cyl(t_interlst **lst, t_ray ray, t_shapes *shap)
{
	t_iter	h;
	double	discriminant;
	double	sqrt_discriminant;
	double	two_a;

	h.a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	if (!(h.a < ROUND_ERROR && h.a > -ROUND_ERROR))
	{
		h.b = 2 * ray.pos.x * ray.dir.x + 2 * ray.pos.z * ray.dir.z;
		h.cc = ray.pos.x * ray.pos.x + ray.pos.z * ray.pos.z - 1;
		discriminant = h.b * h.b - 4 * h.a * h.cc;
		if (discriminant < 0)
		{
			ft_intersect_cyl_caps(lst, ray, shap);
			return ;
		}
		two_a = 2 * h.a;
		sqrt_discriminant = sqrt(discriminant);
		h.inter_one = (-h.b - sqrt_discriminant) / two_a;
		h.inter_two = (-h.b + sqrt_discriminant) / two_a;
		ft_cyl_limits_and_intersect(lst, ray, shap, &h);
	}
	ft_intersect_cyl_caps(lst, ray, shap);
}
