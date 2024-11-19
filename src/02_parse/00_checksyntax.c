#include "ft_printf.h"
#include "minirt.h"

int	ft_check_syntax(t_canvas *canvas, char *file)
{
	int	fd;
	char	*line;

	(void)canvas;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf(1, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
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
