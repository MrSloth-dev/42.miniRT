//#include "minirt.h"


/*void	test_shadow_110(t_canvas *canvas)*/
/*{*/
/*	t_tuple color;*/
/*	t_material	m;*/
/*	t_light		light;*/
/**/
/*	m = ft_create_material();*/
/*	light.coord = (t_tuple){0, 0, -10, 1};*/
/*	light.color= (t_tuple){1, 1, 1, 3};*/
/*	ft_create_world_camera_test(IMG_W, IMG_H, canvas);*/
/*	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,*/
/*					ft_add_tuple(canvas->camera.coord, canvas->camera.norm),*/
/*									(t_tuple){0, 1, 0, 0});*/
/*	ft_print_tuple(canvas->camera.norm, "camera norm");*/
/*	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);*/
/*	color = OLD_ft_lighting_shadow(m,*/
/*							(t_tuple){0, 0, 0, 1},*/
/*							light, */
/*							canvas->camera, */
/*							(t_tuple){0, 0, -1, 0}, */
/*							true);*/
/*	ft_print_tuple(color, "color in shaddow");*/
/*}*/


/*void	test_shadow_111(t_canvas *canvas)*/
/*{*/
/*	t_shapes	*_1 = (t_shapes *)canvas->objects->cont;*/
/*//	t_shapes	*_2 = (t_shapes *)canvas->objects->next->cont;*/
/*//	t_shapes	*_3 = (t_shapes *)canvas->objects->next->next->cont;*/
/*	bool result;*/
/**/
/*	_1->material.color = (t_color){0.8, 1.0, 0.6, 3};*/
/*	_1->material.diffuse = 0.7;*/
/*	_1->material.specular = 0.2;*/
/**/
/*	printf("\ntests IN_SHADOW or NOT page 111 - VERIFY VALUES ON PARSE LIKE BOOK!\n");*/
/*	result = ft_is_shadowed(canvas, (t_tuple){0, 10, 0, 1});*/
/*	printf("\n1st test\nshould NOT in shadow = %d\n", result);*/
/**/
/*	result = ft_is_shadowed(canvas, (t_tuple){10, -10, 10, 1});*/
/*	printf("\n2nd test \npoint is colinear: light -> shpere -> point\nshould IN shadow = %d\n", result);*/
/**/
/*	result = ft_is_shadowed(canvas, (t_tuple){-20, 20, -20, 1});*/
/*	printf("\n3rd test \npoint is behind light and sphere\nshould NOT in shadow = %d\n", result);*/
/**/
/*	result = ft_is_shadowed(canvas, (t_tuple){-2, 2, -2, 1});*/
/*	printf("\n4th test \npoint is between light and sphere\nshould NOT in shadow = %d\n", result);*/
/*}*/


/*void	test_plane_125(t_canvas *canvas)*/
/*{*/
/*	ft_print_tuple(((t_shapes *)canvas->objects->cont)->pla.norm, "plane norm");*/
/*	ft_print_tuple(((t_shapes *)canvas->objects->cont)->pla.coord, "plane coord");*/
/*	ft_print_objects(canvas);*/
/*}*/
/*void	test_inter_plane_123()*/
/*{*/
/*	t_shapes	plane;*/
/*	t_ray		ray;*/
/*	t_interlst	*lst;*/
/**/
/*	lst = NULL;*/
/*	plane.pla.norm = (t_tuple){0, 1, 0, 0};*/
/*	plane.pla.coord = (t_tuple){1, -2, 0, 1};*/
/*	ray.pos = (t_tuple){0, 1, 0, 1};*/
/*	ray.dir =  (t_tuple){0, -1, 0, 0};*/
/*	ft_intersection_plane(&lst, ray, &plane);*/
/*	ft_print_intersections(lst);*/
/*}*/
/**/
/*void	test_shadow_114(t_canvas *canvas)*/
/*{*/
/*	t_shapes	*_1 = (t_shapes *)canvas->objects->cont;*/
/*	t_shapes	*_2 = (t_shapes *)canvas->objects->next->cont;*/
/*	//t_tuple color;*/
/*	//t_material	m;*/
/*	//t_light		light;*/
/*	//light.coord = (t_tuple){0, 0, -10, 1};*/
/*	//light.color= (t_tuple){1, 1, 1, 3};*/
/*	_1->material.color = (t_color){0.8, 1.0, 0.6, 3};*/
/*	_1->material.diffuse = 0.7;*/
/*	_1->material.specular = 0.2;*/
/*	_2->material.diffuse = 0.7;*/
/*	_2->material.specular = 0.2;*/
/**/
/**/
/**/
/*	ft_create_world_camera_test(IMG_W, IMG_H, canvas);*/
/*	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,*/
/*												ft_add_tuple(canvas->camera.coord, canvas->camera.norm),*/
/*												(t_tuple){0, 1, 0, 0});*/
/*	ft_print_tuple(canvas->camera.norm, "camera norm");*/
/*	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);*/
/**/
/*	t_ray	ray = {.pos = canvas->camera.coord, .dir = canvas->camera.norm};*/
/*	t_interlst *lst =ft_inter_world(canvas, ray);*/
/*	t_inter	*hit = ft_hit_inter(&lst);*/
/*	printf("Hit value = %f", hit->value);*/
/*	t_comp comp = ft_prepare_comp(hit, ray);*/
/*	t_color color = ft_shade_hit_shadow(canvas, comp);*/
/*	ft_print_tuple(color, "color in shaddow");*/
/**/
/**/
/*}*/

//////////////////////////////////////////////////////////////
/*void	ft_start_rays_2(t_canvas *canvas);*/
/*void	test_draw_ball_light_2(t_canvas *canvas)*/
/*{*/
/*	ft_start_rays_2(canvas);*/
/*}*/
/*void	ft_start_rays_2(t_canvas *canvas)*/
/*{*/
/*	ft_refreshframe(canvas);*/
/**/
/*	ft_create_world_camera_test(IMG_W, IMG_H, canvas);*/
/*	// t_tuple	from = {0, 0, -5, 1};*/
/*	t_tuple	to = {0, 0, 1, 1};*/
/*	t_tuple	up = {0, 1, 0, 0};*/
/**/
/*	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,*/
/*						to, up);*/
/*	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);*/
/**/
/*	ft_render(canvas, (t_camera)(canvas->camera));*/
/*}*/











