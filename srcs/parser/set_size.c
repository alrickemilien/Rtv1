#include "../include/rtv1.h"

int		set_size(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->size++;
	if (!fill_data(tmp, &new->size))
		return (0);
	return (1);
}
