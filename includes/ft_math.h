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
