#include "rtv1.h"

double	get_diffuse(t_vector n, t_vector light_dir)
{
	double	diffuse;

	normalize_vec(&light_dir);
	diffuse = dot_product(light_dir, n);
	if (diffuse < 0)
		return (0);
	return (diffuse);
}
