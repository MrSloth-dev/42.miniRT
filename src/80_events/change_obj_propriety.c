#include "minirt.h"

static bool	ft_change_obj_dimension(int keysym, t_canvas *canvas)
{
	double	scl;

	scl = (double)canvas->shift_press / 10;
	if (keysym == XK_1)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0},
			(t_tuple){1 + scl, 1 + scl, 1 + scl, 0});
	else if (keysym == XK_2 && canvas->object_selected->type == CYLINDER)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0},
			(t_tuple){1, 1 + scl * 2, 1, 0});
	else if (keysym == XK_3 && canvas->object_selected->type == CYLINDER)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0},
			(t_tuple){1 + scl * 2, 1, 1 + scl * 2, 0});
	else
		return (false);
	return (true);
}

static bool	ft_change_obj_position(int keysym, t_canvas *canvas)
{
	if (keysym == XK_w)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0, 0.3, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_s)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0, -0.3, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_a)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){-0.3, 0, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_d)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0.3, 0, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_q)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0, 0, 0.3, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_e)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0, 0, -0.3, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else
		return (false);
	return (true);
}

static bool	ft_change_obj_rotation(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Left)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0}, (t_tuple){-0.3, 0, 0, 0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_Right)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0}, (t_tuple){0.3, 0, 0, 0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_Up)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0}, (t_tuple){0, 0, 0.3, 0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_Down)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0}, (t_tuple){0, 0, -0.3, 0}, (t_tuple){1, 1, 1, 0});
	else
		return (false);
	return (true);
}

bool	ft_change_obj_propriety(int keysym, t_canvas *canvas, bool state)
{
	if (canvas->object_selected)
	{
		mlx_do_key_autorepeaton(canvas->mlx);
		state = true;
		if (ft_change_obj_dimension(keysym, canvas))
			;
		else if (ft_change_obj_position(keysym, canvas))
			;
		else if (canvas->object_selected->type != SPHERE
			&& ft_change_obj_rotation(keysym, canvas))
			;
		else if (ft_change_object_color(keysym, canvas))
			;
		else
		{
			mlx_do_key_autorepeatoff(canvas->mlx);
			state = false;
		}
	}
	return (state);
}
