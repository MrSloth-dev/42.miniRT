/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:26:03 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/16 12:08:37 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// -------------------------------- INCLUDES -----------------------------------

# include "structs.h"
# include "mlx_utils.h"
# include "error.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h> 

// -------------------------------- DEFINES ------------------------------------

# define WIDTH		700
# define RATIO		1.8
# define YES		1
# define NO			0
# define MIN		1
# define MAX		0
# define DEG2RAD	0.017453292519943295
# define THREADS	4

// ------------------------------- PROTOTYPES ----------------------------------

// PARSER __________________________________________________________________

void		ft_parser(char *file, t_world *w);
void		ft_read_line(char *line, t_world *w, int *count);

int			ft_get_ambient(char *line, t_world *w);
int			ft_get_camera(char *line, t_world *w);
int			ft_get_light(char *line, t_world *w);

void		ft_get_sphere(char *line, t_world *w);
void		ft_get_plane(char *line, t_world *w);
void		ft_get_cylinder(char *line, t_world *w);

void		ft_perror(t_world *w, t_shapes *s, char *msg);
double		ft_atof(t_world *w, t_shapes *s, char *str);
double		ft_get_double(t_world *w, t_shapes *s, char **line, char d);
t_point		ft_get_tuple(t_world *world, t_shapes *s, char **line, double w);
bool		ft_in_range(t_vec3 v, double min, double max);

void		ft_get_transform(t_shapes *s, t_point c, t_vec3 o, double d);
t_matrix	ft_get_rotate(t_vec3 orien);

// RENDER ______________________________________________________________________

void		ft_render(t_camera *c, t_world *w);
t_ray		ft_ray_for_pixel(t_camera *c, int x, int y);
t_color		ft_color_at(t_world *world, t_ray r, int remaining);

void		ft_world_intersections(t_intrs **xs, t_world *world, t_ray r);
t_intr		*ft_hit(t_intrs *xs);

t_comps		ft_prepare_computations(t_intrs **lst, t_intr *hit, t_ray r);
t_vec3		ft_normal_at(t_shapes *s, t_point world_point);
void		ft_calculate_refracted_indices(t_comps *c, t_intrs **xs, t_intr *h);
void		ft_set_refracted_index(char n, t_comps *c, t_list *containers);

t_color		ft_shade_hit(t_world *w, t_comps *c, t_material m, int remaining);
bool		ft_is_shadowed(t_world *w, t_light *light, t_point point);

t_color		ft_lighting(t_comps *c, t_light *l, bool in_shadow);
t_color		ft_get_diffuse(t_comps *c, t_color effective_color, t_vec3 lightv);
t_color		ft_get_specular(t_comps *c, t_light *l, t_vec3 lightv);

t_color		ft_reflected_color(t_world *w, t_comps *c, int remaining);
t_color		ft_refracted_color(t_world *w, t_comps *c, int remaining);
double		ft_schlick(t_comps *c);

// SHAPES ______________________________________________________________________

t_shapes	*ft_create_shape(int type);
t_material	ft_create_material(void);
void		ft_add_shapes(t_list **lst, t_shapes *shapes);
double		ft_get_discriminant(int type, t_ray r, t_aux *a);

void		ft_sphere_intersections(t_intrs **i, t_shapes *s, t_ray r);

void		ft_plane_intersections(t_intrs **i, t_shapes *s, t_ray r);

void		ft_cylinder_intersections(t_intrs **i, t_shapes *s, t_ray r);
void		ft_cylinder_caps_intersections(t_intrs **i, t_shapes *s, t_ray r);
bool		ft_cylinder_check_cap(t_ray ray, double t);
t_vec3		ft_cylinder_normal_at(t_shapes *cylinder, t_point point);

void		ft_cone_intersections(t_intrs **i, t_shapes *s, t_ray r);
void		ft_cone_caps_intersections(t_intrs **i, t_shapes *s, t_ray ray);
bool		ft_cone_check_cap(t_ray ray, double t, double range);
t_vec3		ft_cone_normal_at(t_shapes *cone, t_point point);

void		ft_cube_intersections(t_intrs **xs, t_shapes *cube, t_ray r);
void		ft_cube_check_axis(double *t, double origin, double direction);
t_vec3		ft_cube_normal_at(t_point point);

void		ft_triangle_intersections(t_intrs **xs, t_shapes *s, t_ray r);

// TEXTURES ____________________________________________________________________

t_pattern	ft_create_pattern(char pattern_type, t_color a, t_color b);
t_color		ft_pattern_at_shape(t_pattern p, t_shapes *obj, t_point world_pt);

t_color		ft_stripe_at(t_pattern pattern, int shape_type, t_point point);
t_color		ft_gradient_at(t_pattern pattern, t_point point);
t_color		ft_ring_at(t_pattern pattern, int shape_type, t_point point);
t_color		ft_checkers_at(t_pattern pattern, int shape_type, t_point point);
t_uv		ft_cartesian_to_spherical(t_point point);

t_pattern	ft_create_xpm_pat(t_world *w, t_shapes *s, int type, char *file);
t_canvas	ft_read_xpm(t_world *w, t_shapes *s, char *file);
void		ft_load_xpm(t_canvas scene, t_image img_ptr, void *mlx_ptr);
t_color		ft_xpm_at(t_pattern pattern, t_point point);
t_color		ft_xpm_at_shape(int shape_type, t_pattern pattern, t_point point);

// UTILS _______________________________________________________________________

t_camera	*ft_create_camera(int hsize, int vsize, double fov);

t_canvas	ft_create_canvas(int width, int height);
void		ft_free_canvas(t_canvas canvas);

t_intr		*ft_create_intersection(double t, t_shapes *s);
void		ft_add_sorted_intersection(t_intrs **lst, t_shapes *s, double t);
void		ft_free_intersections(t_intrs **lst);

t_ray		ft_create_ray(t_point origin, t_vec3 direction);
t_ray		ft_transform_ray(t_ray ray, t_matrix matrix);

bool		ft_lst_contains(t_list *lst, t_shapes *shape);
void		ft_lst_remove(t_list **lst, t_shapes *shape);
t_list		*ft_lst_last(t_list *lst);
void		ft_free_lst(t_list **lst);

int			ft_clamp(int value, int min, int max);
int			ft_int_to_rgb(t_color color);
t_color		ft_rgb_to_int(int color);
void		ft_free_all_allocated_memory(t_world *w);

// BONUS _______________________________________________________________________

void		ft_set_camera(t_world *w);

void		ft_get_resolution(char *line, t_world *w);

void		ft_get_cone(char *line, t_world *w);
void		ft_get_cube(char *line, t_world *w);
void		ft_get_triangle(char *line, t_world *w);

void		ft_get_texture(t_world *w, t_shapes *s, char **line);
char		*ft_get_xpm(t_world *w, t_shapes *s, char **line);
void		ft_get_optics(t_world *w, t_shapes *s, char **line);

void		ft_render_threads(t_camera *c, t_world *w);
void		*ft_render_bonus(void *arg);

#endif
