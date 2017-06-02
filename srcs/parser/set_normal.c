#include "../include/rtv1.h"

int		set_normal(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->normal++;
	if (!fill_data_vec(tmp, &new->n))
		return (0);
	if (!new->n.z && !new->n.y && !new->n.x)
		return (parse_error(INVALID_NORMAL));
	return (1);
}