/*void	test_inter_world(t_canvas *canvas, char *argv[])*/
/*{*/
/*	t_interlst	*lst;*/
/*	if (ft_parse(canvas, argv[1]) == 0)*/
/*		return ;*/
/*	t_ray	ray = ft_create_ray((t_tuple) {0,0,-5, 1}, (t_tuple) {0,0,1,0});*/
/*	((t_shapes *)canvas->objects->cont)->material.diffuse = 0.7;*/
/*	((t_shapes *)canvas->objects->cont)->material.specular = 0.2;*/
/*	lst  = ft_inter_world(canvas, ray);*/
/*	for (t_interlstcy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255 *temp = lst; temp; temp = temp->next)*/
/*		printf("inter value %f\n", ((t_inter *)temp->cont)->value);*/
/*	ft_free_objects(lst);*/
/*}*/
/**/
/*void	test_shade(t_canvas *canvas)*/
/*{*/
/*	t_interlst	*lst;*/
/*	lst = NULL;*/
/*	t_ray	ray = ft_create_ray((t_tuple) {0,0,0, 1}, (t_tuple) {0,0,1,0});*/
/*	ft_intersection_sphere(&lst, ray, canvas->objects->cont);*/
/*	t_inter	*hit = ft_hit_inter(&lst);*/
/*	t_comp	temp = ft_prepare_comp(hit, ray);*/
/*	t_color	c = ft_shade_hit(canvas, temp);*/
/*	ft_print_tuple(c, "color");*/
/*	ft_free_objects(lst);*/
/*}*/
/**/
/*void	test_color_at(t_canvas *canvas)*/
/*{*/
/*	((t_shapes *)canvas->objects->cont)->material.diffuse = 0.7;*/
/*	((t_shapes *)canvas->objects->cont)->material.specular = 0.2;*/
/*	t_ray	ray = ft_create_ray((t_tuple) {0, 0, -5, 1},*/
/*			(t_tuple){0, 0, 1, 0});*/
/*	ft_print_tuple(ft_color_at(canvas, ray), "color at");*/
/*}*/
/**/
/*void	test_color_at_mult(t_canvas *canvas)*/
/*{*/
/*	t_shapes *outer = ((t_shapes *)canvas->objects->cont);*/
/*	t_shapes *inner = ((t_shapes *)canvas->objects->next->cont);*/
/**/
/*	outer->material.ambient = 1;*/
/*	inner->material.ambient = 1;*/
/**/
/*	printf("inner dia %f\n", inner->sph.diameter);*/
/*	printf("outer dia %f\n", outer->sph.diameter);*/
/*	t_ray	ray = ft_create_ray((t_tuple) {0, 0, 0.75, 1},*/
/*		(t_tuple) {0, 0, -1, 0});*/
/*	ft_print_tuple(ft_color_at(canvas, ray), "color at");*/
/*}*/
/**/
/*void	test_viewtransform()*/
/*{*/
/*	printf("\ntest 1\n");*/
/*	t_tuple from = {0, 0, 0, 1};*/
/*	t_tuple to = {0, 0, -1, 1};*/
/*	t_tuple up = {0, 1, 0, 0};*/
/*	ft_print_matrix(ft_view_transformation(from, to, up));*/
/*	printf("\ntest 2\n");*/
/*	from = (t_tuple){0, 0, 0, 1};*/
/*	to = (t_tuple){0, 0, 1, 1};*/
/*	up = (t_tuple){0, 1, 0, 0};*/
/*	ft_print_matrix(ft_view_transformation(from, to, up));*/
/*	printf("\ntest 3\n");*/
/*	from = (t_tuple){0, 0, 8, 1};*/
/*	to = (t_tuple){0, 0, 0, 1};*/
/*	up = (t_tuple){0, 1, 0, 0};*/
/*	ft_print_matrix(ft_view_transformation(from, to, up));*/
/*	printf("\ntest 4\n");*/
/*	from = (t_tuple){1, 3, 2, 1};*/
/*	to = (t_tuple){4, -2, 8, 1};*/
/*	up = (t_tuple){1, 1, 0, 0};*/
/*	ft_print_matrix(ft_view_transformation(from, to, up));*/
/*}*/
/**/
/*void	test_camera()*/
/*{*/
/*	t_camera	cam;*/
/*	t_ray		ray;*/
/**/
/*	printf("test creation camera\n");*/
/*	cam = ft_create_world_camera(200, 125, M_PI / 2);*/
/*	printf("cam 200, 125, pi/2 -> px_size 0.01? check %f\n", cam.px_size);*/
/*	cam = ft_create_world_camera(125, 200, M_PI / 2);*/
/*	printf("cam 200, 125, pi/2 -> px_size 0.01? check %f\n", cam.px_size);*/
/**/
/*	printf("\ntest ray_for_pixel\n");*/
/*	cam = ft_create_world_camera(201, 101, M_PI / 2);*/
/**/
/*	ray = ft_ray_for_pixel(cam, 100, 50);*/
/*	printf("\nConstructing a ray through the CENTER of the canvas\n");*/
/*	ft_print_tuple(ray.pos, "ray.pos (origin)\n0, 0, 0 ?");*/
/*	ft_print_tuple(ray.dir, "ray.direction\n0, 0, -1 ?");*/
/**/
/*	printf("\nConstructing a ray through a CORNER of the canvas\n");*/
/*	ray = ft_ray_for_pixel(cam, 0, 0);*/
/*	ft_print_tuple(ray.pos, "ray.pos (origin)\n0, 0, 0?");*/
/*	ft_print_tuple(ray.dir, "ray.direction \n0.66519, 0.33259, -0,66851?");  */
/**/
/*	printf("\nConstructing a ray when the camera is transformed\n"); */
/*	t_matrix rotated = ft_rotate_matrix_y(M_PI / 4);*/
/*	t_matrix translated = ft_translation_matrix(0, -2, 5);*/
/*	cam.transf = ft_matrix_mult(rotated, translated);*/
/*	cam.inverted = ft_invert_matrix(cam.transf);*/
/*	ray = ft_ray_for_pixel(cam, 100, 50);*/
/*	ft_print_tuple(ray.pos, "ray.pos (origin)\n0\t\t2\t\t-5  ?????");*/
/*	printf("ray.direction 0.707106781, 0, -0.707106781?\n");*/
/*	ft_print_tuple(ray.dir, "ray.direction sqrt(2) / 2, 0, sqrt(2) / 2 ?????");*/
/*}*/
/**/
/*void	test_render(t_canvas *canvas)*/
/*{*/
/*	// needs this on parse*/
/*	//A 1.0		0,0,0*/
/*	//L -10,10.0,-10.0		0.1		255,255,255*/
/*	// sp 0.0,0,0.0			1.0		204,255,153*/
/*	((t_shapes *)canvas->objects->cont)->material.color = (t_color){0.8, 1.0, 0.6, 3};*/
/*	((t_shapes *)canvas->objects->cont)->material.diffuse = 0.7;*/
/*	((t_shapes *)canvas->objects->cont)->material.specular = 0.9;*/
/*	t_camera cam = ft_create_world_camera(IMG_W, IMG_H, M_PI / 4);*/
/*	t_tuple	from = {0, 0, -5, 1};*/
/*	t_tuple	to = {0, 0, 0, 1};*/
/*	t_tuple	up = {0, 1, 0, 0};*/
/*	cam.norm = (t_tuple){0, 0, 1, 1};*/
/*	cam.transf = ft_view_transformation(from, to, up);*/
/*	cam.inverted = ft_invert_matrix(cam.transf);*/
/*	cam.fov = 30 * M_PI / 180;*/
/*	ft_render(canvas, cam);*/
/*}*/

