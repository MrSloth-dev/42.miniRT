#include "ft_printf.h"
#include "libft.h"
#include "minirt.h"
#include <math.h>

int	ft_vector_check(t_tuple tuple)
{
	if (ft_is_float_equal(tuple.x, -43.42))
		return (0);
	if (ft_is_float_equal(tuple.y, -43.42))
		return (0);
	if (ft_is_float_equal(tuple.z, -43.42))
		return (0);
	if (ft_is_float_equal(tuple.w, -43.42))
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

double	ft_get_double(char *str, char *element, t_canvas *canvas)
{
	double	value;

	value = ft_atod(str);
	if (ft_is_float_equal(value, -43.42))
		return (ft_printf(2, "Error\n%s ratio format is wrong\n", element),
			ft_free_objects(canvas->objects), value);
	return (value);
}

int	ft_check_values(double a, double b, double c)
{
	if (ft_is_float_equal(a, -43.42)
		|| ft_is_float_equal(b, -43.42)
		|| ft_is_float_equal(c, -43.42))
		return (0);
	return (1);
}

t_tuple	ft_get_norm(char *str, char *element, t_canvas *canvas)
{
	char	**norm_split;
	t_tuple	norm;

	norm_split = ft_split(str, ',');
	norm = (t_color){ft_atod(norm_split[0]), ft_atod(norm_split[1]),
		ft_atod(norm_split[2]), 3};
	if (ft_check_null_split(norm_split)
		&& ft_vector_check(norm))
		return (ft_free_split(norm_split), norm);
	else
		return (ft_free_split(norm_split),
			ft_printf(2, "Error\n%s normal format is wrong\n", element),
			ft_free_objects(canvas->objects),
			(t_tuple){-43.42, -43.42, -43.42, -1});
}

t_tuple	ft_get_coord(char *str, char *element, t_canvas *canvas)
{
	char	**coord_split;
	t_tuple	coord;

	coord_split = ft_split(str, ',');
	coord = (t_color){ft_atod(coord_split[0]), ft_atod(coord_split[1]),
		ft_atod(coord_split[2]), 3};
	if (ft_check_null_split(coord_split)
		&& ft_check_values(coord.x, coord.y, coord.z))
		return (ft_free_split(coord_split), coord);
	else
		return (ft_free_split(coord_split),
			ft_printf(2, "Error\n%s coord format is wrong\n", element),
			ft_free_objects(canvas->objects),
			(t_color){-43.42, -43.42, -43.42, -1});
}

t_color	ft_get_color(char *str, char *element, t_canvas *canvas)
{
	char	**color_split;
	t_color	color;

	color_split = ft_split(str, ',');
	color = (t_color){ft_atod(color_split[0]), ft_atod(color_split[1]),
		ft_atod(color_split[2]), 3};
	if (ft_check_null_split(color_split))
		return (ft_free_split(color_split), color);
	else if (!ft_rgb_check(color))
		return (ft_free_split(color_split),
			ft_printf(2, "Error\n%s color is out of bounds [0-255]\n", element),
			ft_free_objects(canvas->objects),
			(t_color){-43.42, -43.42, -43.42, -1});
	else
		return (ft_free_split(color_split),
			ft_printf(2, "Error\n%s color format is wrong\n", element),
			ft_free_objects(canvas->objects),
			(t_color){-43.42, -43.42, -43.42, -1});
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
int	ft_create_ambient(t_canvas *canvas, char **split)
{
	t_ambient	amb;

	amb.ratio = ft_get_double(split[1], "Ambient", canvas);
	if (amb.ratio < 0 || amb.ratio > 1)
		return (ft_printf(2, "Error\nAmbient value is out of bounds[0,1]\n"), 0);
	amb.color = ft_get_color(split[2], "Ambient", canvas);
	if (amb.color.w == -1)
		return (0);
	canvas->ambient.color = ft_scalar_tuple(ft_scalar_tuple(amb.color,
				amb.ratio), 0.1f / 25.5f);
	return (1);
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
int	ft_create_light(t_canvas *canvas, char **split)
{
	t_light light;
	double	bright;

	bright = ft_get_double(split[2], "Light", canvas);
	if (bright != -43.42 && (bright < 0 || bright > 1))
		return (ft_printf(2, "Error\nLight value is out of bounds[0,1]\n"), 0);
	else if (bright == -43.42)
		return (0);
	light.coord = ft_get_coord(split[1], "Light", canvas);
	light.color = ft_get_color(split[3], "Light", canvas);
	if (light.color.w == -1 || light.coord.w == -1)
		return (0);
	light.color = ft_scalar_tuple(light.color, bright);
	light.color = ft_scalar_tuple(light.color, 1.0f / 25.5f);
	light.intensity = ft_scalar_tuple(light.color, bright / 90);
	canvas->light = light;
	return (1);
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
int	ft_create_camera(t_canvas *canvas, char **split)
{
	t_camera	cam;

	cam.coord = ft_get_coord(split[1], "Camera", canvas);
	canvas->camera.coord = cam.coord;
	cam.norm = ft_get_norm(split[2], "Camera", canvas);
	if (cam.coord.w == -1 || cam.norm.w == -1)
		return (0);
	canvas->camera.field_v = ft_get_double(split[3], "Camera", canvas);
	if (canvas->camera.field_v == -42.43)
		return (0);
	canvas->camera.field_v *= M_PI / 180;
	ft_create_world_camera(IMG_W, IMG_H, canvas);
	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,
			ft_add_tuple(canvas->camera.coord, canvas->camera.norm),
			(t_tuple){0, 1, 0, 0});
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	canvas->camera.reset = canvas->camera.transf;
	return (1);
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
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
	return (1);
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
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
	return (1);
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
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
	shape->cyl.size.max = shape->cyl.size.height / 2;
	shape->cyl.size.min = -shape->cyl.size.max; 
	ft_get_transf_obj(shape, shape->cyl.coord, shape->cyl.norm,
		   (t_tuple) {shape->cyl.size.diameter, 1, shape->cyl.size.diameter, 0});
	ft_lstadd_back(&canvas->objects, ft_lstnew(shape));
	return (1);
}
