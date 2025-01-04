#include "minirt.h"

void	ft_menu(t_canvas *canvas)
{
	int	i;

	if (canvas->help)
	{
		i = 19;
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "Press 'h' to close help");
		i--;
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - 6 - HEIGHT_POS * i--, WHITE,
				 "Keyboard commands:");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "\"Esc\"       --> exit");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "o p         --> adjust pixel upscale");
		i--;
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "w a s d q e --> move");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "Arrow keys  --> rotate");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "Space/c     --> camera move up / down");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "z           --> reset camera position");
		i--;
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "mouse left click --> select object"); //change brightness in object, to sum in lighting function
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "l           --> select light");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "x           --> abort selection"); //reset color vars sum
		i--;
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "Left Shift hold --> subtract enable");	
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "r g b      --> adjust R-G-B color"); 
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "t    --> adjust bright object/light"); 
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "1 2 3      --> adjust dimensions");

	}
	else
	{
		i = 2;
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
				 "Press 'h' for help");
		mlx_string_put(canvas->mlx, canvas->win, W_POS, WIN_H - HEIGHT_POS * i, WHITE,
				 "Pixel upscale:");
		if (canvas->step > 9)
		{
			canvas->char_step[0] = '1';
			canvas->char_step[1] = canvas->step - 10 + '0';
		}
		else
		{
			canvas->char_step[0] = '0';
			canvas->char_step[1] = canvas->step + '0';
		}
		mlx_string_put(canvas->mlx, canvas->win, W_POS + 105 , WIN_H - HEIGHT_POS * i--, WHITE,
				 canvas->char_step);
		


	}
		
}
