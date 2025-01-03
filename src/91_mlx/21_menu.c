#include "minirt.h"

void	ft_menu(t_canvas *canvas)
{
	int	i;

	if (canvas->help)
	{
		i = 15;
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - 16 - HEIGHT_POS * i--, WHITE,
				 "Press 'h' to close help");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - 6 - HEIGHT_POS * i--, WHITE,
				 "Keyboard commands:");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "\"Esc\" -> exit");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "o p     -> adjust resolution:");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "w a s d q e -> camera move");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "Space/c -> camera move up and down");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "r       --> reset camera position");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "mouse left click -> select object"); //change brightness in object, to sum in lighting function
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "x       -> abort selection"); //reset color vars sum
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "h j k l -> object moove");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "9 0     -> adjust scale");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "8 9     -> adjust cylinder height"); 
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "r g b   -> adjust red-green-blue color"); 
	}
	else
	{
		canvas->char_step[0] = canvas->step + '0';
		i = 2;
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "Press 'h' for help");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i, WHITE,
				 "Pixel upscale:");
		mlx_string_put(canvas->mlx, canvas->win, W_POS + 110 , WIN_H - HEIGHT_POS * i, WHITE,
				 "1x ");
		mlx_string_put(canvas->mlx, canvas->win, W_POS + 125 , WIN_H - HEIGHT_POS * i--, WHITE,
				 canvas->char_step);


	}
		
}
