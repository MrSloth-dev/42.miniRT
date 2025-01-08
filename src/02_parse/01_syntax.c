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

int	ft_check_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == ',')
			count++;
	if (count == 2)
		return (1);
	return (0);
}

int	ft_syntax_ambient(t_canvas *canvas, char **split)
{
	char	**color_split;

	if (canvas->count.ambient > 0)
		return (ft_printf(2, "Error\nMore than one Ambient not allowed\n"), 0);
	if (ft_count_members(split) != 3)
		return (ft_printf(2, "Error\nAmbient format is wrong\n"), 0);
	if (!ft_check_commas(split[2]))
		return (ft_printf(2, "Error\nAmbient color format is wrong\n"), 0);
	color_split = ft_split(split[2], ',');
	if (!ft_check_null_split(color_split))
		return (ft_free_split(color_split),
			ft_printf(2, "Error\nAmbient color format is wrong\n"), 0);
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
		return (0);
	if (canvas->count.camera > 1)
		return (0);
	if (canvas->count.ambient > 1)
		return (0);
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
	while (line && ft_strlen(line) > 0 && ok && ft_check_count(canvas))
	{
		split = ft_split_charset(line, WHITESPACE);
		if (split && *split)
			ok = ft_syntax_line(split, canvas);
		ft_free_split(split);
		line = ft_free(line);
		line = get_next_line(fd, &canvas->gnl_rest);
	}
	line = ft_free(line);
	close (fd);
	if ((canvas->count.light < 1 || canvas->count.camera < 1
			|| canvas->count.ambient < 1) && ok)
		return (ft_printf(2, "Error\nNumber of elements not valid\n"), 0);
	return (canvas->gnl_rest = ft_free(canvas->gnl_rest), ok);
}
