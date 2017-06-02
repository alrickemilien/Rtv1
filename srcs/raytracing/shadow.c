#include "../include/rtv1.h"

double			shadow(t_env *env, t_ray ray, double norme)
{
	double		t;
	t_list		*tmp_list;
	int			ret;

	t = 0;
	ray.t = norme;
	normalize_vec(&ray.dir);
	tmp_list = env->list;
	while (tmp_list)
	{
		if ((ret = ((t_obj*)(tmp_list->content))->func_obj(
					*((t_obj*)(tmp_list->content)), &ray, &t)))
		{
			if (t <= norme && t >= 0)
				return (0);
		}
		tmp_list = tmp_list->next;
	}
	return (1);
}
