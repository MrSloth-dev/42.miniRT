/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _06_085_1_create_material.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:29:29 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	ft_create_material(void)
{
	t_material	m;

	m.color = (t_color){1, 1, 1, 3};
	m.ambient = 0.1;
	m.ambient_color = (t_tuple){0.1, 0.1, 0.1, 3};
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0f;
	return (m);
}
