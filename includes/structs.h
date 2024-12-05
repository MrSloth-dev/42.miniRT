#include "libft.h"

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

typedef struct s_ray
{
	t_tuple pos;
	t_tuple dir;
}	t_ray;

typedef struct s_ambient
{
	double				ratio;
	t_color				color;
}	t_ambient;

typedef struct s_camera
{
	t_tuple			coord;
	t_tuple			norm;//[0-1]
	int				fov; //0-180
}	t_camera;

typedef struct s_light
{
	t_tuple			coord;
	float			bright;
	t_color			color;
}	t_light;

typedef struct s_sphere
{
	t_tuple			coord;
	double			diameter;
	t_color			color;
}	t_sphere;

typedef struct s_plane
{
	t_tuple			coord;
	t_tuple			norm;//[0-1]
	t_color			color;
}	t_plane;

typedef struct s_cyl_size
{
	double				diameter;
	double				height;
} t_cyl_size;

typedef struct s_cylinder
{
	t_tuple				coord;
	t_tuple				norm;//[0-1]
	t_cyl_size			size;
	t_color				color;
}	t_cylinder;

enum e_type
{
	PLANE,
	CYLINDER,
	SPHERE,
	// CONE,
	// CUBE,
	// TRIANGLE
};

typedef struct s_material
{
	t_color	color; //0 -255
	double	ambient; //0- 1
	double	diffuse; // 0-1
	double	specular; // 0 -1
	double	shininess; //10 -200 (bigger the number lower the shininess)
} t_material;

typedef struct s_shapes
{
	enum e_type		type;
	union
	{
		t_plane		pla;
		t_cylinder	cyl;
		t_sphere	sph;
		// t_cone		cone;
		// t_cube		cube;
		// t_triangle	triangle;
	};
	t_matrix		inverted;
	t_matrix		transform;
	t_matrix		transposed;
	t_material		material;
}	t_shapes;

typedef struct s_inter
{
	double	value;
	t_shapes *shape;
}	t_inter;

typedef struct s_canvas
{
	void		*mlx;
	char		*program;
	char		*name;
	char		*file;
	void		*win;
	t_img		*img;
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

