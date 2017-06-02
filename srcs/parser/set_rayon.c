#include "../include/rtv1.h"

int		set_rayon(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->rayon++;
	if (!fill_data(tmp, &new->r))
		return (0);
	if (new->r <= 0)
		return (0);
	return (1);
}