//////////////////////////////////////////////////////
/*void	ft_start_rays(t_canvas *canvas, t_shapes shape);*/
/*void	test_draw_ball_light(t_canvas *canvas)*/
/*{*/
/*	t_shapes	shape;*/
/*	shape.type = SPHERE;*/
/*	shape.sph.coord = (t_tuple){0, 0, 0, 1};*/
/*	shape.sph.diameter = 1;*/
/*	shape.material = ft_create_material();*/
/*	shape.material.color = (t_color){1, 0.2, 1, 1};*/
/*	shape.material.shininess = 100;*/
/*	shape.material.specular = 0.9;*/
/*	shape.material.diffuse = 0.9;*/
/*	shape.material.ambient = 0.1;*/
/*	t_tuple point;*/
/*	 ft_tuple_init(&point, (t_point){0,0,0}, T_POINT);*/
/*	ft_get_transf_obj(&shape, point, (t_tuple){0}, (t_tuple){1, 1, 1, 0});*/
/*	ft_start_rays(canvas, shape);*/
/*}*/
/*void	ft_start_rays(t_canvas *canvas, t_shapes shape)*/
/*{*/
/*	double	wall_z = 10;*/
/*	double	wall_size = 7.0;*/
/*	double	pixel_size = wall_size / IMG_W;*/
/*	double	half = wall_size / 2;*/
/**/
/*	double 	world_y;*/
/*	double 	world_x;*/
/*	t_tuple position;*/
/*	t_tuple normal;*/
/*	t_ray 	ray;*/
/*	t_tuple dir;*/
/*	t_camera  camera = ft_create_camera_a((t_tuple){0 , 0, -25, 1}, (t_tuple){0, 0, 0, 0}, 70);*/
/*	t_light	light = ft_create_light_a((t_tuple){-10 , 10, -10, 1}, (t_color){1, 1, 1, 3}, 10);*/
/*	ray.pos = camera.coord;*/
/*	int x_step;*/
/*	int y_step;*/
/*	ft_refreshframe(canvas);*/
/*	for(int y = 0; y < IMG_H; y += STEP)*/
/*	{*/
/*		world_y = half - pixel_size * y;*/
/**/
/*		for(int x = 0; x < IMG_H; x += STEP)*/
/*		{*/
/*			y_step = 0;*/
/*			t_interlst	*lst;*/
/*			lst = NULL;*/
/*			world_x = -half + pixel_size * x;*/
/*			position = (t_tuple){ world_x, world_y, wall_z, 1};*/
/*			dir = ft_norm_vector(ft_sub_tuple(position, ray.pos));*/
/*			ray = ft_set_transf_ray(ft_create_ray(ray.pos, dir), shape.inverted);*/
/*			ft_intersection_sphere(&lst, ray, &shape);*/
/*			t_inter	*hit;*/
/*			hit = ft_hit_inter(&lst);*/
/*			if (hit != NULL)*/
/*			{*/
/*				t_tuple point = ft_distance_ray(ray, hit->value);*/
/*				normal = ft_normal_at_sph(hit->shape, point);*/
/*				camera.norm = ft_neg_tuple(ray.dir);*/
/*				while (y_step < STEP)*/
/*				{*/
/*					x_step = 0;*/
/*					while(x_step < STEP)*/
/*					{*/
/*						t_color lighting = ft_lighting(hit->shape->material, point, light, camera, normal);*/
/*						int color = ft_get_mlx_color(lighting);*/
/*						ft_pixel_put(canvas->img, x + x_step++, y + y_step, color);*/
/*					}*/
/*					y_step++;*/
/*				}*/
/*			}*/
/*			}*/
/*	}*/
/*	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);*/
/*}*/


