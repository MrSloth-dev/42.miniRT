#include "minirt.h"

bool	ft_camera_transform(int keysym, t_canvas *canvas)
{
	if (keysym == XK_z)
		canvas->camera.transf = canvas->camera.reset;
	else if (!canvas->object_selected && !canvas->light_selected)
		canvas->camera.transf = ft_transform_camera_key(
				canvas->camera.transf, keysym);
	else
		return (false);
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	return (true);
}
