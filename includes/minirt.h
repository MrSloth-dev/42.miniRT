/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:01:55 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/08 02:07:21 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# include "structs.h"

# define WHITE 0xFFFFFF
# define RED "\e[1;3;31m"
# define GREEN "\e[1;3;32m"
# define YELLOW "\e[1;3;93m"
# define RESET "\e[0m"

# ifndef DEBUG
#  define DEBUG 0
# endif
# define WIN_H 500
# define WIN_W 900

# define IMG_H 500
# define IMG_W 900

# define HEIGHT_POS 16
# define W_POS 12
# define TEXT_H_ZONE 500
# define TEXT_W_ZONE 250

# ifndef STEP
#  define STEP 2
# endif

# define ROUND_ERROR 0.000001
# define ERR_INPUT 1
# define ERR_MLX 2

# define T_VECTOR 0
# define T_POINT 1
# define WHITESPACE " \t\n\r\v\f"

# ifndef ASSERT
#  define ASSERT 0
# endif

void		ft_assert(int condition, char *message);
void		*ft_free(void *ptr);
void		*ft_free_split(char **split);
void		ft_free_objects(t_objects *list);
int			ft_clean_exit(t_canvas *canvas);

//init
void		ft_init_canvas(t_canvas *canvas);
t_iter		ft_iter(int n);
void		ft_free_canvas(t_canvas *canvas);
int			ft_printf(int fd, const char *str, ...);

// Init objects
t_shapes	*ft_create_default_shape(int type);
t_ambient	ft_init_ambient(int ratio, t_color color);
t_camera	ft_init_camera(t_tuple coord, t_tuple norm, int fov);
t_light		ft_init_light(t_tuple coord, int bright, t_color color);
t_sphere	ft_init_sphere(t_tuple coord, int diameter);
t_plane		ft_init_plane(t_tuple coord, t_tuple norm);
t_cylinder	ft_init_cylinder(t_tuple coord, t_tuple norm,
				t_cyl_size size);
void		ft_add_object(void **head, void *object);

//parse
int			ft_count_members(char **split);
int			ft_check_null_split(char **split);
int			ft_check_syntax(t_canvas *canvas, char *file);
int			ft_check_commas(char *str);
int			ft_parse(t_canvas *canvas, char *file);
int			ft_syntax_ambient(t_canvas *canvas, char **split);
int			ft_syntax_camera(t_canvas *canvas, char **split);
int			ft_syntax_light(t_canvas *canvas, char **split);
int			ft_syntax_sphere(t_canvas *canvas, char **split);
int			ft_syntax_plane(t_canvas *canvas, char **split);
int			ft_syntax_cylinder(t_canvas *canvas, char **split);
int			ft_create_ambient(t_canvas *canvas, char **split);
int			ft_create_camera(t_canvas *canvas, char **split);
int			ft_create_light(t_canvas *canvas, char **split);
int			ft_create_sphere(t_canvas *canvas, char **split);
int			ft_create_plane(t_canvas *canvas, char **split);
int			ft_create_cylinder(t_canvas *canvas, char **split);
//checkers
int			ft_check_values(double a, double b, double c);
int			ft_vector_check(t_tuple tuple);
int			ft_rgb_check(t_color color);
int			ft_norm_check(t_tuple norm);
//Getters
double		ft_get_double(char *str, char *element, t_canvas *canvas);
t_tuple		ft_get_norm(char *str, char *element, t_canvas *canvas);
t_tuple		ft_get_coord(char *str, char *element, t_canvas *canvas);
t_color		ft_get_color(char *str, char *element, t_canvas *canvas);

//minilibx
int			ft_setup(t_canvas *canvas, char *argv[]);
int			key_handler(int keysym, t_canvas *canvas);
void		ft_mlx_init(t_canvas *canvas);
void		ft_pixel_put(t_img *data, int x, int y, int color);
int			ft_handle_key_hook(int key, t_canvas *canvas);
int			ft_free_mlx(t_canvas *canvas);
void		ft_menu(t_canvas *canvas);

//events minilibx
int			key_handler(int keysym, t_canvas *canvas);
int			key_release(int keysym, t_canvas *canvas);
int			mouse_handler(int mousecode, int x, int y, t_canvas *canvas);
int			mouse_handler_release(int mousecode,
				int x, int y, t_canvas *canvas);
int			mouse_motion(int x, int y, t_canvas *canvas);
int			close_handler(t_canvas *canvas);
int			ft_refreshframe(void *ptr);
bool		ft_make_disco(int key, t_canvas *canvas);
void		ft_change_color_disco(t_canvas *canvas, int *type);
bool		ft_light_transform(int keysym, t_canvas *canvas);
bool		ft_change_light_position(int keysym, t_canvas *canvas);
bool		ft_change_light_color(int keysym, t_canvas *canvas);
bool		ft_change_resolution(int keysym, t_canvas *canvas);
bool		ft_change_obj_properties(int keysym, t_canvas *canvas, bool state);
t_matrix	ft_sel_transform(int keysym, t_matrix transform);
bool		ft_change_object_color(int keysym, t_canvas *canvas);
bool		ft_camera_transform(int keysym, t_canvas *canvas);
void		ft_transform_camera_key(t_canvas *canvas, int key);
void		ft_select_obj(int x, int y, t_canvas *canvas);
void		ft_clear_select(t_canvas *canvas);

