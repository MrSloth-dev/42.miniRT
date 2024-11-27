/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:26:27 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/16 11:57:08 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// -------------------------------- INCLUDES -----------------------------------

# include "../libft/libft.h"
# include "maths.h"
# include "mlx_utils.h"

// --------------------------------- ENUMS -------------------------------------

enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	CUBE,
	TRIANGLE
};

enum e_pattern
{
	NONE,
	STRIPES,
	GRADIENT,
	RING,
	CHECKERS,
	XPM
};

// --------------------------------- STRUCTS -----------------------------------

typedef struct s_canvas
{
	int				width;
	int				height;
	t_color			**pixels;
}	t_canvas;

typedef struct s_amb
{
	double			ratio;
	t_vec3			color;
}	t_amb;

typedef struct s_camera
{
	int				hsize;
	int				vsize;
	double			fov;
	t_matrix		transform;
	t_matrix		inverted;
	double			half_width;
	double			half_height;
	double			pixel_size;
}	t_camera;

typedef struct s_light
{
	t_point			coordinates;
	t_color			intensity;
}	t_light;

typedef struct s_sphere
{
	double			diameter;
	t_point			coordinates;
}	t_sphere;

typedef struct s_plane
{
	t_point			coordinates;
	t_vec3			orientation;
}	t_plane;

typedef struct s_cylinder
{
	double			minimum;
	double			maximum;
	bool			closed;
	t_point			coordinates;
	t_vec3			orientation;
	double			diameter;
	double			height;
}	t_cylinder;

typedef struct s_cone
{
	double			minimum;
	double			maximum;
	bool			closed;
	t_point			coordinates;
	t_vec3			orientation;
	double			diameter;
	double			height;
}	t_cone;

typedef struct s_cube
{
	t_point			coordinates;
	t_vec3			orientation;
	double			size;
	double			side;
}	t_cube;

typedef struct s_triangle
{
	t_point			p1;
	t_point			p2;
	t_point			p3;
	t_vec3			e1;
	t_vec3			e2;
	t_vec3			normal;
}	t_triangle;

typedef struct s_pattern
{
	enum e_pattern	type;
	t_color			a;
	t_color			b;
	t_matrix		transform;
	t_matrix		inverted;
	t_canvas		xpm;
}	t_pattern;

typedef struct s_uv
{
	double			u;
	double			v;
}	t_uv;

typedef struct s_material
{
	t_color			color;
	t_color			ambient;
	double			diffuse;
	double			specular;
	double			shininess;
	t_pattern		pattern;
	double			reflective;
	double			transparency;
	double			refractive_index;
}	t_material;

typedef struct s_shapes
{
	enum e_type		type;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
		t_cone		cone;
		t_cube		cube;
		t_triangle	triangle;
	};
	t_matrix		transform;
	t_matrix		inverted;
	t_matrix		transposed;
	t_material		material;
}	t_shapes;

typedef struct s_intersection
{
	double			t;
	t_shapes		*object;
}	t_intr;

typedef t_list	t_intrs;

typedef struct s_ray
{
	t_point			origin;
	t_vec3			direction;
}	t_ray;

typedef struct s_comps
{
	double			t;
	t_shapes		*object;
	t_point			point;
	t_vec3			eyev;
	t_vec3			normalv;
	bool			inside;
	t_point			over_point;
	t_point			under_point;
	t_vec3			reflectv;
	double			n1;
	double			n2;
}	t_comps;

typedef struct s_image
{
	int				bpp;
	int				endian;
	int				line_length;
	void			*img;
	char			*addr;
}	t_image;

typedef struct s_world
{
	int				width;
	int				height;
	t_amb			ambient;
	t_camera		*camera;
	t_list			*lights;
	t_list			*objects;
	void			*mlx;
	void			*win;
	t_image			img;
	t_image			img2;
	t_ui			ui;
	int				status_key;
	int				i[7];
	t_point			cam_coords;
	t_vec3			cam_orient;
	double			cam_fov;
	t_matrix		cam_reset;
	char			*line;
}	t_world;

typedef struct s_aux
{
	double			f;
	double			u;
	double			v;
	double			t;
	double			det;
	double			a;
	double			b;
	double			c;
	double			discriminant;
	double			t0;
	double			t1;
	double			y0;
	double			y1;
}	t_aux;

typedef struct s_thread
{
	int				start;
	int				end;
	t_world			*world;
	t_camera		*camera;
	char			*dst;
}	t_thread;

#endif
