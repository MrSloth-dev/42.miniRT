#include "minirt.h"

void	*ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		split[i] = ft_free(split[i]);
		i++;
	}
	if (split)
		split = ft_free(split);
	return (NULL);
}

int	ft_count_members (char **split)
{
	int	count;

	count = 0;
	while (*split++)
		count++;
	return (count);
}

int	ft_check_null_split(char **split)
{
	while(*split)
	{

		if (ft_strlen(*split) == 0)
			return (0);
		split++;
	}
	return (1);

}
int	ft_parse_ambient(t_canvas *canvas, char **split)
{
	char	**color_split;
	t_ambient	*ambient;
	ambient = NULL;
	if (!split)
		return (0);
	ft_printf(2, RED"_ambient\n"RESET);
	if (ft_count_members(split) != 3)
		return (ft_printf(2, "Error, ambient format is wrong\n"), 0);
	ambient->ratio = ft_atod(split[1]);
	color_split = ft_split(split[2], ',');
	if (ft_check_null_split(color_split))
	{
		ambient->color.r = ft_atod(color_split[0]);
		ambient->color.g = ft_atod(color_split[1]);
		ambient->color.b = ft_atod(color_split[2]);
	}
	else
		return (ft_free_split(color_split), ft_printf(2, "Error, ambient format is wrong\n"), 0);
	ft_add_object((void **)canvas->ambient, (void *)ambient);
	// canvas->ambient = ft_lstnew_ambient(ambient.ratio, ambient.color);
	
	// canvas->ambient = canvas->ambient->next;
	return (ft_free_split(color_split), 0);
}
int	ft_parse_camera(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_camera\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, camera format is wrong\n"), 0);
	(void)canvas;
	if (!split)
		return (0);
	return (0);
}
int	ft_parse_light(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_light\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, light format is wrong\n"), 0);
	(void)canvas;
	if (!split)
		return (0);
	return (0);
}
int	ft_parse_sphere(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_sphere\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, sphere format is wrong\n"), 0);
	(void)canvas;
	if (!split)
		return (0);
	return (0);
}
int	ft_parse_plane(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_plane\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, plane format is wrong\n"), 0);
	(void)canvas;
	if (!split)
		return (0);
	return (0);
}
int	ft_parse_cylinder(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_cylinder\n"RESET);
	if (ft_count_members(split) != 6)
		return (ft_printf(2, "Error, cylinder format is wrong\n"), 0);
	(void)canvas;
	if (!split)
		return (0);
	return (0);
}

int	ft_parse_line(char **split, t_canvas *canvas)
{
	if (*split[0] == 'A')
		return (ft_parse_ambient(canvas, split));
	else if (*split[0] == 'C')
		return (ft_parse_camera(canvas, split));
	else if (*split[0] == 'L')
		return (ft_parse_light(canvas, split));
	else if (!ft_strcmp(*split, "sp"))
		return (ft_parse_sphere(canvas, split));
	else if (!ft_strcmp(*split, "pl"))
		return (ft_parse_plane(canvas, split));
	else if (!ft_strcmp(*split, "cy"))
		return (ft_parse_cylinder(canvas, split));
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
	while (line)
	{
		split = ft_split_charset(line, WHITESPACE);
		if (split && *split)
			error = ft_parse_line(split, canvas);
		ft_free_split(split);
		line = ft_free(line);
		line = get_next_line(fd);
	}
	line = ft_free(line);
	close(fd);
	return (error);
}

int	ft_check_file(char *file)
{
	int dotindex;
	int len;


	len = ft_strlen(file);
	if (!file || !ft_strchr(file, '.') || len < 4)
	 return (ft_printf(2, "Error, file not valid\n"), 0);
	dotindex = 0;
	while (file && file[dotindex] != '.')
		dotindex++;
	if (dotindex == len - 3)
		if (file[dotindex + 1] == 'r' && file[dotindex + 2] == 't' )
		return (ft_printf(2, "File Accepted!\n"), 1);
	return (ft_printf(2, "Error, file not valid\n"), 0);
}

int	ft_parse_objects(t_canvas *canvas)
{
	(void)canvas;
	return 1;
}
int	ft_parse(t_canvas *canvas, char *file)
{
	if (ft_check_file(file)
		&& ft_check_syntax(canvas, file)
		&& ft_parse_objects(canvas))
		return (1);
	return (0);
}
