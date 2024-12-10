#include "minirt.h"

void	ft_init_canvas(t_canvas *canvas)
{
	(void)canvas;
	canvas->count.ambient = 0;
	canvas->count.camera = 0;
	canvas->count.light = 0;

	canvas->objects = NULL;
	canvas->light = ft_init_light((t_tuple){0, 0, 0, 0}, 0.0f, (t_color){0, 0, 0, 0});
	canvas->ambient = ft_init_ambient(0, (t_color){0, 0, 0, 0});
	canvas->camera = ft_init_camera((t_tuple){0, 0, 0, 0}, (t_tuple){0, 0, 0, 0}, 0);
	//descomentei abaixo
}
