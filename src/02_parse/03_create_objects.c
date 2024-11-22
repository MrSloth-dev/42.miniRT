#include "minirt.h"

int	ft_create_ambient(t_canvas *canvas, char **split)
{
	char	**color_split;
	int		i;

	i = canvas->count.ambient;
	canvas->ambient[i].ratio = ft_atod(split[1]);
	color_split = ft_split(split[2], ',');
	if (ft_check_null_split(color_split)
		&& (ft_atod(color_split[1]) != -43.42
			&& ft_atod(color_split[1]) != -43.42
			&& ft_atod(color_split[2]) != -43.42))
	{
		canvas->ambient[i].color.r = ft_atod(color_split[0]);
		canvas->ambient[i].color.g = ft_atod(color_split[1]);
		canvas->ambient[i].color.b = ft_atod(color_split[2]);
	}
	else
		return (ft_free_split(color_split),
			ft_printf(2, "Error, ambient format is wrong\n"), 0);
	canvas->count.ambient++;
	return (0);
}

int	ft_create_camera(t_canvas *canvas, char **split)
{
	char	**coord_split;
	char	**norm_split;
	int		i;

	i = canvas->count.camera;
	coord_split = ft_split(split[1], ',');
	if (ft_check_null_split(coord_split)
		&& (ft_atod(coord_split[1]) != -43.42
			&& ft_atod(coord_split[1]) != -43.42
			&& ft_atod(coord_split[2]) != -43.42))
	{
		canvas->camera[i].coord.x = ft_atod(coord_split[0]);
		canvas->camera[i].coord.y = ft_atod(coord_split[1]);
		canvas->camera[i].coord.z = ft_atod(coord_split[2]);
		// canvas->camera[i].coord.w = 1;
		ft_free_split(coord_split);
	}
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, camera format is wrong\n"), 0);
	norm_split = ft_split(split[2], ',');
	if (ft_check_null_split(norm_split)
		&& (ft_atod(norm_split[1]) != -43.42
			&& ft_atod(norm_split[1]) != -43.42
			&& ft_atod(norm_split[2]) != -43.42))
	{
		canvas->camera[i].norm.x = ft_atod(norm_split[0]);
		canvas->camera[i].norm.y = ft_atod(norm_split[1]);
		canvas->camera[i].norm.z = ft_atod(norm_split[2]);
		canvas->camera[i].norm.w = 0;
		ft_free_split(norm_split);
	}
	else
		return (ft_free_split(norm_split),
			ft_printf(2, "Error, camera format is wrong\n"), 0);
	canvas->camera[i].fov = ft_atoi(split[2]);
	canvas->count.camera++;
	return (0);
}

int	ft_create_light(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_light\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, light format is wrong\n"), 0);
	canvas->count.light++;
	return (0);
}

int	ft_create_sphere(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_sphere\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, sphere format is wrong\n"), 0);
	(void)canvas;
	return (0);
}

int	ft_create_plane(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_plane\n"RESET);
	if (ft_count_members(split) != 4)
		return (ft_printf(2, "Error, plane format is wrong\n"), 0);
	canvas->count.plane++;
	return (0);
}

int	ft_create_cylinder(t_canvas *canvas, char **split)
{
	ft_printf(2, RED"_cylinder\n"RESET);
	if (ft_count_members(split) != 6)
		return (ft_printf(2, "Error, cylinder format is wrong\n"), 0);
	canvas->count.cylinder++;
	return (0);
}
