#include "ft_printf.h"
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

int	ft_parse_ambient(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_ambient\n"RESET);
	if (ft_count_members(split) != 3)
		return (ft_printf(2, "Error, ambient format is wrong\n"), 0);
	(void)canvas;
	if (!split)
		return (0);
	return (0);
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

int	ft_check_syntax(t_canvas *canvas, char *file)
{
	int	fd;
	char	*line;

	(void)canvas;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		char **split;

		split = ft_split_charset(line, WHITESPACE);
		if (split && *split)
		{
			if (*split[0] == 'A')
				ft_parse_ambient(canvas, split);
			else if (*split[0] == 'C')
				ft_parse_camera(canvas, split);
			else if (*split[0] == 'L')
				ft_parse_light(canvas, split);
			else if (!ft_strcmp(*split, "sp"))
				ft_parse_sphere(canvas, split);
			else if (!ft_strcmp(*split, "pl"))
				ft_parse_plane(canvas, split);
			else if (!ft_strcmp(*split, "cy"))
				ft_parse_cylinder(canvas, split);
			// ft_printf(1, line);
		}
		ft_free_split(split);
		line = ft_free(line);
		line = get_next_line(fd);
	}
	line = ft_free(line);
	return (1);
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
	if (ft_check_file(file) && ft_check_syntax(canvas, file)
		&& ft_parse_objects(canvas))
		return (1);
	return (0);
}
