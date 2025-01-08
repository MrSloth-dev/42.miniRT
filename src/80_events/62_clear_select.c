/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:37:50 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/03 15:38:07 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_clear_select(t_canvas *canvas)
{
	t_list	*cur;

	if (!canvas->objects || !canvas->objects->cont)
		return ;
	cur = canvas->objects;
	while (cur && cur->cont)
	{
		((t_shapes *)cur->cont)->selected = false;
		cur = cur->next;
	}
	canvas->object_selected = NULL;
	canvas->light_selected = 0;
}
