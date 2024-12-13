#include "libft.h"
#include "minirt.h"
#include <unistd.h>

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
	t_objects *current = canvas.objects;
	while (current) {
		if (current->cont) {
			t_shapes *shape = (t_shapes *)current->cont;
			switch (shape->type) {
				case PLANE: printf(YELLOW"PLANE\n"RESET); break;
				case CYLINDER: printf(YELLOW"CYLINDER\n"RESET); break;
				case SPHERE: printf(YELLOW"SPHERE\n"RESET); break;
			}
		} else {
			fprintf(stderr, "Warning: current->cont is null\n");
		}
		current = current->next;
	}
	ft_free_canvas(&canvas);
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
