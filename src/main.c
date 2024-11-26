#include "minirt.h"
#include <unistd.h>

void	ft_draw_square(t_canvas *canvas,t_tuple start, t_tuple sides, int color)
{
	int	y;
	int	x;

	if (!canvas)
		return ;
	ft_refreshframe(canvas);
	y = start.y;
	x = start.x;
	while (y < (int)(sides.x + start.y))
	{
		while (x < (int)(sides.x + start.x))
		{
			ft_pixel_put(canvas->img, x, y, color);
			x++;
		}
		x = start.x;
		y++;
	}
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
}

void	ft_print_tuple(t_tuple tuple, char *name)
{
	printf("%s\n", name);
	printf("x= %f\n",tuple.x);
	printf("y= %f\n",tuple.y);
	printf("z= %f\n",tuple.z);
	if (tuple.w == 0)
		printf("is a Vector\n");
	else
		printf("is a Point\n");
}

void	operations_testing(void);

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
		if (point.y > IMG_HEIGHT - 100 || point.y < 5)
			vel.y = -vel.y * 0.95;
		if (point.x > IMG_WIDTH - (100) || point.x < 0)
			vel.x = -vel.x / 0.95;
		ft_draw_square(canvas, point, (t_tuple){100, 100, 0, 1}, 0xFF0000);
		// ft_print_tuple(point, "");
		// printf("y is %6f and type %d\n", point.y, point.type);
		usleep(10000);
	}
}

void	ft_free_canvas(t_canvas *canvas)
{
	ft_free(canvas->ambient);
}

int	main(int argc, char *argv[])
{
	t_canvas	canvas;
	// t_matrix	m;

	canvas.name = argv[0] + 2;

	(void)argc;
	if (argc != 2)
		return (ft_printf(2, "Error in argv!\n"));
	ft_init_canvas(&canvas);
	// ft_mlx_init(&canvas);
	ft_parse(&canvas, argv[1]);
	int i = 0;
	printf(YELLOW"\nAMBIENT\n"RESET);
	while (canvas.count.ambient > i)
	{
		printf("\n%d\n", i);
		printf("ambient ratio %f\n", canvas.ambient[i].ratio);
		printf("ambient color r %f\n", canvas.ambient[i].color.r);
		printf("ambient color g %f\n", canvas.ambient[i].color.g);
		printf("ambient color b %f\n", canvas.ambient[i].color.b);
		i++;
	}
	i = 0;
	printf(RED"\nCAMERA\n"RESET);
	while (canvas.count.camera > i)
	{
		printf("\n%d\n", i);
		printf("camera fov %d\n", canvas.camera[i].fov);
		printf("camera coord %f\n", canvas.camera[i].coord.x);
		printf("camera coord %f\n", canvas.camera[i].coord.y);
		printf("camera coord %f\n", canvas.camera[i].coord.z);
		printf("camera norm %f\n", canvas.camera[i].norm.x);
		printf("camera norm %f\n", canvas.camera[i].norm.y);
		printf("camera norm %f\n", canvas.camera[i].norm.z);
		i++;
	}
	i = 0;
	printf(RED"\nLIGHT\n"RESET);
	while (canvas.count.light > i)
	{
		printf("\n%d\n", i);
		printf("light bright %f\n", canvas.light[i].bright);
		printf("light coord %f\n", canvas.light[i].coord.x);
		printf("light coord %f\n", canvas.light[i].coord.y);
		printf("light coord %f\n", canvas.light[i].coord.z);
		printf("light color r = %f, ", canvas.light[i].color.r);
		printf("g = %f, ", canvas.light[i].color.g);
		printf("b = %f\n", canvas.light[i].color.b);
		i++;
	}

	//ft_free_canvas(&canvas);
	//
	// m = ft_create_matrix(4, 4);
	// ft_set_matrix_values(&m,(double[4][4]){{1,2,3,4}, {5.5,6.5,7.5,8.5}, {9,10,11,12}, {13.5,14.5,15.5,16.5}});
	// ft_print_matrix(m);
	// operations_testing();
	// ft_setup(&canvas);
	//
	//jumpingball(&canvas);
	// ft_draw_square(&canvas, (t_tuple){150, 150, 0, 0}, (t_tuple){150, 150, 0, 0}, 0xFFFF0000);
	// mlx_key_hook(canvas.win, key_handler, &canvas);
	// mlx_hook(canvas.win, DestroyNotify, 0L, &close_handler, &canvas);
	// mlx_loop(canvas.mlx);
	return (0);
}

void	operations_testing(void)
{
	t_tuple	result;
	t_tuple	point1;
	t_tuple	point2;
	ft_tuple_init(&point1, (t_point){1,2,3}, T_VECTOR);
	ft_tuple_init(&point2, (t_point) {0,0,1}, T_VECTOR);
	ft_print_tuple(point1, "point1");
	ft_print_tuple(point2, "point2");
	ft_print_tuple(ft_add_tuple(point1, point2), "add");
	ft_print_tuple(ft_sub_tuple(point1, point2), "sub");
	printf("\n");
	printf("magn %f\n", ft_magn_tuple(point2));
	printf("\n");
	ft_print_tuple(ft_neg_tuple(point1), "neg");
	printf("\n");
	ft_print_tuple(ft_mul_tuple(point1, point2), "mult");
	printf("\n");
	ft_print_tuple(ft_norm_vector(point2), "normalize");
	printf("\n");
	printf("dotprod = %lf\n", ft_dotprod_vector(point2, point2));
	printf("\n");
	printf("dotprod = %lf\n", ft_dotprod_vector(point1, point2));
	printf("\n");
	result = ft_crossprod_vector((t_tuple){1,0,0,T_VECTOR}, (t_tuple){0,1,0,T_VECTOR});
	ft_print_tuple(result, "Cross Prod");
	printf("\n");
}
