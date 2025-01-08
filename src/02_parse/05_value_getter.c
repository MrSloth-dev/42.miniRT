/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_value_getter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:22:40 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:22:40 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_get_double(char *str, char *element, t_canvas *canvas)
{
	double	value;

	(void)canvas;
	value = ft_atod(str);
	if (ft_is_float_equal(value, -43.42))
		return (ft_printf(2, "Error\n%s ratio format is wrong\n", element),
			value);
	return (value);
}

t_tuple	ft_get_norm(char *str, char *element, t_canvas *canvas)
{
	char	**norm_split;
	t_tuple	norm;

	(void)canvas;
	if (!ft_check_commas(str))
		return (ft_printf(2, "Error\n%s norm format is wrong\n", element),
			(t_tuple){-43.42, -43.42, -43.42, -1});
	norm_split = ft_split(str, ',');
	norm = (t_color){ft_atod(norm_split[0]), ft_atod(norm_split[1]),
		ft_atod(norm_split[2]), 0};
	if (ft_check_null_split(norm_split)
		&& ft_norm_check(norm))
		return (ft_free_split(norm_split), norm);
	else
		return (ft_free_split(norm_split),
			ft_printf(2, "Error\n%s normal format is wrong\n", element),
			(t_tuple){-43.42, -43.42, -43.42, -1});
}

t_tuple	ft_get_coord(char *str, char *element, t_canvas *canvas)
{
	char	**coord_split;
	t_tuple	coord;

	(void)canvas;
	if (!ft_check_commas(str))
		return (ft_printf(2, "Error\n%s coord format is wrong\n", element),
			(t_tuple){-43.42, -43.42, -43.42, -1});
	coord_split = ft_split(str, ',');
	coord = (t_color){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split)
		&& ft_check_values(coord.x, coord.y, coord.z))
		return (ft_free_split(coord_split), coord);
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error\n%s coord format is wrong\n", element),
			(t_color){-43.42, -43.42, -43.42, -1});
}

t_color	ft_get_color(char *str, char *element, t_canvas *canvas)
{
	char	**color_split;
	t_color	color;

	(void)canvas;
	if (!ft_check_commas(str))
		return (ft_printf(2, "Error\n%s color format is wrong\n", element),
			(t_color){-43.42, -43.42, -43.42, -1});
	color_split = ft_split(str, ',');
	color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};
	if (!ft_rgb_check(color))
		return (ft_free_split(color_split),
			ft_printf(2, "Error\n%s color is out of bounds [0-255]\n", element),
			(t_color){-43.42, -43.42, -43.42, -1});
	else if (ft_check_null_split(color_split))
		return (ft_free_split(color_split), color);
	else
		return (ft_free_split(color_split),
			ft_printf(2, "Error\n%s color format is wrong\n", element),
			(t_color){-43.42, -43.42, -43.42, -1});
}
