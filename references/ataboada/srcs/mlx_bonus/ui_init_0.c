/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:43:20 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/18 12:07:53 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_set_ui(t_world *w)
{
	w->ui.begin = UI_WIN_WIDTH - UI_WIDTH;
	if (w->ui.n_objs[0] > 0)
		w->ui.sp = malloc(sizeof(t_shapes *) * w->ui.n_objs[0]);
	if (w->ui.n_objs[1] > 0)
		w->ui.pl = malloc(sizeof(t_shapes *) * w->ui.n_objs[1]);
	if (w->ui.n_objs[2] > 0)
		w->ui.cy = malloc(sizeof(t_shapes *) * w->ui.n_objs[2]);
	if (w->ui.n_objs[3] > 0)
		w->ui.co = malloc(sizeof(t_shapes *) * w->ui.n_objs[3]);
	if (w->ui.n_objs[4] > 0)
		w->ui.cb = malloc(sizeof(t_shapes *) * w->ui.n_objs[4]);
	if (w->ui.n_objs[5] > 0)
		w->ui.tr = malloc(sizeof(t_shapes *) * w->ui.n_objs[5]);
	if (w->ui.n_li > 0)
		w->ui.li = malloc(sizeof(t_light *) * w->ui.n_li);
	ft_set_element_arrays(w);
	ft_set_n_buttons(w);
	ft_set_tags(w);
	ft_set_menu(w);
	ft_set_header(w);
	ft_set_button_limits(w);
	ft_set_ranges(w);
	ft_set_themes(w);
}

void	ft_set_element_arrays(t_world *w)
{
	t_list	*tmp;

	tmp = w->objects;
	while (tmp)
	{
		if (((t_shapes *)tmp->content)->type == SPHERE)
			w->ui.sp[w->i[0]++] = (t_shapes *)tmp->content;
		else if (((t_shapes *)tmp->content)->type == PLANE)
			w->ui.pl[w->i[1]++] = (t_shapes *)tmp->content;
		else if (((t_shapes *)tmp->content)->type == CYLINDER)
			w->ui.cy[w->i[2]++] = (t_shapes *)tmp->content;
		else if (((t_shapes *)tmp->content)->type == CONE)
			w->ui.co[w->i[3]++] = (t_shapes *)tmp->content;
		else if (((t_shapes *)tmp->content)->type == CUBE)
			w->ui.cb[w->i[4]++] = (t_shapes *)tmp->content;
		else if (((t_shapes *)tmp->content)->type == TRIANGLE)
			w->ui.tr[w->i[5]++] = (t_shapes *)tmp->content;
		tmp = tmp->next;
	}
	tmp = w->lights;
	while (tmp)
	{
		w->ui.li[w->i[6]++] = (t_light *)tmp->content;
		tmp = tmp->next;
	}
}

void	ft_set_n_buttons(t_world *w)
{
	int	index;
	int	counter;

	index = -1;
	counter = 3;
	while (++index < 6)
	{
		if (w->ui.n_objs[index] > 0)
			counter += 1;
	}
	w->ui.n_buttons = counter;
}

void	ft_set_tags(t_world *w)
{
	int	s_index;
	int	t_index;

	s_index = 0;
	t_index = 3;
	w->ui.tags[0] = "    Theme";
	w->ui.tags[1] = "   Camera";
	w->ui.tags[2] = "    Light";
	if (w->ui.n_objs[s_index++] > 0)
		w->ui.tags[t_index++] = "    Sphere";
	if (w->ui.n_objs[s_index++] > 0)
		w->ui.tags[t_index++] = "    Plane";
	if (w->ui.n_objs[s_index++] > 0)
		w->ui.tags[t_index++] = "   Cylinder";
	if (w->ui.n_objs[s_index++] > 0)
		w->ui.tags[t_index++] = "     Cone";
	if (w->ui.n_objs[s_index++] > 0)
		w->ui.tags[t_index++] = "     Cube";
	if (w->ui.n_objs[s_index++] > 0)
		w->ui.tags[t_index++] = "  Triangle";
}

void	ft_set_menu(t_world *w)
{
	w->ui.keys[0] = "Right  translation x";
	w->ui.keys[1] = "Left   translation x";
	w->ui.keys[2] = "Up     translation y";
	w->ui.keys[3] = "Down   translation y";
	w->ui.keys[4] = "Space  translation z";
	w->ui.keys[5] = "Alt    translation z";
	w->ui.keys[6] = "W      rotation x";
	w->ui.keys[7] = "S      rotation x";
	w->ui.keys[8] = "A      rotation y";
	w->ui.keys[9] = "D      rotation y";
	w->ui.keys[10] = "M      rotation z";
	w->ui.keys[11] = "N      rotation z";
	w->ui.keys[12] = "Plus   zoom in";
	w->ui.keys[13] = "Minus  zoom out";
	w->ui.keys[14] = "Z      camera default";
	w->ui.keys[15] = "Minus  intensity";
	w->ui.keys[16] = "Plus   intensity";
	w->ui.keys[17] = "Tab    next obj";
	w->ui.keys[18] = "Plus   obj size";
	w->ui.keys[19] = "Minus  obj size";
}