//
//void	ft_start_rays_mult_objs(t_canvas *canvas, t_shapes shape)
//{
//	double	wall_z = 10;
//	double	wall_size = 7.0;
//	double	pixel_size = wall_size / IMG_W;
//	double	half = wall_size / 2;
//
//	double 	world_y;
//	double 	world_x;
//	t_tuple position;
//	t_tuple normal;
//	t_ray 	ray;
//	t_tuple dir;
//	t_camera  camera = ft_create_camera_a((t_tuple){0 , 0, -5, 1}, (t_tuple){0, 0, 1, 0}, 70);
//	ray.pos = camera.coord;
//	int x_step;
//	int y_step;
//	ft_refreshframe(canvas);
//	for(int y = 0; y < IMG_H; y += STEP)
//	{
//		world_y = half - pixel_size * y;
//
//		for(int x = 0; x < IMG_H; x += STEP)
//		{
//			y_step = 0;
//			t_interlst	*lst;
//			lst = NULL;
//			world_x = -half + pixel_size * x;
//			position = (t_tuple){ world_x, world_y, wall_z, 1};
//			dir = ft_norm_vector(ft_sub_tuple(position, ray.pos));
//			ray = ft_set_transf_ray(ft_create_ray(ray.pos, dir), shape.inverted);
//			t_objects *temp;
//			temp = canvas->objects;
//			t_inter	*hit;
//			ft_intersection_sphere(&lst, ray, ((t_shapes *)temp->cont));
//			t_inter	*hit_min;
//			hit_min= ft_hit_inter(&lst);
//			while (temp)
//			{
//				lst = NULL;
//				ft_intersection_sphere(&lst, ray, ((t_shapes *)temp->cont));
//				hit = ft_hit_inter(&lst);
//				if (hit && hit->value > 0 && hit->value <= hit_min->value)
//				{
//					hit_min = hit;
//				}
//
//				temp = temp->next;
//			}
//			if (hit!= NULL)
//			{
//				t_tuple point = ft_distance_ray(ray, hit_min->value);
//				normal = ft_normal_at_sph(hit_min->shape, point);
//				camera.norm = ft_neg_tuple(ray.dir);
//				while (y_step < STEP)
//				{
//					x_step = 0;
//					while(x_step < STEP)
//					{
//						t_color lighting = ft_lighting(hit->shape->material, point, canvas->light, camera, normal);
//						int color = ft_get_mlx_color(lighting);
//						ft_pixel_put(canvas->img, x + x_step++, y + y_step, color);
//					}
//					y_step++;
//				}
//			}
//			else
//				while (y_step < STEP)
//				{
//					x_step = 0;
//					while(x_step < STEP)
//						ft_pixel_put(canvas->img, x + x_step++, y + y_step, ft_get_mlx_color(canvas->ambient.color));
//					y_step++;
//				}
//		}
//	}
//	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
//}
//
//void	test_draw_ball_light(t_canvas *canvas)
//{
//	// t_tuple point;
//	// t_tuple grav;
//	// t_tuple wind;
//	// t_tuple vel;
//	// ft_tuple_init(&point, (t_point){0.1,0,0.2}, T_POINT);
//	// ft_tuple_init(&vel, (t_point){0.0,0,0.2}, T_VECTOR);
//	// ft_tuple_init(&grav, (t_point){0,-0.03,0}, T_VECTOR);
//	// ft_tuple_init(&wind, (t_point){0,0,0.0}, T_VECTOR);
//	// while (1)
//	// {
//	// 	point = ft_add_tuple(point, vel);
//	// 	vel = ft_add_tuple(vel, ft_add_tuple(grav, wind));
//	// 	if (point.z > 17.5 || point.z < -4.5)
//	// 		vel.z = -vel.z;
//	// 	if (point.y > 7.5 || point.y < -7.5)
//	// 		vel.y = -vel.y * 0.95;
//	// 	if (point.x > 5.5 || point.x < -3.5)
//	// 		vel.x = -vel.x / 0.95;
//	// 	ft_get_transf_obj(canvas->objects->cont, point, (t_tuple){0}, (t_tuple) {1, 1, 1, 0});
//		ft_start_rays_mult_objs(canvas, *(t_shapes *)canvas->objects->cont);
//	// 	usleep(150);
//	// }
//}
//
//void	test_mlx(char *argv[])
//{
//	t_canvas canvas;
//	if (ft_parse(&canvas, argv[1]) == 0)
//		return ;
//	test_mlx_start(&canvas);
//	test_draw_ball_light(&canvas);
//	test_mlx_end(&canvas);
//}
//
//void	test_comp(t_canvas canvas, char *argv[])
//{
//	t_interlst	*lst;
//	lst = NULL;
//	if (ft_parse(&canvas, argv[1]) == 0)
//		return ;
//	t_ray	ray = ft_create_ray((t_tuple) {0,0,0, 1}, (t_tuple) {0,0,1,0});
//	ft_intersection_sphere(&lst, ray, canvas.objects->cont);
//	t_inter	*hit = ft_hit_inter(&lst);
//	t_comp	temp = ft_prepare_comp(hit, ray);
//	(void)temp;
//	printf("\nvalue inter = %f\n", temp.value);
//	ft_print_tuple(temp.shape->material.color, "sphere color");
//	ft_print_tuple(temp.point, "point");
//	ft_print_tuple(temp.eyev, "eyev");
//	printf("\nis inside? = %i\n", temp.inside);
//	ft_print_tuple(temp.normalv, "normalv");
//}
///* void	ft_start_rays(t_canvas *canvas, t_shapes shape)
//{
//	double	wall_z = 10;
//	double	wall_size = 10.0;
//	double	pixel_size = wall_size / IMG_W;
//	double	half = wall_size / 2;
//
//	double 	world_y;
//	double 	world_x;
//	t_tuple position;
//	t_tuple normal;
//	t_ray 	ray;
//	t_tuple dir;
//	t_camera  camera = ft_create_camera_a((t_tuple){0 , 0, -5, 1}, (t_tuple){0, 0, 1, 0}, 70);
//	ray.pos = camera.coord;
//	int x_step;
//	int y_step;
//	ft_refreshframe(canvas);
//	for(int y = 0; y < IMG_H; y += STEP)
//	{
//		world_y = half - pixel_size * y;
//
//		for(int x = 0; x < IMG_H; x += STEP)
//		{
//			y_step = 0;
//			t_interlst	*lst;
//			lst = NULL;
//			world_x = -half + pixel_size * x;
//			position = (t_tuple){ world_x, world_y, wall_z, 1};
//			dir = ft_norm_vector(ft_sub_tuple(position, ray.pos));
//			ray = ft_set_transf_ray(ft_create_ray(ray.pos, dir), shape.inverted);
//			t_objects *temp;
//			temp = canvas->objects;
//			t_inter	*hit;
//			ft_intersection_sphere(&lst, ray, ((t_shapes *)temp->cont));
//			hit= ft_hit_inter(&lst);
//			if (hit!= NULL)
//			{
//				t_tuple point = ft_distance_ray(ray, hit->value);
//				normal = ft_normal_at_sph(hit->shape, point);
//				camera.norm = ft_neg_tuple(ray.dir);
//				while (y_step < STEP)
//				{
//					x_step = 0;
//					while(x_step < STEP)
//					{
//						t_color lighting = ft_lighting(hit->shape->material, point, canvas->light, camera, normal);
//						int color = ft_get_mlx_color(lighting);
//						ft_pixel_put(canvas->img, x + x_step++, y + y_step, color);
//					}
//					y_step++;
//				}
//			}
//			else
//				while (y_step < STEP)
//				{
//					x_step = 0;
//					while(x_step < STEP)
//						ft_pixel_put(canvas->img, x + x_step++, y + y_step, ft_get_mlx_color(canvas->ambient.color));
//					y_step++;
//				}
//		}
//	}
//	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
//} */
//
//void	test_norm_sphere()
//{
//	t_shapes	shape;
//	t_tuple point;
//	ft_tuple_init(&point, (t_point){1,0,0}, T_POINT);
//	shape.type = SPHERE;
//	shape.sph.coord = (t_tuple){0, 0, 0, 1};
//	shape.sph.diameter = 1;
//	shape.material.color = (t_color){255, 0, 0, 1};
//	ft_print_tuple(ft_normal_at_sph(&shape, point), "point (1, 0, 0)");
//	ft_tuple_init(&point, (t_point){0,1,0}, T_POINT);
//	ft_print_tuple(ft_normal_at_sph(&shape, point), "point (0, 1, 0)");
//	ft_tuple_init(&point, (t_point){0,0,1}, T_POINT);
//	ft_print_tuple(ft_normal_at_sph(&shape, point), "point (0, 0, 1)");
//	ft_tuple_init(&point, (t_point){sqrt(3) / 3,sqrt(3) / 3,sqrt(3) / 3}, T_POINT);
//	ft_print_tuple(ft_norm_vector(ft_normal_at_sph(&shape, point)), "point (0, 0, 1)");
//}
//
//void	test_norm_sphere_transf()
//{
//	t_shapes	shape;
//	t_tuple point;
//	shape.type = SPHERE;
//	shape.sph.coord = (t_tuple){0, 0, 0, 1};
//	shape.sph.diameter = 1;
//	shape.material.color = (t_color){1, 0, 0, 1};
//	ft_get_transf_obj(&shape, (t_tuple){0, 1, 0, 1}, (t_tuple) {0}, (t_tuple) {1, 1, 1, 0});
//	ft_tuple_init(&point, (t_point){0,1.70711,-0.70711}, T_POINT);
//	ft_print_tuple(ft_normal_at_sph(&shape, point), "point (0,1.70711,-0.70711)");
//
//	ft_get_transf_obj(&shape, ft_rotation_z((t_tuple){0, 0, 0, 1}, M_PI /5), (t_tuple) {0}, (t_tuple) {1, 0.5, 1, 0});
//	ft_tuple_init(&point, (t_point){0,sqrt(2)/2,-sqrt(2)/2}, T_POINT);
//	ft_print_tuple(ft_normal_at_sph(&shape, point), "point (0,sqrt(2)/2,-sqrt(2)/2)");
//}
//
//void	test_reflect()
//{
//	t_tuple incoming;
//	t_tuple normal;
//	ft_tuple_init(&incoming, (t_point){0,-1,0}, T_VECTOR);
//	ft_tuple_init(&normal, (t_point){sqrt(2) /2,sqrt(2) /2, 0}, T_VECTOR);
//	ft_print_tuple(ft_reflect(incoming, normal), "reflected ray");
//	ft_tuple_init(&incoming, (t_point){1,-1,0}, T_VECTOR);
//	ft_tuple_init(&normal, (t_point){0, 1, 0}, T_VECTOR);
//	ft_print_tuple(ft_reflect(incoming, normal), "reflected ray");
//}
//
//// t_color	ft_lighting(t_material m, t_tuple point, t_light light, t_camera camera, t_tuple normal)
//void	test_reflect_light()
//{
//	t_shapes	shape;
//	shape.type = SPHERE;
//	shape.sph.coord = (t_tuple){0, 0, 0, 1};
//	shape.sph.diameter = 1;
//	shape.material.color = (t_color){0, 0, 0, 1};
//	t_tuple		point;
//	t_tuple		normal;
//	t_light		light;
//	t_camera	camera;
//	t_color		final;
//
//	shape.material = ft_create_material();
//	ft_tuple_init(&point, (t_point){0, 0, 0}, 1);
//	camera = ft_create_camera_a((t_tuple){0,0,-10 ,1}, (t_tuple){0, 0, -1, 0}, 10);
//	light = ft_create_light_a((t_tuple){0,0,-10 ,1}, (t_color){1,1, 1, 3}, 1);
//	normal = (t_tuple){0,0,-1 ,0};
//	final = ft_lighting(shape.material, point, light, camera, normal);
//	ft_print_tuple(final, "final color 1st test");
//	camera = ft_create_camera_a((t_tuple){0,0,-10 ,1}, (t_tuple){0,sqrt(2) / 2, -sqrt(2) / 2 ,0}, 10);
//	light = ft_create_light_a((t_tuple){0,0,-10 ,1}, (t_color){1,1, 1, 3}, 1);
//	final = ft_lighting(shape.material, point, light, camera, normal);
//	ft_print_tuple(final, "final color 2nd test");
//	camera = ft_create_camera_a((t_tuple){0,0,-10 ,1}, (t_tuple){0, 0, -1,0}, 10);
//	light = ft_create_light_a((t_tuple){0,10,-10 ,1}, (t_color){1,1, 1, 3}, 1);
//	final = ft_lighting(shape.material, point, light, camera, normal);
//	ft_print_tuple(final, "final color 3rd test");
//	camera = ft_create_camera_a((t_tuple){0,0,-10 ,1}, (t_tuple){0,-sqrt(2) / 2,-sqrt(2) / 2 ,0}, 10);
//	light = ft_create_light_a((t_tuple){0,10,-10 ,1}, (t_color){1,1, 1, 3}, 1);
//	final = ft_lighting(shape.material, point, light, camera, normal);
//	ft_print_tuple(final, "final color 4th test");
//	camera = ft_create_camera_a((t_tuple){0,0,-10 ,1}, (t_tuple){0, 0, -1,0}, 10);
//	light = ft_create_light_a((t_tuple){0,0,10 ,1}, (t_color){1,1, 1, 3}, 1);
//	final = ft_lighting(shape.material, point, light, camera, normal);
//	ft_print_tuple(final, "final color 5th test");
//}
///* void	test_draw_circle_with_ray(t_canvas *canvas)
//{
//	t_shapes	shape;
//	t_tuple point;
//	shape.material = ft_create_material();
//	shape.material.color = (t_color){1, 0.2, 1, 3};
//	shape.type = SPHERE;
//	shape.sph.coord = (t_tuple){0, 0, 0, 1};
//	shape.sph.diameter = 1;
//	shape.sph.color = (t_color){10, 10, 0, 1};
//	ft_tuple_init(&point, (t_point){0,0,5}, T_POINT);
//	t_tuple grav;
//	t_tuple wind;
//	t_tuple vel;
//	ft_tuple_init(&vel, (t_point){0.1,0,0.2}, T_VECTOR);
//	ft_tuple_init(&grav, (t_point){0,-0.06,0}, T_VECTOR);
//	ft_tuple_init(&wind, (t_point){0,0,0.0}, T_VECTOR);
//	while (1)
//	{
//		point = ft_add_tuple(point, vel);
//		vel = ft_add_tuple(vel, ft_add_tuple(grav, wind));
//		if (point.z > 17.5 || point.z < -4.5)
//			vel.z = -vel.z;
//		if (point.y > 7.5 || point.y < -7.5)
//			vel.y = -vel.y * 0.95;
//		if (point.x > 5.5 || point.x < -3.5)
//			vel.x = -vel.x / 0.95;
//		ft_get_transf_obj(&shape, point, (t_tuple){0.0, 0.0, 0.0, 0}, (t_tuple){15.5, 15.5, 15.5, 0});
//		ft_start_rays(canvas, shape);
//		usleep(15000);
//	}
//	
//
//} */
//void teste_tuple_op()
//{
//	printf("\n%stest_tuple_op\n%s", GREEN, RESET);
//	// t_tuple	result;
//	t_tuple	point1;
//	t_tuple	point2;
//
//	ft_tuple_init(&point1, (t_point){4, 0, 0}, T_VECTOR);
//	point1 = ft_norm_vector(point1);
//	ft_tuple_init(&point2, (t_point){1, 2, 3}, T_VECTOR);
//	point2 = ft_norm_vector(point2);
//	ft_print_tuple(point1, "point1 normalize");
//	ft_print_tuple(point2, "point2 normalized");
//	// ft_print_tuple(ft_add_tuple(point1, point2), "add");
//	// ft_print_tuple(ft_sub_tuple(point1, point2), "sub");
//	// printf("\n");
//	// printf("magn %f\n", ft_magn_tuple(point2));
//	// printf("\n");
//	// ft_print_tuple(ft_neg_tuple(point1), "neg");
//	// printf("\n");
//	// ft_print_tuple(ft_norm_vector(point2), "normalize");
//	// printf("\n");
//	// printf("dotprod = %lf\n", ft_dotprod_vector(point2, point2));
//	// printf("\n");
//	// printf("dotprod = %lf\n", ft_dotprod_vector(point1, point2));
//	// printf("\n");
//	// result = ft_crossprod_vector((t_tuple){1,0,0,T_VECTOR}, (t_tuple){0,1,0,T_VECTOR});
//	// ft_print_tuple(result, "Cross Prod");
//	// printf("\n");
//}
//
//void teste_matrix_mult()
//{
//	printf("\n%stest_matrix_multi\n%s", GREEN, RESET);
//	t_matrix a, b, c;
//	double m_a[4][4] = {
//		{1, 2, 3, 4},
//		{5, 6, 7, 8},
//		{9, 8, 7, 6},
//		{5, 4, 3, 2}
//	};
//	double m_b[4][4] = {
//		{-2, 1, 2, 3},
//		{3, 2, 1, -1},
//		{4, 3, 6, 5},
//		{1, 2, 7, 8}
//	};
//	a = ft_create_matrix(4, 4, 0);
//	b = ft_create_matrix(4, 4, 0);
//	for (int c = 0; c < 4; c++) {
//        for (int r = 0; r < 4; r++) {
//            a.data[r][c] = m_a[c][r];
//        }}
//	for (int c = 0; c < 4; c++) {
//        for (int r = 0; r < 4; r++) {
//            b.data[r][c] = m_b[c][r];
//        }}
//	c = ft_matrix_mult(a, b);
//	ft_print_matrix(c);
//	printf("\n");
//	c = ft_transpose_matrix(c);
//	ft_print_matrix(c);
//}
//
//void	test_put_together_mtx()
//{
//	t_matrix a, b, c;
//	double m_a[4][4] = {
//		{1, 2, 3, 4},
//		{5, -6, 7, 8},
//		{-9, 8, -7, 6},
//		{5, 4, 3, -2}
//	};
//	a = ft_create_matrix(4, 4, 0);
//	b = ft_create_matrix(4, 4, 0);
//	c = ft_create_matrix(4, 4, 0);
//	printf(GREEN"\nMatrix multi by its inverse\n"RESET);
//	ft_set_matrix_values(&a, m_a);
//	b = ft_invert_matrix(a);
//	printf(GREEN"\nMatrix A\n"RESET);
//	ft_print_matrix(a);
//	printf(GREEN"\nMatrix B\n"RESET);
//	ft_print_matrix(b);
//	printf(GREEN"\nMult\n"RESET);
//	c = ft_matrix_mult(a, b);
//	ft_print_matrix(c);
//}
//void	teste_minor_cofactor()
//{
//	printf(GREEN"\nteste_matrix_minor_Cofator\n"RESET);
//	double data[4][4] = {{ 3, 5, 0},
//	        {2, -1, -7},
//	        {6, -1, 5}};
//	t_matrix m;
//	m = ft_create_matrix(3, 3, 0);
//	ft_set_matrix_values(&m, data);
//	printf("Matrix M\n");
//	ft_print_matrix(m);
//	printf("\nminor[0][0] is %f\n", ft_minor(m, 0, 0));
//	printf("\ncafactor[0][0] is %f\n", ft_cofactor(m, 0, 0));
//	printf("\nminor[1][0] is %f\n", ft_minor(m, 1, 0));
//	printf("\ncafactor[1][0] is %f\n", ft_cofactor(m, 1, 0));
//
//}
//
////testing multiplication matrix by  tuple
//void	teste_matrix_mult_tuple()
//{
//	t_tuple b = (t_tuple){-1, 24, 3.2, 0};
//	ft_print_tuple(b, "b");
//	t_matrix A;
//	
//	A = ft_create_matrix(4, 5, 1);
//	ft_print_matrix(A);
//	t_tuple res = ft_mult_matrix_tuple(A, b);
//	ft_print_tuple(res, "res");
//}
//
//void	test_ft_determinant_size_two()
//{
//	printf("\n%stest_ft_determinant_size_two\n%s", GREEN, RESET);
//	t_matrix a ;
//	double m_a[4][4] = {
//		{1, 5, 2, 6},
//		{-3, 2, -2, 3},
//		{3, 8, 7, 6},
//		{5, 7, 3, 2}
//	};
//	double deter;
//	a = ft_create_matrix(3, 3, 0);  
//	for (int r = 0; r < a.rows; r++) {
//        for (int c = 0; c < a.cols; c++) {
//            a.data[r][c] = m_a[r][c];
//        }}
//	deter = ft_determinant(a);
//	printf("determinant: %f\n", deter);
//}
//
//void	test_ft_submatrix()
//{
//	printf("\n%stest_ft_submatrix\n%s", GREEN, RESET);
//	t_matrix a, b;
//	double m_a[4][4] = {
//		{1, 5, 2, 6},
//		{-3, 2, -2, 3},
//		{3, 8, 7, 6},
//		{5, 7, 3, 2}
//	};
//
//	a = ft_create_matrix(3, 3, 0); 
//	for (int r = 0; r < a.rows; r++) {
//        for (int c = 0; c < a.cols; c++) {
//            a.data[r][c] = m_a[r][c];
//        }}
//		ft_print_matrix(a);
//	printf("\n");
//	printf("rem 0 0\n");
//	b = ft_submatrix(a, 0, 0);
//	ft_print_matrix(b);
//		printf("\n");
//		printf("rem 1 0\n");
//		b = ft_submatrix(a, 1, 0);
//		ft_print_matrix(b);
//	printf("\n");
//	printf("rem 2 2\n");
//	b = ft_submatrix(a, 2, 2);
//	ft_print_matrix(b);
//		printf("\n");
//		printf("rem 3 3\n");
//		b = ft_submatrix(a, 3, 3);
//		ft_print_matrix(b);
//	printf("\n");
//	printf("rem 0 3\n");
//	b = ft_submatrix(a, 0, 3);
//	ft_print_matrix(b);
//}
//
//void	test_cofators()
//{
//	printf(GREEN"\ntest_ft_determinant\n"RESET);
//	t_matrix a ;
//	double data[4][4] = {
//		{-2, -8, 3, 5},
//		{-3, 1, 7, 3},
//		{1, 2, -9, 6},
//		{-6, 7, 7, -9}
//	};
//	a = ft_create_matrix(4, 4,0);
//	ft_set_matrix_values(&a, data);
//	ft_print_matrix(a);
//	printf("\nmatrix col size is %d\n", a.cols);
//	for( int c = 0; c < a.cols; c++)
//		printf("\ncofator is %f\n", ft_cofactor(a, 0, c));
//}
//
//void	test_determinant()
//{
//	printf(GREEN"\ntest_ft_determinant\n"RESET);
//	t_matrix a ;
//	double data[4][4] = {
//		{-2, -8, 3, 5},
//		{-3, 1, 7, 3},
//		{1, 2, -9, 6},
//		{-6, 7, 7, -9}
//	};
//	a = ft_create_matrix(4, 4,0);
//	ft_set_matrix_values(&a, data);
//	ft_print_matrix(a);
//	printf("\ndeterminant is %f\n", ft_determinant(a));
//
//}
//
//void	test_invertion()
//{
//	printf(GREEN"\ntest_ft_invertion\n"RESET);
//	t_matrix a ;
//	t_matrix temp;
//	double data[4][4] = {
//		{-5, 2, 6, -8},
//		{1, -5, 1, 8},
//		{7, 7, -6, -7},
//		{1, -3, 7, 4}
//	};
//	printf(GREEN"\nMatrix A\n"RESET);
//	a = ft_create_matrix(4, 4,0);
//	ft_set_matrix_values(&a, data);
//	ft_print_matrix(a);
//	double det = ft_determinant(a);
//	printf("\ndeter = %f\n", det);
//	printf("\ncofator[3][2] = %f\n", ft_cofactor(a, 3, 2));
//	printf("\ncofator[2][3] = %f\n", ft_cofactor(a, 2, 3));
//	printf(GREEN"\nInverting\n"RESET);
//	temp = ft_invert_matrix(a);
//	ft_print_matrix(temp);
//
//	(void)temp;
//}
//
//void	test_translation()
//{
//	printf(GREEN"\nTransformation\n"RESET);
//	t_tuple vector = {-3, 4, 5, 0};
//	t_tuple point = {-3, 4, 5, 1};
//	ft_print_tuple(ft_translate(vector, vector), "translate vector");
//	ft_print_tuple(ft_translate(point, point), "translate point");
//}
//
//void	test_scale()
//{
//	printf(GREEN"\nTransformation\n"RESET);
//	t_tuple vector = {-4, 6, 8, 1};
//	t_tuple point = {-4, 6, 8, 1};
//	ft_print_tuple(ft_scale((t_tuple){2, 3, 4, 1}, vector), "scale vector");
//	ft_print_tuple(ft_scale((t_tuple){2, 3, 4, 1}, point), "scale point");
//}
//
//void	test_rotation_x()
//{
//	t_tuple temp;
//	printf(GREEN"\nTransformation\n"RESET);
//	t_tuple point = {1, 0, 1, 1};
//	temp = ft_rotation_x(point, 90);
//	ft_print_tuple(temp, "\nrotation x \n");
//	temp = ft_scale((t_tuple){5, 5, 5, 1}, temp);
//	ft_print_tuple(temp, "\nscale (5, 5, 5)\n");
//	temp = ft_translate((t_tuple){10, 5, 7, 1}, temp);
//	ft_print_tuple(temp, "\ntranslate (10, 5, 7)\n");
//}
//
//void	test_ray_distance()
//{
//	t_ray	ray;
//	ray = ft_create_ray((t_tuple){2, 3, 4, 1}, (t_tuple){1, 0, 0, 0});
//	ft_print_tuple(ft_distance_ray(ray, 0), "point time 0");
//	ft_print_tuple(ft_distance_ray(ray, 1), "point time 1");
//	ft_print_tuple(ft_distance_ray(ray, -1), "point time -1");
//	ft_print_tuple(ft_distance_ray(ray, 2.5), "point time 2.5");
//}
//
//void	test_intersect_sphere()
//{
//	t_sphere	sph;
//	t_ray		ray;
//	t_interlst	*lst;
//
//	lst = NULL;
//	sph.diameter = 1;
//	sph.coord = (t_tuple){0, 0, 0, 1};
//	ray.pos = (t_tuple){0, 0, 5, 1};
//	ray.dir =  (t_tuple){0, 0, 1, 0};
//	ft_intersection_sphere(&lst, ray, (t_shapes *)&sph);
//}
//
//void	test_multiple_intersect()
//{
//	t_shapes	sph;
//	t_shapes	sph2;
//	t_shapes	sph3;
//	t_ray		ray;
//	t_interlst	*lst;
//
//	lst = NULL;
//	ray.pos = (t_tuple){0, 0, 5, 1};
//	ray.dir =  (t_tuple){0, 0, 1, 0};
//
//	sph3.sph.diameter = 0.65;
//	sph3.sph.coord = (t_tuple){0, 0.1, -7, 1};
//	sph3.material.color = (t_color){130, 0, 0, 1};
//
//	sph2.sph.diameter = 0.5;
//	sph2.sph.coord = (t_tuple){0, 0.1, 0.1, 1};
//	sph2.material.color = (t_color){130, 0, 0, 1};
//
//	sph.sph.diameter = 1;
//	sph.sph.coord = (t_tuple){0, 0, 0, 1};
//	sph.material.color = (t_color){255, 0, 0, 1};
//
//	ft_intersection_sphere(&lst, ray, &sph);
//	ft_intersection_sphere(&lst, ray, &sph2);
//	ft_intersection_sphere(&lst, ray, &sph3);
//	ft_hit_inter(&lst);
//}
//
//void	test_transform_ray()
//{
//	t_ray		ray;
//	t_ray		ray2;
//
//	ray.pos = (t_tuple){1, 2, 3, 1};
//	ray.dir =  (t_tuple){0, 1, 0, 0};
//	ray2 = ft_translate_ray((t_tuple) {3, 4, 5, 0}, ray);
//	ft_print_tuple(ray2.dir, "ray2 dir");
//	ft_print_tuple(ray2.pos, "ray2 pos");
//	ray2 = ft_scale_ray((t_tuple) {2, 3, 4, 0}, ray);
//	ft_print_tuple(ray2.dir, "ray2 dir");
//	ft_print_tuple(ray2.pos, "ray2 pos");
//}
//
//void	test_transformed_ray()
//{
//	t_shapes	shape;
//	t_ray		ray;
//	t_ray		ray2;
//	t_interlst	*lst;
//
//	lst = NULL;
//	ray.pos = (t_tuple){0, 0, -5, 1};
//	ray.dir =  (t_tuple){0, 0, 1, 0};
//	shape.type = SPHERE;
//	shape.sph.diameter = 1;
//	shape.sph.coord = (t_tuple){0, 0, 0, 1};
//	shape.material.color = (t_color){255, 0, 0, 1};
//	ft_get_transf_obj(&shape, (t_tuple){0}, (t_tuple){0}, (t_tuple){2, 2, 2, 0});
//	// ft_get_transf_obj(&shape, (t_tuple){0.0,0.0,20.6, 1}, (t_tuple){0.0, 0.0, 0.0, 0}, 12.6);
//	ray2 = ft_set_transf_ray(ray, shape.inverted);
//	ft_intersection_sphere(&lst, ray2, &shape);
//	ft_hit_inter(&lst);
//	shape.sph.diameter = 1;
//	shape.sph.coord = (t_tuple){0, 0, 0, 1};
//	shape.material.color = (t_color){255, 0, 0, 1};
//	ft_get_transf_obj(&shape, (t_tuple){5, 0, 0, 1}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
//	// ft_get_transf_obj(&shape, (t_tuple){0.0,0.0,20.6, 1}, (t_tuple){0.0, 0.0, 0.0, 0}, 12.6);
//	ray2 = ft_set_transf_ray(ray, shape.inverted);
//	ft_intersection_sphere(&lst, ray2, &shape);
//	ft_hit_inter(&lst);
//}
//
//void	test_mlx_clock(t_canvas *canvas)
//{
//	float radius = (float)WIN_H / 4;
//	t_tuple point = {0, 0, 0, 1};
//
//	ft_pixel_put(canvas->img, (float)WIN_W / 2, (float)WIN_H / 2, 0x00ff00); // center
//	t_tuple temp = ft_translate((t_tuple){0, -radius, 0, 0} , point);
//	(void)temp;
//	// printf("windows width = %d, height =  %d\n\n", WIN_W, WIN_H);
//	// printf("image width = %d, height =  %d\n\n", IMG_W, IMG_H);
//	for (int i = 0; i < 12; i++)
//	{
//		ft_pixel_put(canvas->img, temp.x + (float)WIN_W / 2, temp.y + (float)WIN_H / 2, 0xffffff);
//		temp = ft_rotation_z(temp, ((float)360 / (12)));
//		printf("x = %f, y = %f\n", temp.x+ (float)WIN_W / 2, temp.y+ (float)WIN_H / 2);
//		// ft_draw_square(canvas, (t_tuple){0,0,0,1}, (t_tuple){WIN_W,WIN_H,0,1}, 0xff0000);
//		mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
//		sleep(1);
//		
//	}
//}

