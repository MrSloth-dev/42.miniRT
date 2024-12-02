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
	int		w;
}	t_tuple;

typedef t_tuple t_color;

typedef struct s_limit
{
	double	min;
	double	max;
}	t_limit;


//oper.c
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
