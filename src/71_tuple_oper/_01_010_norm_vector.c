#include "minirt.h"

t_tuple	ft_norm_vector(t_tuple tuple)
{
	double	magn;

	ft_assert(tuple.w == 0, "Not a Vector");
	magn = ft_magn_tuple(tuple);
	return ((t_tuple){tuple.x / magn,
		tuple.y / magn,
		tuple.z / magn,
		0});
}

/*t_tuple	ft_norm_vector(t_tuple tuple)*/
/*{*/
/*	double	magn;*/
/**/
/*	ft_assert(tuple.w == 0, "Not a Vector");*/
/*	magn = ft_magn_tuple(tuple);*/
/*	return ((t_tuple){tuple.x / magn,*/
/*		tuple.y / magn,*/
/*		tuple.z / magn,*/
/*		tuple.w / magn});*/
/*}*/
