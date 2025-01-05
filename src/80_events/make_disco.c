#include "minirt.h"


static void	ft_set_color(t_canvas *canvas, double r, double g, double b)
{
	t_objects	*cur;
	t_shapes	*cur_shape;
	double		dance;

	dance = canvas->disco_dance;

	canvas->light.color = (t_tuple){r, g, b, 3};
	cur = canvas->objects;
	while (cur)
	{
		cur_shape = cur->cont;
		if (cur_shape->type != PLANE)
		{
			ft_get_transf_obj(cur_shape,
			(t_tuple){dance, dance, dance, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
		}
		cur = cur->next;
	}
	canvas->disco_dance = -dance;;
}

static void	ft_backup_light_ambient(t_canvas *canvas, char to_do)
{
	if (to_do == 'b')
	{
		canvas->light.prev_color = canvas->light.color;
		canvas->light.prev_intensity = canvas->light.intensity;
		canvas->ambient.prev_color = canvas->ambient.color;
	}
	else
	{
		canvas->light.color = canvas->light.prev_color;
		canvas->light.intensity = canvas->light.prev_intensity;
		canvas->ambient.color = canvas->ambient.prev_color;
	}
}

bool	ft_make_disco(int key, t_canvas *canvas)
{
	unsigned int	change;
	int		type;
	int		done;
	unsigned int		local_step;
	unsigned int		strob;
	t_color	up_color;
	t_color	up_inten;


	if (canvas->step == 1 || canvas->shift_press == 1)
		return (false);
	else if (canvas->step > 10)
		local_step = canvas->step * 8000000;
	else if (canvas->step > 2)
		local_step = canvas->step * 16000000;
	else
		local_step = canvas->step * 5000000;
	up_color = (t_tuple){3, 3, 3, 3};
	up_inten = (t_tuple){0.06, 0.06, 0.06, 3};
	strob = local_step / 6;
	change = 0;
	type = 0;
	done = 0;
	ft_backup_light_ambient(canvas, 'b');
	if (key == XK_0)
	{
		while (1)
		{
			if (change == 0)
			{
				double		hi;
				double		lo;

				hi = 10;
				lo = 2;

				//canvas->ambient.color = canvas->ambient.prev_color;	
				type++;
				if (type == 1)
					ft_set_color(canvas, hi, lo, lo);
				else if (type == 2)		
					ft_set_color(canvas, lo, hi, hi);
				else if (type == 3)
					ft_set_color(canvas, lo, lo, hi);
				else if (type == 4)			
					ft_set_color(canvas, hi, hi, lo);
				else if (type == 5)
					ft_set_color(canvas, lo, hi, lo);
				else if (type == 6)
					ft_set_color(canvas, hi, lo, hi);
				else if (type == 7)
					ft_set_color(canvas, hi + 10, hi + 10, hi + 10);
				if (type == 7)
					type = 0;
			}
			change++;
			if (canvas->step > 2 && change == strob)
			{
				up_color = ft_neg_tuple(up_color);
				up_inten = ft_neg_tuple(up_inten);
				canvas->light.color = ft_add_tuple(canvas->light.color, up_color);
				canvas->light.intensity = ft_add_tuple(canvas->light.intensity, up_inten);
				ft_refreshframe(canvas);
			}
			if (change == local_step)
			{
				if (++done == 40)
					break ;
				change = 0;
				ft_refreshframe(canvas);
			}
		}
		ft_backup_light_ambient(canvas, 'r');
	}
	else
		return (false);
	return (true);
}
