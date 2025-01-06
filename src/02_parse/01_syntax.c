#include "ft_printf.h"
#include "minirt.h"

int	ft_syntax_ambient(t_canvas *canvas, char **split)
{
	if (!split)
		return (0);
	if (ft_count_members(split) != 3)
		return (ft_printf(2, "Error, ambient format is wrong\n"), 0);
	canvas->count.ambient++;
	return (1);
}

int	ft_syntax_camera(t_canvas *canvas, char **split)
{
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, camera format is wrong\n"), 0);
	canvas->count.camera++;
	return (1);
}

int	ft_syntax_light(t_canvas *canvas, char **split)
{
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, light format is wrong\n"), 0);
	canvas->count.light++;
	return (1);
}

int	ft_syntax_sphere(t_canvas *canvas, char **split)
{
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, sphere format is wrong\n"), 0);
	(void)canvas;
	return (1);
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

int	ft_syntax_line(char **split, t_canvas *canvas)
{
	if (!split)
		return (1);
	if (*split[0] == 'A')
		return (ft_syntax_ambient(canvas, split));
	else if (*split[0] == 'C')
		return (ft_syntax_camera(canvas, split));
	else if (*split[0] == 'L')
		return (ft_syntax_light(canvas, split));
	else if (!ft_strcmp(*split, "sp"))
		return (ft_syntax_sphere(canvas, split));
	else if (!ft_strcmp(*split, "pl"))
		return (ft_syntax_plane(canvas, split));
	else if (!ft_strcmp(*split, "cy"))
		return (ft_syntax_cylinder(canvas, split));
	return (1);
}

int	ft_check_count(t_canvas *canvas)
{
	if (canvas->count.light > 1)
		return (ft_printf(2, "Error\nMore than one light"), 0);
	if(canvas->count.camera > 1)
		return (ft_printf(2, "Error\nMore than one camera"), 0);
	if(canvas->count.ambient > 1)
		return (ft_printf(2, "Error\nMore than one ambient"), 0);
	return (1);
}

int	ft_check_syntax(t_canvas *canvas, char *file)
{
	char	**split;
	char	*line;
	int		fd;
	int		error;

	error = 1;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd, &canvas->gnl_rest);
	while (line && ft_strlen(line) > 0)
	{
		split = ft_split_charset(line, WHITESPACE);
		if (split)
			error = ft_syntax_line(split, canvas);
		// this var must sum result in every iteration
		ft_free_split(split);
		line = ft_free(line);
		line = get_next_line(fd, &canvas->gnl_rest);
		error = ft_check_count(canvas);
		if (error == 0)
			break;
	}
	if (canvas->count.light < 1 || canvas->count.camera < 1 || canvas->count.ambient < 1)
		return (ft_printf(2, "Error\nMust have at least one light, camera and ambient\n"), 0);
	line = ft_free(line);
	return (close(fd), error);
}
