#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
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

#define WIN_HEIGHT 600
#define WIN_WIDTH 920
#define IMG_HEIGHT 600
#define IMG_WIDTH 920

#define ROUND_ERROR 0.00001
#define ERR_INPUT 1
#define ERR_MLX 2

#define T_VECTOR 0
#define T_POINT 1

typedef struct s_matrix
{
	int			rows;
	int			cols;
	double		data[4][4];
}				t_matrix;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	int		type;
}	t_tuple;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_limit
{
	double	min;
	double	max;
}	t_limit;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_canvas
{
	void		*mlx;
	char		*program;
	char		*name;
	void		*win;
	t_img		*img;
	t_limit		winlimit_x;
	t_limit		winlimit_y;
	t_limit		color;
	t_limit		iter;
	double		scale;
	int			help;
	t_img		*menu;
}				t_canvas;

void	ft_tuple_init(t_tuple *tuple, t_point coord, int type);
void	ft_assert(int condition, char *message);
//oper.c
t_tuple	ft_add_tuple(t_tuple tuple1, t_tuple tuple2);
double	ft_magn_tuple(t_tuple tuple);
t_tuple	ft_sub_tuple(t_tuple tuple1, t_tuple tuple2);
t_tuple	ft_neg_tuple(t_tuple tuple);
t_tuple	ft_scalar_tuple(t_tuple tuple, double value);
t_tuple	ft_mul_tuple(t_tuple tuple1, t_tuple tuple2);
t_tuple ft_norm_vector(t_tuple tuple);
double	ft_dotprod_vector(t_tuple a, t_tuple b);
t_tuple	ft_crossprod_vector(t_tuple a, t_tuple b);

int		ft_printf(int fd, const char *str, ...);

void ft_print_matrix(t_matrix m);
t_matrix	ft_create_matrix(int rows, int cols);
void	ft_set_matrix_values(t_matrix *m, double values[4][4]);
//minilibx
int	ft_refreshframe(t_canvas *canvas);
int	close_handler(t_canvas *canvas);
int	mouse_handler(int mousecode, int x, int y, t_canvas *canvas);
int	key_handler(int keysym, t_canvas *canvas);

//parse
int	ft_check_syntax(t_canvas *canvas, char *file);
int	ft_parse(t_canvas *canvas, char *file);

