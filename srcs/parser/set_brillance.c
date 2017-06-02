#include "../include/rtv1.h"

int		set_brillance(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->brillance++;
	if (!fill_int_data(tmp, &new->brillance))
		return (0);
	if (new->brillance < 0)
		return (0);
	return (1);
}
