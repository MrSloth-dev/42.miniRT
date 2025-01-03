#include "minirt.h"

void	ft_menu(t_canvas *canvas)
{
	int	i;

	i = 10;
	if (canvas->help)
	{
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - 16 - HEIGHT_POS * i--, 0xFFFFFF,
				 "Press 'h' to close help");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - 6 - HEIGHT_POS * i--, 0xFFFFFF,
				 "Keyboard commands:");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, 0xFFFFFF,
				 "\"Esc\" -> exit");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, 0xFFFFFF,
				 "w a s d -> camera move");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, 0xFFFFFF,
				 "Space/c -> camera move up and down");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, 0xFFFFFF,
				 "q e     -> select object"); //change brightness in object, to sum in lighting function
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, 0xFFFFFF,
				 "x       -> abort selection"); //reset color vars sum
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, 0xFFFFFF,
				 "h j k l -> object moove");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, 0xFFFFFF,
				 "u i     -> adjust radius / height"); 
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, 0xFFFFFF,
				 "r g b   -> adjust red-green-blue color"); 
	}
	else
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS, 0xFFFFFF,
				 "Press 'h' for help");
}
