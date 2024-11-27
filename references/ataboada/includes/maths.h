/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:54:03 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/25 16:29:40 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

// -------------------------------- INCLUDES -----------------------------------

# include <math.h>
# include <stdbool.h>

// --------------------------------- MACROS ------------------------------------

# define EPSILON		0.00001

// --------------------------------- STRUCTS -----------------------------------

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec3;

typedef t_vec3	t_color;
typedef t_vec3	t_point;

typedef struct s_matrix
{
	int			rows;
	int			cols;
	double		data[4][4];
}				t_matrix;

// ------------------------------- PROTOTYPES ----------------------------------

// Vector Functions

t_vec3		ft_op(t_vec3 a, char op, t_vec3 b);
t_vec3		ft_ops(t_vec3 a, char op, double b);
double		ft_dot(t_vec3 a, t_vec3 b);
t_vec3		ft_cross(t_vec3 a, t_vec3 b);

double		ft_length(t_vec3 vec);
t_vec3		ft_normalize(t_vec3 vec);
t_vec3		ft_reflect(t_vec3 in, t_vec3 normal);

// Matrix Functions

t_matrix	ft_create_matrix(int rows, int cols, bool identity);
t_matrix	ft_translation_matrix(double x, double y, double z);
t_matrix	ft_scaling_matrix(double x, double y, double z);
t_matrix	ft_rotation_matrix(char axis, double radians);
t_matrix	ft_view_transform_matrix(t_point from, t_point to, t_vec3 up);

t_matrix	ft_multiply_matrix(t_matrix a, t_matrix b);
t_vec3		ft_multiply_matrix_tuple(t_matrix a, t_vec3 b);
t_matrix	ft_transpose_matrix(t_matrix a);
t_matrix	ft_invert_matrix(t_matrix a);

t_matrix	ft_get_submatrix(t_matrix a, int row, int col);
double		ft_get_determinant(t_matrix a);
double		ft_get_minor(t_matrix a, int row, int col);
double		ft_get_cofactor(t_matrix a, int row, int col);

#endif
