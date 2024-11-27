/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:49:08 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/13 13:35:38 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Initializes the t_canvas structure with the specified values.
t_canvas	ft_create_canvas(int width, int height)
{
	int			i;
	int			j;
	t_canvas	c;

	i = 0;
	c.width = width;
	c.height = height;
	c.pixels = (t_color **)malloc(sizeof(t_color *) * height);
	while (i < height)
	{
		j = 0;
		c.pixels[i] = (t_color *)malloc(sizeof(t_color) * width);
		while (j < width)
		{
			c.pixels[i][j] = (t_color){0, 0, 0, 3};
			j++;
		}
		i++;
	}
	return (c);
}

// Frees the memory allocated for the canvas structure.
void	ft_free_canvas(t_canvas canvas)
{
	int	i;

	i = 0;
	while (i < canvas.height)
	{
		free(canvas.pixels[i]);
		i++;
	}
	free(canvas.pixels);
}
