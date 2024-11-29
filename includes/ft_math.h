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
//invert matrix
double 		ft_determinant_mtx_two_by_two(t_matrix m, int r, int c);
t_matrix	ft_submatrix(t_matrix src, int row, int col);
