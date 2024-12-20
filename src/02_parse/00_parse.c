#include "minirt.h"
#include <fcntl.h>

int	ft_check_file(char *file)
{
	int dotindex;
	int len;
	int fd;

	fd = open(file, O_RDONLY);
	printf("%d\n", fd);
	len = ft_strlen(file);
	if (fd == -1 || (!file || !ft_strchr(file, '.') || len < 4))
	 return (close(fd), perror("Error, file not valid\n"), 0);
	dotindex = 0;
	while (file && file[dotindex] != '.')
		dotindex++;
	if (dotindex == len - 3)
		if (file[dotindex + 1] == 'r' && file[dotindex + 2] == 't')
		return (close(fd), ft_printf(2, "File Accepted!\n"), 1);
	return (close(fd), perror("Error, file not valid\n"), 0);
}

int	ft_parse_line(char **split, t_canvas *canvas)
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

int	ft_parse_objects(t_canvas *canvas)
{
	char	**split;
	char	*line;
	int		fd;
	int		error;

	error = 1;
	fd = open(canvas->file, O_RDONLY);
	line = get_next_line(fd);
	while (*line)
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

int	ft_parser(t_canvas *canvas)
{
	ft_parse_objects(canvas);
	return (1);
}

int	ft_parse(t_canvas *canvas, char *file)
{
	canvas->file = file;
	if (ft_check_file(file)
		&& ft_check_syntax(canvas, file)
		&& ft_parser(canvas))
		return (1);
	return (0);
}
