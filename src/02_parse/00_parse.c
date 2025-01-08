/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:34:19 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:34:19 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_check_file(char *file)
{
	int	dotindex;
	int	len;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1 || !file)
		return (close(fd), ft_printf(2, "Error\nFile not found\n"), 0);
	close(fd);
	len = ft_strlen(file);
	if (!ft_strchr(file, '.') || len < 4)
		return (ft_printf(2, "Error\nFile not valid\n"), 0);
	if (len > 4 && file[len - 4] == '/')
		return (ft_printf(2, "Error\nFile not valid\n"), 0);
	dotindex = len;
	while (file && file[dotindex] != '.')
		dotindex--;
	if (dotindex == len - 3 && file[dotindex + 1] == 'r'
		&& file[dotindex + 2] == 't')
		return (1);
	return (ft_printf(2, "Error\n File not valid\n"), 0);
}

static int	ft_parse_line(char **split, t_canvas *canvas)
{
	if (!ft_strcmp(*split, "A"))
		return (ft_create_ambient(canvas, split));
	else if (!ft_strcmp(*split, "C"))
		return (ft_create_camera(canvas, split));
	else if (!ft_strcmp(*split, "L"))
		return (ft_create_light(canvas, split));
	else if (!ft_strcmp(*split, "sp"))
		return (ft_create_sphere(canvas, split));
	else if (!ft_strcmp(*split, "pl"))
		return (ft_create_plane(canvas, split));
	else if (!ft_strcmp(*split, "cy"))
		return (ft_create_cylinder(canvas, split));
	return (1);
}

static int	ft_parse_objects(t_canvas *canvas)
{
	char	**split;
	char	*line;
	int		fd;
	int		ok;

	ok = 1;
	fd = open(canvas->file, O_RDONLY);
	line = get_next_line(fd, &canvas->gnl_rest);
	while (line && *line && ok)
	{
		split = ft_split_charset(line, WHITESPACE);
		if (split && *split)
			ok = ft_parse_line(split, canvas);
		ft_free_split(split);
		line = ft_free(line);
		line = get_next_line(fd, &canvas->gnl_rest);
	}
	line = ft_free(line);
	canvas->gnl_rest = ft_free(canvas->gnl_rest);
	close(fd);
	return (ok);
}

static void	ft_set_objects_material_color(t_canvas *canvas)
{
	t_list	*cur;

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

int	ft_parse(t_canvas *canvas, char *file)
{
	canvas->file = file;
	if (ft_check_file(file)
		&& ft_check_syntax(canvas, file)
		&& ft_parse_objects(canvas))
		return (ft_set_objects_material_color(canvas), 1);
	return (0);
}
