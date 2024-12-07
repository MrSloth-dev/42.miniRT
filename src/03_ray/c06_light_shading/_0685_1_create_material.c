#include "minirt.h"

t_material ft_create_material(void)
{
	t_material	m;
	m.color = (t_color){1, 1, 1, 3};
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0f;
	return (m);
}
