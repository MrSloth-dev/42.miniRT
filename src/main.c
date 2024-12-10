#include "libft.h"
#include "minirt.h"
#include <unistd.h>


void	ft_free_objects(t_objects *list)
{
	t_objects *temp;
	while (list)
	{
		temp = list;
		temp->cont = 0;
		list = list->next;
		ft_free(temp);
	}
}
void	ft_free_canvas(t_canvas *canvas)
{
	ft_free_objects(canvas->objects);
}

int	main(int argc, char *argv[])
{
	t_canvas	canvas;

	canvas.name = argv[0] + 2;

	(void)argc;
	if (argc != 2)
		return (ft_printf(2, "Error in argv!\n"));
	ft_init_canvas(&canvas);
	// ft_mlx_init(&canvas);
	// ft_setup(&canvas);
	if (ft_parse(&canvas, argv[1]) == 0)
		return (1);
	((t_shapes *)canvas.objects->cont)->material = ft_create_material();
	while (canvas.objects && (t_shapes *)canvas.objects->cont)
	{
		if (((t_shapes *)canvas.objects->cont))
			printf("ok %d\n\n", ((t_shapes *)canvas.objects->cont)->type);
		// canvas.objects = canvas.objects->next;
		break;
	}
	// ft_print_tuple(((t_shapes *)canvas.objects)->sph.coord, "sphere coord");
	// ft_free_canvas(&canvas);
	// ft_print_objects(canvas);
	//
	// m = ft_create_matrix(4, 4);
	// ft_set_matrix_values(&m,(double[4][4]){{1,2,3,4}, {5.5,6.5,7.5,8.5}, {9,10,11,12}, {13.5,14.5,15.5,16.5}});
	// ft_print_matrix(m);
	// operations_testing();
	//
	//jumpingball(&canvas);
	// ft_draw_square(&canvas, (t_tuple){150, 150, 0, 0}, (t_tuple){150, 150, 0, 0}, 0xFFFF0000);
	// mlx_key_hook(canvas.win, key_handler, &canvas);
	// mlx_hook(canvas.win, DestroyNotify, 0L, &close_handler, &canvas);
	// mlx_loop(canvas.mlx);
	return (0);
}
