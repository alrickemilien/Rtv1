#include "../include/rtv1.h"
#include <stdio.h>

int		plan(t_obj p, t_ray *ray, double *t)
{
	double		alpha;

	alpha = dot_product(ray->org, p.n);
	alpha = dot_product(vec_diff(p.pos, ray->org), p.n) /
			dot_product(ray->dir, p.n);
	if (alpha >= 0)
	{
		*t = alpha;
		return (1);
	}
	return (0);
}
