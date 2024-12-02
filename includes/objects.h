#include "ft_math.h"
//OBJECTS

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
	// t_matrix		transform;
	// t_matrix		inverted;
	// t_matrix		transposed;
	// t_material		material;
}	t_shapes;

typedef struct s_inter
{
	double	value;
	t_shapes *shape;
}	t_inter;

// WILL NOT USE
t_ambient	*ft_init_ambient(int ratio, t_color color);
t_camera	*ft_init_camera(t_tuple coord, t_tuple norm, int fov);
t_light		*ft_init_light(t_tuple coord, int bright, t_color color);
t_sphere	*ft_init_sphere(t_tuple coord, int diameter, t_color color);
t_plane		*ft_init_plane(t_tuple coord, t_tuple norm, t_color color);
t_cylinder	*ft_init_cylinder(t_tuple coord, t_tuple norm,
				t_cyl_size size, t_color color);
void	ft_add_object(void **head, void *object);
