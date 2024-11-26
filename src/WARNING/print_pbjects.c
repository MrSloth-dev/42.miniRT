#include "minirt.h"

void	ft_print_objects(t_canvas canvas)
{
	int i = 0;
	printf(YELLOW"\nAMBIENT\n"RESET);
	while (canvas.count.ambient > i)
	{
		printf("\n%d\n", i);
		printf("ambient ratio %f\n", canvas.ambient[i].ratio);
		printf("ambient color r %f\n", canvas.ambient[i].color.r);
		printf("ambient color g %f\n", canvas.ambient[i].color.g);
		printf("ambient color b %f\n", canvas.ambient[i].color.b);
		i++;
	}
	i = 0;
	printf(RED"\nCAMERA\n"RESET);
	while (canvas.count.camera > i)
	{
		printf("\n%d\n", i);
		printf("camera fov %d\n", canvas.camera[i].fov);
		printf("camera coord %f\n", canvas.camera[i].coord.x);
		printf("camera coord %f\n", canvas.camera[i].coord.y);
		printf("camera coord %f\n", canvas.camera[i].coord.z);
		printf("camera norm %f\n", canvas.camera[i].norm.x);
		printf("camera norm %f\n", canvas.camera[i].norm.y);
		printf("camera norm %f\n", canvas.camera[i].norm.z);
		i++;
	}
	i = 0;
	printf(RED"\nLIGHT\n"RESET);
	while (canvas.count.light > i)
	{
		printf("\n%d\n", i);
		printf("light bright %f\n", canvas.light[i].bright);
		printf("light coord %f\n", canvas.light[i].coord.x);
		printf("light coord %f\n", canvas.light[i].coord.y);
		printf("light coord %f\n", canvas.light[i].coord.z);
		printf("light color r = %f, ", canvas.light[i].color.r);
		printf("g = %f, ", canvas.light[i].color.g);
		printf("b = %f\n", canvas.light[i].color.b);
		i++;
	}
}
