#include "minirt.h"

int	main()
{
	t_canvas	canvas;
	ft_init_canvas(&canvas);
	// ft_mlx_init(&canvas);
	ft_setup(&canvas);
	//jumpingball(&canvas);
	
	t_color color1, color2, color;

	color1 = (t_tuple){0.15, 0.40, 0.60, 3};
	color2 = (t_tuple){0.10, 0.30, 0.20, 3};

	color = ft_operator(color1, '+', color2);
	ft_print_tuple((t_tuple)color, "teste cor");

	color = ft_operator(color1, '-', color2);
	ft_print_tuple((t_tuple)color, "teste cor");

	color = ft_operator(color1, '*', color2);
	ft_print_tuple((t_tuple)color, "teste cor");

	return (0);
}
