#include "minirt.h"

int	ft_syntax_ambient(t_canvas *canvas, char **split)
{
	// char	**color_split;
	if (!split)
		return (0);
	ft_printf(2, RED"_ambient\n"RESET);
	if (ft_count_members(split) != 3)
		return (ft_printf(2, "Error, ambient format is wrong\n"), 0);
	canvas->count.ambient++;
	return (1);
}

int	ft_syntax_camera(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_camera\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, camera format is wrong\n"), 0);
	canvas->count.camera++;
	return (1);
}

int	ft_syntax_light(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_light\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, light format is wrong\n"), 0);
	canvas->count.light++;
	return (1);
}

int	ft_syntax_sphere(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_sphere\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, sphere format is wrong\n"), 0);
	(void)canvas;
	return (1);
}

int	ft_syntax_plane(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_plane\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, plane format is wrong\n"), 0);
	canvas->count.plane++;
	return (1);
}

int	ft_syntax_cylinder(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_cylinder\n"RESET);
	if (ft_count_members(split) != 6)
		return (ft_printf(2, "Error, cylinder format is wrong\n"), 0);
	canvas->count.cylinder++;
	return (1);
}

int	ft_syntax_line(char **split, t_canvas *canvas)
{
	if (*split[0] == 'A')
		return (ft_syntax_ambient(canvas, split));
	else if (*split[0] == 'C')
		return (ft_syntax_camera(canvas, split));
	// else if (*split[0] == 'L')
	// 	return (ft_syntax_light(canvas, split));
	// else if (!ft_strcmp(*split, "sp"))
	// 	return (ft_syntax_sphere(canvas, split));
	// else if (!ft_strcmp(*split, "pl"))
	// 	return (ft_syntax_plane(canvas, split));
	// else if (!ft_strcmp(*split, "cy"))
	// 	return (ft_syntax_cylinder(canvas, split));
	// ft_printf(1, line);
	return (1);
}

int	ft_check_syntax(t_canvas *canvas, char *file)
{
	char	**split;
	char	*line;
	int		fd;
	int		error;

	(void)canvas;
	error = 1;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line && ft_strlen(line) > 0)
	{
		split = ft_split_charset(line, WHITESPACE);
		if (split && *split)
			error = ft_syntax_line(split, canvas);
		ft_free_split(split);
		line = ft_free(line);
		line = get_next_line(fd);
	}
	line = ft_free(line);
	close(fd);
	return (error);
}
