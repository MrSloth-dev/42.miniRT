#include "ft_printf.h"
#include "libft.h"
#include "minirt.h"

int	ft_vector_check(t_tuple tuple)
{
	if (tuple.x == -43.42)
		return (0);
	if (tuple.y == -43.42)
		return (0);
	if (tuple.z == -43.42)
		return (0);
	if (tuple.w == -43.42)
		return (0);
	return (1);
}

int	ft_rgb_check(t_color color)
{
	if (color.x < 0 || color.x > 255)
		return (0);
	if (color.y < 0 || color.y > 255)
		return (0);
	if (color.z < 0 || color.z > 255)
		return (0);
	return (1);
}

int	ft_norm_check(t_tuple norm)
{
	if (norm.x < -1 || norm.x > 1)
		return (0);
	if (norm.y < -1 || norm.y > 1)
		return (0);
	if (norm.z < -1 || norm.z > 1)
		return (0);
	if (norm.w < -1 || norm.w > 1)
		return (0);
	return (1);
}

int	ft_create_ambient(t_canvas *canvas, char **split)
{
	char	**color_split;
	t_color	color;

	canvas->ambient.ratio = ft_atod(split[1]);
	color_split = ft_split(split[2], ',');
	color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};
	if (ft_check_null_split(color_split)
		&& ft_rgb_check(color))
		canvas->ambient.color = color;
	else
		return (ft_free_split(color_split),
			ft_printf(2, "Error, ambient format is wrong\n"), 0);
	return (ft_free_split(color_split), canvas->count.ambient++, 0);
}

int	ft_create_camera(t_canvas *canvas, char **split)
{
	char	**coord_split;
	t_tuple	coord;
	char	**norm_split;
	t_tuple	norm;

	coord_split = ft_split(split[1], ',');
	coord = (t_tuple){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split) && ft_vector_check(coord))
		ft_free_split(coord_split);
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, camera coord values is wrong\n"), 0);
	canvas->camera.coord = coord;
	norm_split = ft_split(split[2], ',');
	norm = (t_tuple){ft_atod(norm_split[0]), ft_atod(norm_split[1]),
		ft_atod(norm_split[2]), 0};
	if (ft_check_null_split(norm_split)
		&& ft_norm_check(norm))
	{
		canvas->camera.norm = norm;
		ft_free_split(norm_split);
	}
	else
		return (ft_free_split(norm_split),
			ft_printf(2, "Error, camera norm value is wrong\n"), 0);
	canvas->camera.fov = ft_atoi(split[2]);
	return (canvas->count.camera++, 0);
}

int	ft_create_light(t_canvas *canvas, char **split)
{
	char	**coord_split;
	t_light light;
	char	**color_split;
	float	bright;

	coord_split = ft_split(split[1], ',');
	light.coord = (t_tuple){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split) && ft_vector_check(light.coord))
		canvas->light.coord = light.coord;
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, light format is wrong\n"), 0);
	ft_free_split(coord_split);
	color_split = ft_split(split[3], ',');
	light.color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};
	bright = ft_atoi(split[2]);
	light.color = ft_scalar_tuple(light.color, bright);
	if (ft_check_null_split(color_split) && ft_rgb_check(light.color))
		canvas->light.color = light.color;
	else
		return (ft_free_split(color_split),
			ft_printf(2, "Error, light format is wrong\n"), 0);
	ft_free_split(color_split);
	canvas->light = light;
	return (0);
}

int	ft_create_sphere(t_canvas *canvas, char **split)
{
	char	**coord_split;
	t_shapes	shape;
	t_tuple	coord;
	char	**color_split;
	t_color	color;

	shape.type = SPHERE;
	// shape.material = ft_create_material();


	coord_split = ft_split(split[1], ',');
	coord = (t_tuple){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split) && ft_vector_check(coord))
		shape.sph.coord = coord;
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, sphere format is wrong\n"), 0);
	ft_free_split(coord_split);

	color_split = ft_split(split[3], ',');
	color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};

	if (ft_check_null_split(color_split) && ft_rgb_check(color))
		shape.material.color = color;
	else
		return (ft_free_split(color_split),
			ft_printf(2, "Error, sphere color format is wrong\n"), 0);
	ft_free_split(color_split);

	shape.sph.diameter = ft_atod(split[2]);

	ft_get_transf_obj(&shape, shape.sph.coord, (t_tuple) {0}, (t_tuple) {shape.sph.diameter, shape.sph.diameter, shape.sph.diameter, 0});

	ft_lstadd_front(&canvas->objects, ft_lstnew(&shape));
	return (canvas->count.sphere++, 0);
}

int	ft_create_plane(t_canvas *canvas, char **split)
{
	char	**coord_split;
	t_tuple	coord;
	char	**color_split;
	t_color	color;
	char	**norm_split;
	t_tuple	norm;

	return 0;
	coord_split = ft_split(split[1], ',');
	coord = (t_tuple){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split) && ft_vector_check(coord))
		canvas->plane->coord = coord;
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, plane format is wrong\n"), 0);
	ft_free_split(coord_split);
	color_split = ft_split(split[3], ',');
	color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};
	if (ft_check_null_split(color_split) && ft_rgb_check(color))
	// 	canvas->plane.color = color;
	// else
		return (ft_free_split(color_split),
			ft_printf(2, "Error, plane color format is wrong\n"), 0);
	ft_free_split(color_split);
	norm_split = ft_split(split[2], ',');
	norm = (t_tuple){ft_atod(norm_split[0]), ft_atod(norm_split[1]),
		ft_atod(norm_split[2]), 0};
	if (ft_check_null_split(norm_split) && ft_norm_check(norm))
	{
		ft_free_split(norm_split);
	}
	else
		return (ft_free_split(norm_split),
			ft_printf(2, "Error, plane norm value is wrong\n"), 0);
	return (canvas->count.plane++, 0);
}

int	ft_create_cylinder(t_canvas *canvas, char **split)
{
	char	**coord_split;
	t_tuple	coord;
	char	**color_split;
	t_color	color;
	char	**norm_split;
	t_tuple	norm;
	int		i;

	return 0;
	i = canvas->count.cylinder;
	coord_split = ft_split(split[1], ',');
	coord = (t_tuple){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split) && ft_vector_check(coord))
		canvas->cylinder[i].coord = coord;
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, cylinder format is wrong\n"), 0);
	ft_free_split(coord_split);
	color_split = ft_split(split[5], ',');
	color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};
	if (ft_check_null_split(color_split) && ft_rgb_check(color))
	// 	canvas->cylinder[i].color = color;
	// else
		return (ft_free_split(color_split),
			ft_printf(2, "Error, cylinder color format is wrong\n"), 0);
	ft_free_split(color_split);
	norm_split = ft_split(split[2], ',');
	norm = (t_tuple){ft_atod(norm_split[0]), ft_atod(norm_split[1]),
		ft_atod(norm_split[2]), 0};
	if (ft_check_null_split(norm_split) && ft_norm_check(norm))
	{
		canvas->cylinder[i].norm = norm;
		ft_free_split(norm_split);
	}
	else
		return (ft_free_split(norm_split),
			ft_printf(2, "Error, cylinder norm value is wrong\n"), 0);
	canvas->cylinder[i].size.diameter = ft_atod(split[3]);
	canvas->cylinder[i].size.height = ft_atod(split[4]);
	return (canvas->count.cylinder++, 0);
}
