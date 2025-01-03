#include "libft.h"
#include "minirt.h"

void	ft_init_canvas(t_canvas *canvas)
{
	(void)canvas;
	canvas->count.ambient = 0;
	canvas->count.camera = 0;
	canvas->count.light = 0;
	canvas->help = 0;
	canvas->step = STEP;
	ft_bzero(canvas->char_step, 2);
	canvas->drag = 0;
	canvas->mouse_x = 0;
	canvas->mouse_y = 0;
	canvas->mouse_calc = 0;

	canvas->objects = NULL;
	canvas->light = ft_init_light((t_tuple){0, 0, 0, 0}, 0.0f, (t_color){0, 0, 0, 0});
	canvas->ambient = ft_init_ambient(0, (t_color){0, 0, 0, 0});
	//descomentei abaixo
}
