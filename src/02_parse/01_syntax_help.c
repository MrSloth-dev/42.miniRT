/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_syntax_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:38:54 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:38:54 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_syntax_camera(t_canvas *canvas, char **split)
{
	char	**coord_split;
	char	**norm_split;

	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error\nCamera format is wrong\n"), 0);
	coord_split = ft_split(split[1], ',');
	if (!ft_check_null_split(coord_split))
		return (ft_free_split(coord_split),
			ft_printf(2, "Error\nCamera coord format is wrong\n"), 0);
	norm_split = ft_split(split[2], ',');
	if (!ft_check_null_split(norm_split))
		return (ft_free_split(norm_split),
			ft_printf(2, "Error\nCamera normal format is wrong\n"), 0);
	canvas->count.camera++;
	return (ft_free_split(coord_split), ft_free_split(norm_split), 1);
}

int	ft_syntax_light(t_canvas *canvas, char **split)
{
	char	**coord_split;
	char	**color_split;

	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, light format is wrong\n"), 0);
	coord_split = ft_split(split[1], ',');
	if (!ft_check_null_split(coord_split))
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, light coord format is wrong\n"), 0);
	color_split = ft_split(split[3], ',');
	if (!ft_check_null_split(color_split))
		return (ft_free_split(color_split),
			ft_printf(2, "Error, light color format is wrong\n"), 0);
	canvas->count.light++;
	return (ft_free_split(coord_split), ft_free_split(color_split), 1);
}

int	ft_syntax_sphere(t_canvas *canvas, char **split)
{
	char	**coord_split;
	char	**color_split;

	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, sphere format is wrong\n"), 0);
	coord_split = ft_split(split[1], ',');
	if (!ft_check_null_split(coord_split))
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, sphere coord format is wrong\n"), 0);
	color_split = ft_split(split[3], ',');
	if (!ft_check_null_split(color_split))
		return (ft_free_split(color_split),
			ft_printf(2, "Error, sphere color format is wrong\n"), 0);
	canvas->count.sphere++;
	return (ft_free_split(coord_split), ft_free_split(color_split), 1);
}

int	ft_syntax_plane(t_canvas *canvas, char **split)
{
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, plane format is wrong\n"), 0);
	canvas->count.plane++;
	return (1);
}

int	ft_syntax_cylinder(t_canvas *canvas, char **split)
{
	if (ft_count_members(split) != 6)
		return (ft_printf(2, "Error, cylinder format is wrong\n"), 0);
	canvas->count.cylinder++;
	return (1);
}
