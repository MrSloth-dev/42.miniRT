#include "minirt.h"

#include "teste_done.c"


void	ft_start_rays(t_canvas *canvas, t_shapes shape)
{
	double	wall_z = 10;
	double	wall_size = 10.0;
	double	pixel_size = wall_size / IMG_W;
	double	half = wall_size / 2;

	double 	world_y;
	double 	world_x;
	t_tuple position;
	t_tuple normal;
	t_ray 	ray;
	t_tuple dir;
	t_camera  camera = ft_create_camera_a((t_tuple){0 , 0, -5, 1}, (t_tuple){0, 0, 1, 0}, 70);
	ray.pos = camera.coord;
	int x_step;
	int y_step;
	ft_refreshframe(canvas);
	for(int y = 0; y < IMG_H; y += STEP)
	{
		world_y = half - pixel_size * y;

		for(int x = 0; x < IMG_H; x += STEP)
		{
			y_step = 0;
			t_interlst	*lst;
			lst = NULL;
			world_x = -half + pixel_size * x;
			position = (t_tuple){ world_x, world_y, wall_z, 1};
			dir = ft_norm_vector(ft_sub_tuple(position, ray.pos));
			ray = ft_set_transf_ray(ft_create_ray(ray.pos, dir), shape.inverted);
			ft_intersection_sphere(&lst, ray, &shape);
			t_inter	*hit;
			hit = ft_hit_inter(&lst);
			if (hit != NULL)
			{
				t_tuple point = ft_distance_ray(ray, hit->value);
				normal = ft_normal_at_sph(hit->shape, point);
				camera.norm = ft_neg_tuple(ray.dir);
				while (y_step < STEP)
				{
					x_step = 0;
					while(x_step < STEP)
					{
						t_color lighting = ft_lighting(hit->shape->material, point, canvas->light, camera, normal);
						int color = ft_get_mlx_color(lighting);
						ft_pixel_put(canvas->img, x + x_step++, y + y_step, color);
					}
					y_step++;
				}
			}
			/* else
				while (y_step < STEP)
				{
					x_step = 0;
					while(x_step < STEP)
						ft_pixel_put(canvas->img, x + x_step++, y + y_step, 0x7f7f);
					y_step++;
				} */
		}
	}
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
}


void	test_mlx_start(t_canvas *canvas)
{
	ft_init_canvas(canvas);
	ft_setup(canvas);
	mlx_hook(canvas->win, DestroyNotify, 0l, &close_handler, &canvas);
}

void	test_mlx_end(t_canvas *canvas)
{
	mlx_loop(canvas->mlx);
	ft_free_canvas(canvas);
}


void	test_draw_ball_light(t_canvas *canvas)
{
	// t_tuple grav;
	// t_tuple wind;
	// t_tuple vel;
	// ft_tuple_init(&vel, (t_point){0.1,0,0.2}, T_VECTOR);
	// ft_tuple_init(&grav, (t_point){0,-0.06,0}, T_VECTOR);
	// ft_tuple_init(&wind, (t_point){0,0,0.0}, T_VECTOR);
	// while (1)
	// {
	// 	point = ft_add_tuple(point, vel);
	// 	vel = ft_add_tuple(vel, ft_add_tuple(grav, wind));
	// 	if (point.z > 17.5 || point.z < -4.5)
	// 		vel.z = -vel.z;
	// 	if (point.y > 7.5 || point.y < -7.5)
	// 		vel.y = -vel.y * 0.95;
	// 	if (point.x > 5.5 || point.x < -3.5)
	// 		vel.x = -vel.x / 0.95;
	ft_start_rays(canvas, *(t_shapes *)canvas->objects->cont);
	// 	usleep(150);
	// }
}

int	main(int argc, char *argv[])
{
	(void)argc;
	t_canvas canvas;
	test_mlx_start(&canvas);
	// test_mlx_clock(&canvas);
	// test_draw_circle_with_ray(&canvas);
	// test_norm_sphere();
	// test_norm_sphere_transf();
	// test_reflect();
	// test_reflect_light();
	ft_init_canvas(&canvas);
	// ft_mlx_init(&canvas);
	// ft_setup(&canvas);
	if (ft_parse(&canvas, argv[1]) == 0)
		return 1;
	/* t_objects *current = canvas.objects;
	while (current) {
		if (current->cont) {
			t_shapes *shape = (t_shapes *)current->cont;
			printf("ok %d\n", shape->type);
			ft_print_tuple(((t_shapes *)shape)->sph.coord, "sphere coord");
			ft_print_tuple(((t_shapes *)shape)->material.color, "sphere color");
		} else {
			fprintf(stderr, "Warning: current->cont is null\n");
		}
		current = current->next;
	}
	ft_print_tuple(canvas.light.coord, "light coord");
	ft_print_tuple(canvas.light.color, "light color"); */


	test_draw_ball_light(&canvas);
	test_mlx_end(&canvas);
	// teste_tuple_op();
	// teste_matrix_mult();
	// teste_matrix_mult_tuple();
	// test_ft_determinant_size_two();
	// test_ft_submatrix();
	// teste_minor_cofactor();
	// test_cofators();
	// test_determinant();
	// test_invertion();
	// test_put_together_mtx();
	// test_translation();
	// test_scale();
	// test_rotation_x();
	// test_ray_distance();
	// test_intersect_sphere();
	// test_multiple_intersect();
	// test_transformed_ray();
	// test_draw_circle_with_ray(&canvas);
	return (0);
}
