/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:35:57 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:39:30 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_syntax_ambient(t_canvas *canvas, char **split)
{
	char	**color_split;

	if (!split)
		return (0);
	if (ft_count_members(split) != 3)
		return (ft_printf(2, "Error, ambient format is wrong\n"), 0);
	color_split = ft_split(split[2], ',');
	if (!ft_check_null_split(color_split))
		return (ft_free_split(color_split),
			ft_printf(2, "Error, ambient color format is wrong\n"), 0);
	canvas->count.ambient++;
	return (ft_free_split(color_split), 1);
}

int	ft_syntax_line(char **split, t_canvas *canvas)
{
	if (!split)
		return (1);
	if (!ft_strcmp(*split, "A"))
		return (ft_syntax_ambient(canvas, split));
	else if (!ft_strcmp(*split, "C"))
		return (ft_syntax_camera(canvas, split));
	else if (!ft_strcmp(*split, "L"))
		return (ft_syntax_light(canvas, split));
	else if (!ft_strcmp(*split, "sp"))
		return (ft_syntax_sphere(canvas, split));
	else if (!ft_strcmp(*split, "pl"))
		return (ft_syntax_plane(canvas, split));
	else if (!ft_strcmp(*split, "cy"))
		return (ft_syntax_cylinder(canvas, split));
	return (1);
}

/**
 * @brief 
 *
 * @param canvas 
 * @return 0 if not valid 1 if valid
 */
int	ft_check_count(t_canvas *canvas)
{
	if (canvas->count.light > 1)
		return (ft_printf(2, "Error\nMore than one light\n"), 0);
	if (canvas->count.camera > 1)
		return (ft_printf(2, "Error\nMore than one camera\n"), 0);
	if (canvas->count.ambient > 1)
		return (ft_printf(2, "Error\nMore than one ambient\n"), 0);
	return (1);
}

int	ft_check_syntax(t_canvas *canvas, char *file)
{
	char	**split;
	char	*line;
	int		fd;
	int		ok;

	ok = 1;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd, &canvas->gnl_rest);
	while (line && ft_strlen(line) > 0 && ft_check_count(canvas))
	{
		split = ft_split_charset(line, WHITESPACE);
		if (split && *split)
			ok = ft_syntax_line(split, canvas);
		ft_free_split(split);
		line = ft_free(line);
		line = get_next_line(fd, &canvas->gnl_rest);
	}
	if (canvas->count.light < 1 || canvas->count.camera < 1
		|| canvas->count.ambient < 1)
		return (ft_printf(2,
				"Error\nMust have @ least one light, camera and ambient\n"), 0);
	line = ft_free(line);
	return (canvas->gnl_rest = ft_free(canvas->gnl_rest), close(fd), ok);
}
