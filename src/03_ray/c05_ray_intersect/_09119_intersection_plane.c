/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _09119_intersection_plane.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:36:36 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/23 13:02:38 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_intersection_plane(t_interlst **lst, t_ray ray, t_shapes *shap)
{
	if (fabs(ray.dir.y) < ROUND_ERROR)
		return ;
	ft_lstadd_sort_inter(lst, (-ray.pos.y / ray.dir.y), shap);
}
