#include "../include/rtv1.h"

static t_obj		set_default_cylinder(t_env *env)
{
	t_obj			new;

	set_vec(&new.axis, 0, 0, 1);
	set_vec(&new.apex, 0, 0, 1);
	set_vec(&new.rotation, 0, 0, 0);
	new.r = 1;
	new.size = 20000;
	new.color = split_color(mlx_get_color_value(env->mlx, 0x00FF3421));
	new.brillance = 10;
	new.specular = 1;
	new.diffuse = 1;
	new.etat = CYLINDRE;
	new.func_obj = &cylindre;
	return (new);
}

static int			check_cylinder(t_env *env, t_obj *new,
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
	if (reference.apex > 1 || reference.axis > 1 || reference.color > 1
		|| reference.rayon > 1 || reference.brillance > 1
		|| reference.rotation > 1 || reference.size > 1
		|| reference.specular > 1 || reference.diffuse > 1)
		return (parse_error(INVALID_OBJECT));
	if (reference.normal || reference.position
		|| reference.angle || reference.from || reference.to)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

int					set_cylinder(t_env *env)
{
	t_obj			new_cylinder;
	char			*line;
	t_pars_object	reference;

	new_cylinder = set_default_cylinder(env);
	ft_bzero(&reference, sizeof(reference));
	line = NULL;
	while (get_next_line(env->fd, &line))
	{
		if (!ft_strcmp(line, ""))
			break ;
		if (!check_indent(line, 1))
			return (parse_error(BAD_INDENT));
		recycle(&line, ft_strtrim(line));
		if (!check_cylinder(env, &new_cylinder, line, &reference))
			return (0);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference))
		return (parse_error(INVALID_OBJECT));
	rotate_object(&new_cylinder, &new_cylinder.axis);
	ft_lstadd(&env->list, ft_lstnew(&new_cylinder, (sizeof(t_obj))));
	return (1);
}
