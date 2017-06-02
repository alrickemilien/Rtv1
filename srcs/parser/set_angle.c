#include "../include/rtv1.h"

int		set_angle(t_env *env, char *tmp, t_obj *new, t_pars_object *index)
{
	(void)env;
	index->angle++;
	if (!fill_data(tmp, &new->angle))
		return (0);
	if (new->angle > 180 || new->angle < -180)
		return (parse_error(INVALID_ANGLE));
	new->angle = (new->angle * M_PI) / 180;
	if (new->etat == CONE)
		new->angle = tan(new->angle / 2) * tan(new->angle / 2);
	return (1);
}
