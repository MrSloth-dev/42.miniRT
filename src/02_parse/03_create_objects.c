#include "ft_printf.h"
#include "libft.h"
#include "minirt.h"
#include <math.h>

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

t_shapes	*ft_create_default_shape(int type)
{
	t_shapes	*new;

	new = malloc(sizeof(t_shapes));
	new->type = type;
	new->material = ft_create_material();
	new->inverted = ft_create_matrix(4, 4, 1);
	new->transposed = ft_create_matrix(4, 4, 1);
	new->transform = ft_create_matrix(4, 4, 1);
	return (new);
}

int	ft_create_ambient(t_canvas *canvas, char **split)
{
	char	**color_split;
	t_ambient amb;

	amb.ratio = ft_atod(split[1]);
	color_split = ft_split(split[2], ',');
	amb.color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};
	if (ft_check_null_split(color_split)
		&& ft_rgb_check(amb.color))
		canvas->ambient.color = ft_scalar_tuple(ft_scalar_tuple(amb.color, amb.ratio), 1.0f / 25.5f);
	else
		return (ft_free_split(color_split),
			ft_printf(2, "Error, ambient format is wrong\n"), 0);
	return (ft_free_split(color_split), 0);
}

int	ft_create_camera(t_canvas *canvas, char **split)
{
	char	**coord_split;
	t_camera cam;
	char	**norm_split;

	coord_split = ft_split(split[1], ',');
	cam.coord = (t_tuple){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split) && ft_vector_check(cam.coord))
		ft_free_split(coord_split);
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, camera coord values is wrong\n"), 0);
	canvas->camera.coord = cam.coord;
	norm_split = ft_split(split[2], ',');
	cam.norm = (t_tuple){ft_atod(norm_split[0]), ft_atod(norm_split[1]),
		ft_atod(norm_split[2]), 0};
	if (ft_check_null_split(norm_split)
		&& ft_norm_check(cam.norm))
	{
		canvas->camera.norm = cam.norm;
		ft_free_split(norm_split);
	}
	else
		return (ft_free_split(norm_split),
			ft_printf(2, "Error, camera norm value is wrong\n"), 0);
	canvas->camera.fov = ft_atod(split[3]) * M_PI / 180;
	return (0);
}

int	ft_create_light(t_canvas *canvas, char **split)
{
	char	**coord_split;
	t_light light;
	char	**color_split;
	double	bright;

	coord_split = ft_split(split[1], ',');
	light.coord = (t_tuple){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split) && ft_vector_check(light.coord))
		light.coord = light.coord;
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, light format is wrong\n"), 0);
	ft_free_split(coord_split);
	color_split = ft_split(split[3], ',');
	light.color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};
	bright = ft_atod(split[2]);
	light.color = ft_scalar_tuple(light.color, bright);
	if (ft_check_null_split(color_split) && ft_rgb_check(light.color))
		light.color = ft_scalar_tuple(light.color, 1.0f / 25.5f);
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
	t_tuple	coord;
	char	**color_split;
	t_color	color;
	t_shapes	*shape;

	shape = ft_create_default_shape(SPHERE);
	coord_split = ft_split(split[1], ',');
	coord = (t_tuple){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split) && ft_vector_check(coord))
		shape->sph.coord = coord;
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, sphere format is wrong\n"), 0);
	ft_free_split(coord_split);

	color_split = ft_split(split[3], ',');
	color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};

	if (ft_check_null_split(color_split) && ft_rgb_check(color))
		shape->material.color = ft_scalar_tuple(color, 1.0f / 255.0f);
	else
		return (ft_free_split(color_split),
			ft_printf(2, "Error, sphere color format is wrong\n"), 0);
	ft_free_split(color_split);

	shape->sph.diameter = ft_atod(split[2]) / 2;
	shape->material.ambient = shape->material.ambient;

	ft_get_transf_obj(shape, coord, (t_tuple) {0}, (t_tuple){shape->sph.diameter, shape->sph.diameter, shape->sph.diameter, 0});
	ft_lstadd_back(&canvas->objects, ft_lstnew(shape));
	return (0);
}

int	ft_create_plane(t_canvas *canvas, char **split)
{
	char	**coord_split;
	t_tuple	coord;
	t_color	color;
	char	**color_split;
	char	**norm_split;
	t_tuple	norm;
	t_shapes	*shape;

	shape = ft_create_default_shape(PLANE);
	coord_split = ft_split(split[1], ',');
	coord = (t_tuple){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split) && ft_vector_check(coord))
		shape->pla.coord = coord;
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, plane format is wrong\n"), 0);
	ft_free_split(coord_split);
	color_split = ft_split(split[3], ',');
	color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};
	if (ft_check_null_split(color_split) && ft_rgb_check(color))
		shape->material.color = ft_scalar_tuple(color, 1 / 255.f);
	else
		return (ft_free_split(color_split),
			ft_printf(2, "Error, plane color format is wrong\n"), 0);
	ft_free_split(color_split);
	norm_split = ft_split(split[2], ',');
	norm = (t_tuple){ft_atod(norm_split[0]), ft_atod(norm_split[1]),
		ft_atod(norm_split[2]), 0};
	if (ft_check_null_split(norm_split) && ft_norm_check(norm))
	{
		if (ft_is_tuples_equal(norm, (t_tuple){0}))
			shape->pla.norm = (t_tuple){0, 1, 0 ,0};
		else
			shape->pla.norm = norm;
		ft_free_split(norm_split);
	}
	else
		return (ft_free_split(norm_split),
			ft_printf(2, "Error, plane norm value is wrong\n"), 0);
	shape->material.ambient = shape->material.ambient;
	ft_get_transf_obj(shape, shape->pla.coord, shape->pla.norm, (t_tuple) {1, 1, 1, 0});

	ft_lstadd_back(&canvas->objects, ft_lstnew(shape));
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
	t_shapes	*shape;

	shape = ft_create_default_shape(CYLINDER);

	coord_split = ft_split(split[1], ',');
	coord = (t_tuple){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 1};
	if (ft_check_null_split(coord_split) && ft_vector_check(coord))
		shape->cyl.coord = coord;
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error, cylinder format is wrong\n"), 0);
	ft_free_split(coord_split);

	color_split = ft_split(split[5], ',');

	color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};
	if (ft_check_null_split(color_split) && ft_rgb_check(color))
		shape->material.color = ft_scalar_tuple(color, 1 / 255.f);
	else
		return (ft_free_split(color_split),
			ft_printf(2, "Error, cylinder color format is wrong\n"), 0);

	ft_print_tuple(shape->material.color, "cyl color");
	ft_free_split(color_split);
	norm_split = ft_split(split[2], ',');
	norm = (t_tuple){ft_atod(norm_split[0]), ft_atod(norm_split[1]),
		ft_atod(norm_split[2]), 0};
	if (ft_check_null_split(norm_split) && ft_norm_check(norm))
	{
		shape->cyl.norm = norm;
		ft_free_split(norm_split);
	}
	else
		return (ft_free_split(norm_split),
			ft_printf(2, "Error, cylinder norm value is wrong\n"), 0);
	shape->cyl.size.diameter = ft_atod(split[3]) / 2;
	shape->cyl.size.height = ft_atod(split[4]);
	ft_get_transf_obj(shape, shape->cyl.coord, shape->cyl.norm, (t_tuple) {shape->cyl.size.diameter, shape->cyl.size.height, shape->cyl.size.diameter, 0});
	ft_lstadd_back(&canvas->objects, ft_lstnew(shape));
	return (0);
}
