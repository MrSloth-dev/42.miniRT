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
#include "objects.h"
#include <X11/keysym.h>
#include <X11/X.h>

#define RED "\e[1;3;31m"
#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define RESET "\e[0m"

#define WIN_HEIGHT 1000
#define WIN_WIDTH 1000
#define IMG_HEIGHT 1000
#define IMG_WIDTH 1000

#define ROUND_ERROR 0.00001
#define ERR_INPUT 1
#define ERR_MLX 2

#define T_VECTOR 0
#define T_POINT 1
#define WHITESPACE " \t\n\r\v\f"

#ifndef ASSERT
# define ASSERT 0
#endif

typedef t_list t_interlst;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_count
{
	int			ambient;
	int			camera;
	int			light;
	int			sphere;
	int			plane;
	int			cylinder;
} t_count;

typedef struct s_canvas
{
	void		*mlx;
	char		*program;
	char		*name;
	char		*file;
	void		*win;
	t_img		*img;
	t_limit		winlimit_x;
	t_limit		winlimit_y;
	t_limit		color;
	t_limit		iter;
	double		scale;
	int			help;
	t_img		*menu;
	t_list		*objects;
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_count		count;
}	t_canvas;

typedef struct s_iter
{
	int		r;
	int		c;
	int		rs;
	int		cs;
	double	a;
	double	b;
	double	d;
}	t_iter;

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


//RAYS
t_tuple		ft_distance_ray(t_ray ray, double time);
t_ray		ft_create_ray(t_tuple pos, t_tuple dir);
void		ft_lstadd_sort_inter(t_interlst **lst, double value, t_shapes *shap);
void		ft_intersection_sphere(t_interlst **lst, t_ray ray, t_shapes *shap);
t_inter		*ft_hit_inter(t_interlst **lst);
t_ray		ft_translate_ray(t_tuple translation, t_ray ray);
t_ray		ft_scale_ray(t_tuple scaling, t_ray ray);
t_ray		ft_set_transf_ray(t_ray ray, t_matrix inverted);
void		ft_get_transf_obj(t_shapes *s, t_tuple coord, t_tuple orientation, double diam);
t_ray	ft_set_transf_ray(t_ray ray, t_matrix inverted);

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



#endif
