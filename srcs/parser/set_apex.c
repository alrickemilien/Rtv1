#include "../include/rtv1.h"

int		set_apex(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->apex++;
	if (!fill_data_vec(tmp, &new->apex))
		return (0);
	return (1);
}
