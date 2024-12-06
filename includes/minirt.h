#ifndef MINIRT_H
# define MINIRT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_printf/libft/libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <X11/keysym.h>
#include <X11/X.h>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

#define WIN_H 499
#define WIN_W 500

#define IMG_H 499
#define IMG_W 500

#define STEP 1
#define ROUND_ERROR 0.00001
#define ERR_INPUT 1
#define ERR_MLX 2

#define T_VECTOR 0
#define T_POINT 1
#define WHITESPACE " \t\n\r\v\f"

#ifndef ASSERT
# define ASSERT 0
#endif
#include "structs.h"

void		ft_tuple_init(t_tuple *tuple, t_point coord, int type);
void		ft_assert(int condition, char *message);
void		*ft_free(void *ptr);
void		*ft_free_split(char **split);
int			ft_clean_exit(t_canvas *canvas);
//init
void		ft_init_canvas(t_canvas *canvas);
t_iter		ft_iter(int n);
void		ft_free_canvas(t_canvas *canvas);

int			ft_printf(int fd, const char *str, ...);
void		ft_print_matrix(t_matrix m);
int	ft_color_rgb_to_int(t_color color);
t_color	ft_color_int_to_rgb(int color);
int	ft_get_mlx_color(t_color color);


//RAYS
t_tuple		ft_distance_ray(t_ray ray, double time);
t_ray		ft_create_ray(t_tuple pos, t_tuple dir);
void		ft_lstadd_sort_inter(t_interlst **lst, double value, t_shapes *shap);
void		ft_intersection_sphere(t_interlst **lst, t_ray ray, t_shapes *shap);
t_inter		*ft_hit_inter(t_interlst **lst);
t_ray		ft_translate_ray(t_tuple translation, t_ray ray);
t_ray		ft_scale_ray(t_tuple scaling, t_ray ray);
t_ray		ft_set_transf_ray(t_ray ray, t_matrix inverted);
void		ft_get_transf_obj(t_shapes *s, t_tuple coord, t_tuple orientation, t_tuple scale);
t_ray	ft_set_transf_ray(t_ray ray, t_matrix inverted);

// LIGHT
t_tuple	ft_normal_at_sph(t_shapes *sphere, t_tuple w_point);
t_tuple	ft_reflect(t_tuple incoming, t_tuple normal);
t_color	ft_lighting(t_material m, t_tuple point, t_light light, t_camera camera, t_tuple normal);
void	ft_material_to_shape(t_material m, t_shapes *shape);
t_camera	ft_create_camera_a(t_tuple pos, t_tuple norm, float fov); // this must go to the parser
t_light	ft_create_light_a(t_tuple pos, t_color color, float bright); // this must go to the parser
t_material ft_create_material(void);

//parse
int			ft_count_members (char **split);
int			ft_check_null_split(char **split);
int			ft_check_syntax(t_canvas *canvas, char *file);
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

//minilibx
int			ft_setup(t_canvas *canvas);
int			ft_refreshframe(t_canvas *canvas);
int			close_handler(t_canvas *canvas);
int			mouse_handler(int mousecode, int x, int y, t_canvas *canvas);
int			key_handler(int keysym, t_canvas *canvas);
void		ft_mlx_init(t_canvas *canvas);
void  		ft_pixel_put(t_img *data, int x, int y, int color);


int			ft_handle_key_hook(int key, t_canvas *canvas);
int			ft_free_mlx(t_canvas *canvas);

//TESTING/////////////////////////////////////////////
void	test_ft_is_tuples_equal();
void	test_ft_sub_tuple();
void	ft_print_tuple(t_tuple tuple, char *name);
void	ft_draw_square(t_canvas *canvas,t_tuple start, t_tuple sides, int color);
void	ft_print_objects(t_canvas canvas);
void	operations_testing(void);
void	jumpingball(t_canvas *canvas);
void	ft_draw_square(t_canvas *canvas,t_tuple start, t_tuple sides, int color);


t_tuple		ft_operator(t_tuple a, char op, t_tuple b);
int			ft_is_float_equal(double num1, double num2);
int			ft_is_tuples_equal(t_tuple tuple1, t_tuple tuple2);
t_tuple		ft_add_tuple(t_tuple tuple1, t_tuple tuple2);
double		ft_magn_tuple(t_tuple tuple);
t_tuple		ft_sub_tuple(t_tuple tuple1, t_tuple tuple2);
t_tuple		ft_neg_tuple(t_tuple tuple);
t_tuple		ft_scalar_tuple(t_tuple tuple, double value);
t_tuple		ft_norm_vector(t_tuple tuple);
double		ft_dotprod_vector(t_tuple a, t_tuple b);
t_tuple		ft_crossprod_vector(t_tuple a, t_tuple b);
t_matrix	ft_matrix_mult(t_matrix A, t_matrix B);


t_tuple		ft_mult_matrix_tuple(t_matrix A, t_tuple B);
t_matrix	ft_transpose_matrix(t_matrix src);
//Matrix
t_matrix	ft_submatrix(t_matrix src, int row, int col);
t_matrix	ft_create_matrix(int rows, int cols, int identity);
void		ft_set_matrix_values(t_matrix *m, double values[4][4]);
int			ft_are_matrixes_equal(t_matrix a, t_matrix b);
double		ft_minor(t_matrix m, int row, int col);
double		ft_cofactor(t_matrix m, int row, int col);
double		ft_determinant(t_matrix m);
t_matrix	ft_invert_matrix(t_matrix m);
t_tuple		ft_translate(t_tuple translation, t_tuple to_translate);
t_tuple	ft_scale(t_tuple scale, t_tuple to_scale);
t_tuple		ft_rotation_x(t_tuple tuple, double angle);
t_tuple		ft_rotation_y(t_tuple tuple, double angle);
t_tuple		ft_rotation_z(t_tuple tuple, double angle);

t_ambient	*ft_init_ambient(int ratio, t_color color);
t_camera	*ft_init_camera(t_tuple coord, t_tuple norm, int fov);
t_light		*ft_init_light(t_tuple coord, int bright, t_color color);
t_sphere	*ft_init_sphere(t_tuple coord, int diameter, t_color color);
t_plane		*ft_init_plane(t_tuple coord, t_tuple norm, t_color color);
t_cylinder	*ft_init_cylinder(t_tuple coord, t_tuple norm,
				t_cyl_size size, t_color color);
void	ft_add_object(void **head, void *object);
#endif
