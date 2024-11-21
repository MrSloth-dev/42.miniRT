#include "ft_math.h"
//OBJECTS
typedef struct s_ambient
{
	struct s_ambient	*next;
	double				ratio;
	t_color				color;
}	t_ambient;

typedef struct s_camera
{
	struct s_camera	*next;
	t_tuple			coord;
	t_tuple			norm;//[0-1]
	int				fov; //0-180
}	t_camera;

typedef struct s_light
{
	struct s_light	*next;
	t_tuple			coord;
	int				bright;
	t_color			color;
}	t_light;

typedef struct s_sphere
{
	struct s_sphere	*next;
	t_tuple			coord;
	double			diameter;
	t_color			color;
}	t_sphere;

typedef struct s_plane
{
	struct s_plane	*next;
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
	struct s_cylinder	*next;
	t_tuple				coord;
	t_tuple				norm;//[0-1]
	t_cyl_size			size;
	t_color				color;

}	t_cylinder;

t_ambient	*ft_lstnew_ambient(int ratio, t_color color);
t_camera	*ft_lstnew_camera(t_tuple coord, t_tuple norm, int fov);
t_light		*ft_lstnew_light(t_tuple coord, int bright, t_color color);
t_sphere	*ft_lstnew_sphere(t_tuple coord, int diameter, t_color color);
t_plane		*ft_lstnew_plane(t_tuple coord, t_tuple norm, t_color color);

t_cylinder	*ft_lstnew_cylinder(t_tuple coord, t_tuple norm,
				t_cyl_size size, t_color color);
void	*ft_lstlast(void *head);
void	ft_add_object(void **head, void *object);
