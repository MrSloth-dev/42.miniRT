#include "minirt.h"

static int	ft_check_file(char *file)
{
	int	dotindex;
	int	len;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (close(fd), ft_printf(2, "Error\nFile not found\n"), 0);
	close(fd);
	len = ft_strlen(file);
	ft_printf(2, "%s\n", ft_strrchr(file, '/'));
	if (!ft_strchr(file, '.') || len < 4 || !ft_strchr(ft_strrchr(file, '/'), '.'))
		return (ft_printf(2, "Error\nFile not wtf valid\n"), 0);
	if (len > 4 && file[len - 3] == '/')
		return (ft_printf(2, "Error\nFile not valid sneaker basterd!\n"), 0);
	dotindex = 0;
	while (file && file[dotindex] != '.')
		dotindex++;
	if (dotindex == len - 3 && file[dotindex + 1] == 'r' && file[dotindex + 2] == 't')
		return (ft_printf(1, "File Accepted!\n"), 1);
	return (ft_printf(2, "Error\n File not valid end of line\n"), 0);
}

static int	ft_parse_line(char **split, t_canvas *canvas)
{
	if (*split[0] == 'A')
		return (ft_create_ambient(canvas, split));
	else if (*split[0] == 'C')
		return (ft_create_camera(canvas, split));
	else if (*split[0] == 'L')
		return (ft_create_light(canvas, split));
	else if (!ft_strcmp(*split, "sp"))
		return (ft_create_sphere(canvas, split));
	else if (!ft_strcmp(*split, "pl"))
		return (ft_create_plane(canvas, split));
	else if (!ft_strcmp(*split, "cy"))
		return (ft_create_cylinder(canvas, split));
	else
		return (1);
	return (1);
}

static int	ft_parse_objects(t_canvas *canvas)
{
	char	**split;
	char	*line;
	int		fd;
	int		error;

	error = 1;
	fd = open(canvas->file, O_RDONLY);
	line = get_next_line(fd, &canvas->gnl_rest);
	while (line)
	{
		split = ft_split_charset(line, WHITESPACE);
		if (split && *split)
			error = ft_parse_line(split, canvas);
		// ok, if i don't have error on last line, and have error in other?
		// i think you can do like this:
		// error += ft_parse_line(split, canvas);
		line = ft_free(line);
		ft_free_split(split);
		if (error)
			break ;
		line = get_next_line(fd, &canvas->gnl_rest);
	}
	line = ft_free(line);
	close(fd);
	return (error);
}

static void	ft_set_objects_material_color(t_canvas *canvas)
{
	t_list *cur;

	if (!canvas->objects)
		return ;
	cur = canvas->objects;
	while (cur && cur->cont)
	{
		((t_shapes *)cur->cont)->material.ambient_color = canvas->ambient.color;
		((t_shapes *)cur->cont)->selected = false;
		cur = cur->next;
	}
}

static int	ft_parser_elements(t_canvas *canvas)
{
	ft_parse_objects(canvas);
	ft_set_objects_material_color(canvas);
	return (1);
}

int	ft_parse(t_canvas *canvas, char *file)
{
	canvas->file = file;
	if (ft_check_file(file)
		&& ft_check_syntax(canvas, file)
		&& ft_parser_elements(canvas))
		return (1);
	return (0);
}
