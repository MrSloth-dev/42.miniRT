#include "libft.h"

#include <stdbool.h>

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

typedef t_list t_objects;

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
	// VARS ON PARSING
	t_tuple			coord;
	t_tuple			norm;//[0-1]
	double			fov; //0-180
	//VARS ON BOOK PAGE 100
	double			h_size;
	double			v_size;
	double			field_v;
	t_matrix		transf;
	t_matrix		reset;
	t_matrix		inverted;
	double			px_size;
	double			half_view;
	double			half_width;
	double			half_height;
}	t_camera;

typedef struct s_light
{
	t_tuple			coord;
	t_color			color;
	t_tuple			intensity;
}	t_light;

typedef struct s_sphere
{
	t_tuple			coord;
	double			diameter;
}	t_sphere;

typedef struct s_plane
{
	t_tuple			coord;
	t_tuple			norm;//[0-1]
}	t_plane;

typedef struct s_cyl_size
{
	double				diameter;
	double				height;
	double				min;
	double				max;
} t_cyl_size;

typedef struct s_cylinder
{
	t_tuple				coord;
	t_tuple				norm;//[0-1]
	t_cyl_size			size;
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
	t_color	color; //0 -1
	double	ambient; //0- 1
	t_color	ambient_color;
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
	};
	t_matrix		inverted;
	t_matrix		transform;
	t_matrix		transposed;
	t_material		material;
	bool			selected;
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
	int			step;
	char		char_step[2];
	t_img		*menu;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_objects	*objects;


	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_count		count;

	int			drag;
	int			mouse_calc;
	int			mouse_x;
	int			mouse_y;
}	t_canvas;

typedef struct s_iter
{
	int		r;
	int		c;
	int		rs;
	int		cs;
	int		k;
	int		x;
	int		y;
	int		y_step;
	int		x_step;
	double	a;
	double	b;
	double	cc;
	double	d;
	double	inter_one;
	double	inter_two;
}	t_iter;

typedef struct s_comp
{
	double		value;
	t_shapes	*shape;
	t_tuple		point;
	t_tuple		over_point;
	t_tuple		eyev;
	t_tuple		normalv;
	bool		inside;
	bool		in_shadow;
	t_color		efective_color;
	t_color		specular;
	t_color		ambient_on_object;
	t_color		diffuse;
	bool		selected;
} t_comp;
