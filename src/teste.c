#include "minirt.h"

int	main()
{
	t_canvas	canvas;
	ft_init_canvas(&canvas);
	// ft_mlx_init(&canvas);
	ft_setup(&canvas);
	//jumpingball(&canvas);
	
	t_color color;
	color = ft_add_tuple((t_tuple){0,0,0,3}, (t_tuple){15, 30, 25, 3});
	ft_print_tuple((t_tuple)color, "teste cor");
	
	
	return (0);
}
