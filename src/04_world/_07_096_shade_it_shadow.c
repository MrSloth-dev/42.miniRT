#include "minirt.h"

t_color	ft_shade_hit_shadow(t_canvas *canvas, t_comp comp)
{
	comp.in_shadow = ft_is_shadowed(canvas, comp.over_point);
	return (ft_lighting_shadow(canvas, comp));
}
