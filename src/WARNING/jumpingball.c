#include "minirt.h"

void	jumpingball(t_canvas *canvas)
{
	t_tuple point;
	t_tuple grav;
	t_tuple wind;
	t_tuple vel;
	ft_tuple_init(&point, (t_point){10,10,5}, T_POINT);
	ft_tuple_init(&vel, (t_point){3,0,0}, T_VECTOR);
	ft_tuple_init(&grav, (t_point){0,+0.1,0}, T_VECTOR);
	ft_tuple_init(&wind, (t_point){0,0,0}, T_VECTOR);
	for (int i = 0; i < 10000; i++)
	{
		point = ft_add_tuple(point, vel);
		vel = ft_add_tuple(vel, ft_add_tuple(grav, wind));
		if (point.y > IMG_H - 100 || point.y < 5)
			vel.y = -vel.y * 0.95;
		if (point.x > IMG_W - (100) || point.x < 0)
			vel.x = -vel.x / 0.95;
		ft_draw_square(canvas, point, (t_tuple){100, 100, 0, 1}, 0xFF0000);
		// ft_print_tuple(point, "");
		// printf("y is %6f and type %d\n", point.y, point.type);
		usleep(10000);
	}
}
