#include "minirt.h"

#include "teste_done.c"


void	ft_start_rays(t_canvas *canvas, t_shapes shape)
{
	double	wall_z = 10;
	double	wall_size = 17.0;
	double	pixel_size = wall_size / IMG_W;
	double	half = wall_size / 2;

	double 	world_y;
	double 	world_x;
	t_tuple position;
	t_tuple normal;
	t_ray 	ray;
	t_tuple dir;
	t_camera  camera = ft_create_camera_a((t_tuple){0 , 0, -5, 1}, (t_tuple){0, 0, 1, 0}, 70);
	t_light	light = ft_create_light_a((t_tuple){-10 , 10, -15, 1}, (t_color){1, 1, 1, 3}, 10);
	ray.pos = camera.coord;
	int x_step;
	int y_step;
	ft_refreshframe(canvas);
	for(int y = 0; y < IMG_H; y += STEP)
	{
		world_y = half - pixel_size * y;

		for(int x = 0; x < IMG_H; x += STEP - 1)
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
						t_color lighting = ft_lighting(hit->shape->material, point, light, camera, normal);
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
	t_shapes	shape;
	shape.type = SPHERE;
	shape.sph.coord = (t_tuple){0, 0, 0, 1};
	shape.sph.diameter = 1;
	shape.material = ft_create_material();
	shape.sph.color = (t_color){1, 0.2, 1, 1};
	shape.material.color = shape.sph.color;
	shape.material.shininess = 200;
	shape.material.specular = 0.9;
	shape.material.diffuse = 0.5;
	shape.material.ambient = 0.1;
	t_tuple point;
	 ft_tuple_init(&point, (t_point){0,0,0}, T_POINT);
	/*t_tuple grav;
	t_tuple wind;
	t_tuple vel;
	ft_tuple_init(&vel, (t_point){0.1,0,0.2}, T_VECTOR);
	ft_tuple_init(&grav, (t_point){0,-0.06,0}, T_VECTOR);
	ft_tuple_init(&wind, (t_point){0,0,0.0}, T_VECTOR);
	while (1)
	{
		point = ft_add_tuple(point, vel);
		vel = ft_add_tuple(vel, ft_add_tuple(grav, wind));
		if (point.z > 17.5 || point.z < -4.5)
			vel.z = -vel.z;
		if (point.y > 7.5 || point.y < -7.5)
			vel.y = -vel.y * 0.95;
		if (point.x > 5.5 || point.x < -3.5)
			vel.x = -vel.x / 0.95; */
		ft_get_transf_obj(&shape, point, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
		ft_start_rays(canvas, shape);
	// 	usleep(15000);
	// }
}

int	main()
{
	t_canvas	canvas;
	test_mlx_start(&canvas);
	// test_mlx_clock(&canvas);
	// test_draw_circle_with_ray(&canvas);
	test_draw_ball_light(&canvas);
	test_mlx_end(&canvas);
	// test_norm_sphere();
	// test_norm_sphere_transf();
	// test_reflect();
	// test_reflect_light();



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
