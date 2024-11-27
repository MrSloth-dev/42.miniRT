/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:32:13 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/17 17:46:37 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Creates a new xpm pattern.
t_pattern	ft_create_xpm_pat(t_world *w, t_shapes *s, int type, char *xpm_file)
{
	t_pattern	pattern;

	pattern.type = type;
	pattern.a = (t_color){0, 0, 0, 3};
	pattern.b = (t_color){0, 0, 0, 3};
	pattern.transform = ft_create_matrix(4, 4, YES);
	pattern.inverted = ft_create_matrix(4, 4, YES);
	pattern.xpm = ft_read_xpm(w, s, xpm_file);
	free(xpm_file);
	return (pattern);
}

// Reads the xpm file and returns the canvas.
t_canvas	ft_read_xpm(t_world *w, t_shapes *s, char *xpm_file)
{
	int			fd;
	int			size[2];
	void		*mlx_ptr;
	t_image		img_ptr;
	t_canvas	canvas;

	fd = open(xpm_file, O_RDONLY);
	if (fd < 0)
	{
		free(xpm_file);
		ft_perror(w, s, "XPM file not found");
	}
	mlx_ptr = mlx_init();
	img_ptr.img = mlx_xpm_file_to_image(mlx_ptr, xpm_file, &size[0], &size[1]);
	if (!img_ptr.img)
	{
		free(xpm_file);
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		ft_perror(w, s, "Invalid XPM file");
	}
	canvas = ft_create_canvas(size[0], size[1]);
	ft_load_xpm(canvas, img_ptr, mlx_ptr);
	close(fd);
	return (canvas);
}

// Parses the xpm file and loads it into the canvas.
void	ft_load_xpm(t_canvas scene, t_image img_ptr, void *mlx_ptr)
{
	int			x;
	int			y;
	int			*color;

	color = (int *)mlx_get_data_addr(img_ptr.img, &img_ptr.bpp,
			&img_ptr.line_length, &img_ptr.endian);
	y = -1;
	while (++y < scene.height)
	{
		x = -1;
		while (++x < scene.width)
			scene.pixels[y][x] = ft_rgb_to_int(color[y * scene.width + x]);
	}
	mlx_destroy_image(mlx_ptr, img_ptr.img);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}

// Returns the color of the xpm at the specified point.
t_color	ft_xpm_at(t_pattern pattern, t_point point)
{
	int		x;
	int		y;
	t_uv	uv;

	uv.u = (point.x + 1.0) / 2.0;
	uv.v = 1.0 - ((point.y + 1.0) / 2.0);
	x = (int)(uv.u * (pattern.xpm.width - 1) + 0.5);
	y = (int)(uv.v * (pattern.xpm.height - 1) + 0.5);
	return (pattern.xpm.pixels[y][x]);
}

t_color	ft_xpm_at_shape(int shape_type, t_pattern pattern, t_point point)
{
	int		x;
	int		y;
	t_uv	uv;

	if (shape_type == PLANE)
	{
		uv.u = point.x / (pattern.xpm.width / 50) + 0.5;
		uv.v = 0.5 - point.z / (pattern.xpm.height / 50);
		x = abs((int)(uv.u * (pattern.xpm.width - 1) + 0.5));
		y = abs((int)(uv.v * (pattern.xpm.height - 1) + 0.5));
		x = x % pattern.xpm.width;
		y = y % pattern.xpm.height;
		return (pattern.xpm.pixels[y][x]);
	}
	uv = ft_cartesian_to_spherical(point);
	x = (int)(uv.u * (pattern.xpm.width - 1) + 0.5);
	y = (int)(uv.v * (pattern.xpm.height - 1) + 0.5);
	x = x % pattern.xpm.width;
	y = y % pattern.xpm.height;
	if (x < 0)
		x += pattern.xpm.width;
	if (y < 0)
		y += pattern.xpm.height;
	return (pattern.xpm.pixels[y][x]);
}