// Chapter 1 - Tuples, Points and Vectors
void		ft_tuple_init(t_tuple *tuple, t_point coord, int type);
t_tuple		ft_add_tuple(t_tuple tuple1, t_tuple tuple2);
int			ft_is_float_equal(double num1, double num2);
int			ft_is_tuples_equal(t_tuple tuple1, t_tuple tuple2);
t_tuple		ft_operator(t_tuple a, char op, t_tuple b);
t_tuple		ft_sub_tuple(t_tuple tuple1, t_tuple tuple2);
t_tuple		ft_neg_tuple(t_tuple tuple);
t_tuple		ft_scalar_tuple(t_tuple tuple, double value);
double		ft_magn_tuple(t_tuple tuple);
double		ft_dotprod_vector(t_tuple a, t_tuple b);
t_tuple		ft_norm_vector(t_tuple tuple);
t_tuple		ft_crossprod_vector(t_tuple a, t_tuple b);

// Chapter 2 - Canvas
int			ft_color_rgb_to_int(t_color color);
t_color		ft_color_int_to_rgb(int color);
int			ft_get_mlx_color(t_color color);

// Chapter 3 - Matrix
void		ft_print_matrix(t_matrix m);
t_matrix	ft_create_matrix(int rows, int cols, int identity);
void		ft_set_matrix_values(t_matrix *m, double values[4][4]);
int			ft_are_matrixes_equal(t_matrix a, t_matrix b);
t_matrix	ft_matrix_mult(t_matrix A, t_matrix B);
t_tuple		ft_mult_matrix_tuple(t_matrix A, t_tuple B);
t_matrix	ft_transpose_matrix(t_matrix src);
double		ft_determinant(t_matrix m);
t_matrix	ft_submatrix(t_matrix src, int row, int col);
double		ft_minor(t_matrix m, int row, int col);
double		ft_cofactor(t_matrix m, int row, int col);
t_matrix	ft_invert_matrix(t_matrix m);

// Chapter 4 - Matrix Transformations
t_tuple		ft_translate(t_tuple translation, t_tuple to_translate);
t_tuple		ft_scale(t_tuple scale, t_tuple to_scale);
t_tuple		ft_rotation_x(t_tuple tuple, double angle);
t_tuple		ft_rotation_y(t_tuple tuple, double angle);
t_tuple		ft_rotation_z(t_tuple tuple, double angle);
t_matrix	ft_rotate_matrix_x(double rad);
t_matrix	ft_rotate_matrix_y(double rad);
t_matrix	ft_rotate_matrix_z(double rad);

// Chapter 5 - Rays - Sphere intersections
t_ray		ft_create_ray(t_tuple pos, t_tuple dir);
t_tuple		ft_distance_ray(t_ray ray, double time);
void		ft_intersection_sphere(t_interlst **lst, t_ray ray, t_shapes *shap);
t_inter		*ft_hit_inter(t_interlst **lst);
t_ray		ft_translate_ray(t_tuple translation, t_ray ray);
t_ray		ft_scale_ray(t_tuple scaling, t_ray ray);
t_ray		ft_set_transf_ray(t_ray ray, t_matrix inverted);
t_matrix	ft_translation_matrix(double x, double y, double z);
t_matrix	ft_scale_matrix(double x, double y, double z);
t_matrix	ft_get_rotation_obj(t_tuple orien);
void		ft_get_transf_obj(t_shapes *s,
				t_tuple coord, t_tuple orientation, t_tuple scale);
void		ft_lstadd_sort_inter(t_interlst **lst,
				double value, t_shapes *shap);
// Chapter 6 - Lightning
t_tuple		ft_normal_at(t_shapes *shape, t_tuple w_point);
t_tuple		ft_normal_at_sph(t_shapes *sphere, t_tuple w_point);
t_tuple		ft_reflect(t_tuple incoming, t_tuple normal);
t_material	ft_create_material(void);
void		ft_material_to_shape(t_material m, t_shapes *shape);
t_color		ft_lighting_shadow(t_canvas *canvas, t_comp comp);

// Chapter 7 - Making a Scene
t_comp		ft_prepare_comp(t_inter *inter, t_ray ray, t_canvas *canvas);
t_color		ft_shade_hit(t_canvas *canvas, t_comp comp);
t_interlst	*ft_intersect_world(t_canvas *canvas, t_ray ray);
t_color		ft_color_at(t_canvas *canvas, t_ray ray);
t_matrix	ft_view_transformation(t_tuple from, t_tuple to, t_tuple up);
void		ft_create_world_camera(double h_size,
				double v_size, t_canvas *canvas);
void		ft_update_world_camera(t_canvas *canvas);
void		ft_ray_for_pixel(t_camera cam, double px, double py, t_ray *ray);
void		ft_render(t_canvas *canvas);
void		draw_axis(t_canvas *canvas);
void		ft_draw_line(t_canvas *c, t_ln_pt data, int color);

//Chapter 8 - Shaddows
bool		ft_is_shadowed(t_canvas *canvas, t_tuple point);
t_color		ft_lighting_shadow(t_canvas *canvas, t_comp comp);
t_color		ft_shade_hit_shadow(t_canvas *canvas, t_comp comp);

//Chapter 9 - Plane
void		ft_intersection_plane(t_interlst **lst, t_ray ray, t_shapes *shap);

//Chapter 13 - Cylinder
void		ft_intersection_cyl(t_interlst **lst, t_ray ray, t_shapes *shap);
t_tuple		ft_normal_at_cyl(t_shapes *shape, t_tuple w_point);

//TESTING/////////////////////////////////////////////
void		test_ft_is_tuples_equal(void);
void		test_ft_sub_tuple(void);
void		ft_print_tuple(t_tuple tuple, char *name);
void		ft_draw_square(t_canvas *canvas, t_tuple start,
				t_tuple sides, int color);
void		ft_print_objects(t_canvas *canvas);
void		operations_testing(void);
void		jumpingball(t_canvas *canvas);
void		ft_draw_square(t_canvas *canvas,
				t_tuple start, t_tuple sides, int color);
void		ft_print_intersections(t_interlst *lst);
#endif
