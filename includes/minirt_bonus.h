/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:01:55 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/08 02:07:21 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "minirt.h"

# define TR 16

# include <pthread.h>

typedef struct s_thread
{
	int				height_start;
	int				height_end;
	t_canvas		canvas;
}		t_thread;

void	ft_render_bonus(t_canvas *canvas);

#endif
