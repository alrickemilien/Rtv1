#include "../include/rtv1.h"

static t_obj		set_default_plan(t_env *env)
{
	t_obj			new_plan;

	set_vec(&new_plan.n, 0, 1, 0);
	set_vec(&new_plan.pos, 0, 0, 0);
	set_vec(&new_plan.rotation, 0, 0, 0);
	new_plan.color = split_color(mlx_get_color_value(env->mlx, 0x00FFFFFF));
	new_plan.brillance = 10;
	new_plan.diffuse = 1;
	new_plan.specular = 1;
	new_plan.etat = PLAN;
	new_plan.func_obj = &plan;
	return (new_plan);
}

static int			check_plan(t_env *env, t_obj *new,
		char *tmp, t_pars_object *index)
{
	int				n;
	int				i;

	i = 0;
	while (i < NBR_DESCRIPTION)
	{
		if (!ft_strncmp(env->tab_str_description[i],
				tmp, (n = ft_strlen(env->tab_str_description[i]))))
			break ;
		i++;
	}
	if (i == NBR_DESCRIPTION)
		return (parse_error(INVALID_DESCRIPTION));
	if (!env->check_description[i](env, tmp + n, new, index))
		return (0);
	return (1);
}

static int			check_reference(t_pars_object reference)
{
	if (reference.normal > 1 || reference.position > 1 || reference.color > 1
		|| reference.brillance > 1 || reference.rotation > 1
		|| reference.specular > 1 || reference.diffuse > 1)
		return (parse_error(INVALID_OBJECT));
	if (reference.axis || reference.apex || reference.rayon
		|| reference.angle || reference.to || reference.from || reference.size)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

int					set_plan(t_env *env)
{
	t_obj			new_plan;
	char			*line;
	t_pars_object	reference;

	new_plan = set_default_plan(env);
	ft_bzero(&reference, sizeof(reference));
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		if (!ft_strcmp(line, ""))
			break ;
		if (!check_indent(line, 1))
			return (parse_error(BAD_INDENT));
		recycle(&line, ft_strtrim(line));
		if (!check_plan(env, &new_plan, line, &reference))
			return (0);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference))
		return (0);
	normalize_vec(&new_plan.n);
	rotate_object(&new_plan, &new_plan.n);
	ft_lstadd(&env->list, ft_lstnew(&new_plan, (sizeof(t_obj))));
	return (1);
}
