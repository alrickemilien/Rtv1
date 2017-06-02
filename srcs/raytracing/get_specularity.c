#include "rtv1.h"

static double	rec_spec(int max, double spec, double angle)
{
	int			i;

	i = -1;
	while (++i < max)
		spec *= angle;
	return (spec);
}

double			get_specularity(t_vector intersection, t_vector n,
								t_vector light_dir, t_obj *obj)
{
	t_vector	r;
	double		tmp;
	double		angle;
	t_vector	v;

	normalize_vec(&intersection);
	if (obj->etat == PLAN)
		return (0);
	v = light_dir;
	tmp = dot_product(light_dir, n);
	normalize_vec(&light_dir);
	r = vec_diff(v, n_vec(n, (tmp + tmp)));
	normalize_vec(&r);
	if ((angle = dot_product(r, intersection)) < 0)
		return (0);
	return (rec_spec(obj->brillance, obj->specular, angle));
}