// void	test_render_scene(t_canvas *canvas)
// {
// 	t_shapes	*_1 = (t_shapes *)canvas->objects->cont;
// 	t_shapes	*_2 = (t_shapes *)canvas->objects->next->cont;
// 	t_shapes	*_3 = (t_shapes *)canvas->objects->next->next->cont;
// 	
// 	ft_get_transf_obj(_1, (t_tuple){0}, (t_tuple){0}, (t_tuple){10, 0.01, 10, 0});
// 	ft_get_transf_obj(_2, (t_tuple){0, 0, 5, 0}, (t_tuple){M_PI / 2, -M_PI / 4, 0, 0}, (t_tuple){10, 0.01, 10, 0});
// 	ft_get_transf_obj(_3, (t_tuple){0, 0, 5, 0}, (t_tuple){M_PI / 2, M_PI / 4, 0, 0}, (t_tuple){10, 0.01, 10, 0});
//
// 	/* ft_get_transf_obj(_4, (t_tuple){0, 1, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
// 	ft_get_transf_obj(_5, (t_tuple){2.5, 1, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
// 	ft_get_transf_obj(_6, (t_tuple){-2.5, 1, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});  */
// 	printf("Matrix _1");
// 	ft_print_matrix(_1->transform);
// 	printf("Matrix _2");
// 	ft_print_matrix(_2->transform);
// 	printf("Matrix _3");
// 	ft_print_matrix(_3->transform);
// 	_1->material.color = (t_color){1, 0.9, 0.9, 3};
// 	_1->material.specular = 0;
//
// 	_2->material = _1->material;
// 	_3->material = _1->material;
//
// 	//put inside create camera of parser
// 	ft_create_world_camera_test(IMG_W, IMG_H, canvas);
// 	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,
// 												ft_add_tuple(canvas->camera.coord, canvas->camera.norm),
// 												(t_tuple){0, 1, 0, 0});
// 	ft_print_tuple(canvas->camera.norm, "camera norm");
// 	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
// 	ft_render(canvas, (t_camera)canvas->camera);
// }
//
