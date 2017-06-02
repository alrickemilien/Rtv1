#include "../include/rtv1.h"

int		set_diffuse(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->diffuse++;
	if (!fill_data(tmp, &new->diffuse))
		return (0);
	if (new->diffuse < 0 || new->diffuse > 1)
		return (parse_error(BAD_COEFF));
	return (1);
}
