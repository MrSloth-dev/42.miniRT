#include "minirt.h"

void	ft_init_canvas(t_canvas *canvas)
{
	canvas->ambient = ft_lstnew_ambient(0, (t_color){0, 0, 0});
	canvas->camera = ft_lstnew_camera((t_tuple){0, 0, 0, 0}, (t_tuple){0, 0, 0, 0}, 0);
	canvas->light = ft_lstnew_light((t_tuple){0, 0, 0, 0}, 0, (t_color){0, 0, 0});
	canvas->sphere = ft_lstnew_sphere((t_tuple){0, 0, 0, 0}, 0, (t_color){0, 0, 0});
	canvas->plane = ft_lstnew_plane((t_tuple){0, 0, 0, 0},(t_tuple){0, 0, 0, 0}, (t_color){0, 0, 0});
	canvas->cylinder = ft_lstnew_cylinder((t_tuple){0, 0, 0, 0},(t_tuple){0, 0, 0, 0}, (t_cyl_size){0, 0}, (t_color){0, 0, 0});
}
