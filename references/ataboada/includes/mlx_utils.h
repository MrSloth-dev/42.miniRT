/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:55:39 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/17 17:56:41 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

// -------------------------------- INCLUDES -----------------------------------

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "minirt.h"

// --------------------------------- DEFINES -----------------------------------

# define ESC				65307
# define Z					122
# define W					119
# define A					97
# define S					115
# define D					100
# define M					109
# define N					110
# define UP					65362
# define DOWN				65364
# define LEFT				65361
# define RIGHT				65363
# define ALT				65513
# define SPACE				32
# define PLUS				65451
# define MINUS				65453
# define TAB				65289

# define PI					3.14159265358979323846
# define CAM_ROT			18
# define OBJ_ROT			18
# define CAM_TRA			1
# define OBJ_TRA			1
# define SCA_M				0.7
# define SCA_P				1.3

# define UI_WIN_WIDTH		1920
# define UI_WIDTH			450
# define UI_RATIO			1.92

# define BTN_W				120
# define BTN_H				60
# define GAP_ROW			150
# define GAP_COL			100
# define BTN_ROW			3
# define LINES_ROW			12
# define STR_GAP_UP			35
# define GAP_RIGHT			20
# define GAP_TOP			150
# define HEADER_TOP			30
# define HEADER_STR_GAP		12

# define UI_THEME			0b1
# define UI_CAMERA			0b10
# define UI_LIGHT			0b100
# define UI_SPHERE			0b1000
# define UI_PLANE			0b10000
# define UI_CYLINDER		0b100000
# define UI_CONE			0b1000000
# define UI_CUBE			0b10000000
# define UI_TRIANGLE		0b100000000

// --------------------------------- STRUCTS -----------------------------------

typedef struct s_pixel
{
	int		col;
	int		row;
}	t_pixel;

typedef struct s_area
{
	t_pixel	origin;
	int		width;
	int		height;
}	t_area;

typedef struct s_range
{
	int		min;
	int		max;
}	t_range;

typedef struct s_ui
{
	void			**li;
	void			**sp;
	void			**pl;
	void			**cy;
	void			**co;
	void			**cb;
	void			**tr;
	int				n_li;
	int				n_objs[6];
	int				n_buttons;
	int				begin;
	int				flags;
	int				tflag;
	char			*tags[9];
	char			*keys[20];
	char			*header[7];
	int				theme[6];
	int				themes[3][6];
	int				limits[9][4];
	t_range			ranges[9];
}	t_ui;

typedef struct s_image	t_image;
typedef struct s_world	t_world;

// -------------------------------- PROTOTYPES ---------------------------------

// MANDATORY ___________________________________________________________________

void		ft_open_window(t_world *w);

void		ft_set_hooks(t_world *w);
int			ft_button_press(int keycode, t_world *w);
int			ft_button_release(int keycode, t_world *w);
int			ft_close(t_world *w);

int			ft_update(void *ptr);
t_matrix	ft_update_camera(t_matrix t, int key);
t_matrix	ft_update_scaling(t_matrix t, int key);

// BONUS _______________________________________________________________________

void		ft_open_window(t_world *w);
void		ft_print_buttons(t_world *w);
void		ft_create_button(t_world *w, t_area area, int color);

void		ft_set_hooks(t_world *w);
int			ft_button_press(int k, t_world *w);
int			ft_button_release(int k, t_world *w);
int			ft_close(t_world *w);
int			ft_mouse_hook(int keycode, int x, int y, t_world *w);

int			ft_update(void *w);
void		ft_update_helper(t_world *w, int key);
void		ft_update_object(t_world *w, int key);

t_matrix	ft_update_camera(t_matrix t, int key);
t_matrix	ft_update_shapes(t_matrix t, int key);
void		ft_update_lights(t_world *w, int key);
t_matrix	ft_update_scaling(t_matrix t, int key);

void		ft_set_ui(t_world *w);
void		ft_set_element_arrays(t_world *w);
void		ft_set_n_buttons(t_world *w);
void		ft_set_tags(t_world *w);
void		ft_set_menu(t_world *w);

void		ft_set_header(t_world *w);
void		ft_set_button_limits(t_world *w);
void		ft_set_ranges(t_world *w);
void		ft_set_themes(t_world *w);
void		ft_free_ui(t_world *w);

void		ft_place_tags(t_world *w, int i);
int			ft_within_limits(t_world *w, int x, int y);
void		ft_set_flags(t_world *w, int button);
int			ft_get_new_index(t_world *w, int index);
void		ft_switch_theme(t_world *w);

void		ft_create_strings(t_world *w);
void		ft_menu_obj(t_world *w, int choice);
void		ft_mlx_string_put(t_world *w, t_range range, int color);

#endif
