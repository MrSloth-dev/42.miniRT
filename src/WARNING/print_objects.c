#include "minirt.h"

void	ft_print_objects(t_canvas canvas)
{
	printf(YELLOW"\nAMBIENT\n"RESET);
	printf("\nambient count = %d\n", canvas.count.ambient);
	for (int i = 0; i < canvas.count.ambient; i++)
	{
		printf("A %f, %f, %f, %f\n", canvas.ambient[i].ratio , canvas.ambient[i].color.r, canvas.ambient[i].color.g, canvas.ambient[i].color.b);
	}
	printf(YELLOW"\nCAMERA\n"RESET);
	printf("\ncamera count = %d\n", canvas.count.camera);
	for (int i = 0; i < canvas.count.camera; i++)
	{
		printf("C %f, %f,%f %f, %f, %f, %d \n", canvas.camera[i].coord.x , canvas.camera[i].coord.y, canvas.camera[i].coord.z, canvas.camera[i].norm.x, canvas.camera[i].norm.y, canvas.camera[i].norm.z, canvas.camera[i].fov);
	}
	printf(YELLOW"\nLIGHT\n"RESET);
	printf("\nlight count = %d\n", canvas.count.light);
	for (int i = 0; i < canvas.count.light; i++)
	{
		printf("L %f, %f, %f |%f |%f, %f, %f\n", canvas.light[i].coord.x, canvas.light[i].coord.y, canvas.light[i].coord.z, canvas.light[i].bright, canvas.light[i].color.r, canvas.light[i].color.g, canvas.light[i].color.b);
	}
	printf(YELLOW"\nSphere\n"RESET);
	printf("\nsphere count = %d\n", canvas.count.sphere);
	for (int i = 0; i < canvas.count.sphere; i++)
	{
		printf("sp %f, %f, %f | %f| %f, %f, %f\n", canvas.sphere[i].coord.x, canvas.sphere[i].coord.y, canvas.sphere[i].coord.z, canvas.sphere[i].diameter, canvas.sphere[i].color.r, canvas.sphere[i].color.g, canvas.sphere[i].color.b);
	}
	printf(YELLOW"\nplane\n"RESET);
	printf("\nplane count = %d\n", canvas.count.plane);
	for (int i = 0; i < canvas.count.plane; i++)
	{
		printf("pl %f, %f, %f %f, %f, %f %f, %f, %f\n", canvas.plane[i].norm.x, canvas.plane[i].norm.y, canvas.plane[i].norm.z, canvas.plane[i].coord.x, canvas.plane[i].coord.y, canvas.plane[i].coord.z, canvas.plane[i].color.r, canvas.plane[i].color.g, canvas.plane[i].color.b);
	}
	printf(YELLOW"\ncylinder\n"RESET);
	printf("\ncylinder count = %d\n", canvas.count.cylinder);
	for (int i = 0; i < canvas.count.cylinder; i++)
	{
		printf("cy %f,%f,%f   %f,%f,%f | %f %f |%f, %f, %f\n", canvas.cylinder[i].norm.x, canvas.cylinder[i].norm.y, canvas.cylinder[i].norm.z, canvas.cylinder[i].coord.x, canvas.cylinder[i].coord.y, canvas.cylinder[i].coord.z, canvas.cylinder[i].size.height, canvas.cylinder[i].size.diameter, canvas.cylinder[i].color.r, canvas.cylinder[i].color.g, canvas.cylinder[i].color.b);
	}
}
