/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:01:59 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 02:03:24 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdbool.h>

typedef struct s_pt
{
	int		x;
	int		y;
}			t_pt;

typedef struct s_ln_pt
{
// vars for draw_line algorithm
	int		delta_x;
	int		delta_y;
	int		x_direction;
	int		y_direction;
	int		err;
	int		e2;
	int		y_str;
	int		x_str;
// points to use on draw_line
	t_pt	actual;
	t_pt	next;
}			t_ln_pt;

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

typedef t_tuple	t_color;

typedef struct s_limit
{
	double	min;
	double	max;
}	t_limit;
typedef t_list	t_interlst;

typedef t_list	t_objects;

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
}	t_count;

typedef struct s_ray
{
	t_tuple	pos;
	t_tuple	dir;
}	t_ray;

typedef struct s_ambient
{
	double				ratio;
	t_color				color;
	t_color				prev_color;
}	t_ambient;

typedef struct s_camera
{
	// VARS ON PARSING
	t_tuple			coord;
	t_tuple			norm;//[0-1]
	//VARS ON BOOK PAGE 100
	double			h_size;
	double			v_size;
	double			field_v;
	t_matrix		transf;
	t_matrix		reset;
	t_matrix		inverted;
	t_matrix		rotate;
	t_matrix		inv_rotate;
	double			px_size;
	double			half_view;
	double			half_width;
	double			half_height;
	double			aspect;
}	t_camera;

typedef struct s_light
{
	t_tuple			coord;
	t_color			color;
	t_tuple			intensity;
	t_color			prev_color;
	t_color			prev_intensity;
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
}	t_cyl_size;

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
};

typedef struct s_material
{
	t_color	color; //0 - 1
	double	ambient; //0 - 1
	t_color	ambient_color;
	double	diffuse; // 0 - 1
	double	specular; // 0 - 1
	double	shininess; //10 - 200 (bigger the number lower the shininess)
}	t_material;

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
	t_matrix		rotate;
	t_matrix		inv_rotate;
	t_material		material;
	bool			selected;
}	t_shapes;

typedef struct s_inter
{
	double		value;
	t_shapes	*shape;
}	t_inter;

typedef struct s_canvas
{
	void		*mlx;
	void		*win;
	t_img		img;
	double		height;
	double		width;
	char		*program;
	char		*name;
	char		*file;
	char		*gnl_rest;
	double		scale;
	int			help;
	int			step;
	int			debug;
	t_img		*menu;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_objects	*objects;
	t_count		count;
// vars for event handle
	char		char_step[3];
	int			shift_press;
	int			mouse_drag;
	int			mouse_prev_x;
	int			mouse_sum_x;
	int			mouse_prev_y;
	int			mouse_sum_y;
	t_shapes	*object_selected;
	int			light_selected;
	int			disco_color;
	double		disco_dance;
// vars for shown axis
	t_ln_pt		local_x;
	t_ln_pt		local_y;
	t_ln_pt		local_z;
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
}	t_comp;
