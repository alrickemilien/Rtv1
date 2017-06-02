#include "../include/rtv1.h"

static t_obj	set_default_sphere(t_env *env)
{
	t_obj		new_sphere;

	set_vec(&new_sphere.pos, 0, 0, 0);
	new_sphere.r = 1;
	set_vec(&new_sphere.rotation, 0, 0, 0);
	new_sphere.color = split_color(mlx_get_color_value(env->mlx, 0x0000FF00));
	new_sphere.etat = SPHERE;
	new_sphere.brillance = 10;
	new_sphere.specular = 1;
	new_sphere.diffuse = 1;
	new_sphere.func_obj = &sphere;
	return (new_sphere);
}

static int		check_reference(t_pars_object reference)
{
	if (reference.position > 1 || reference.color > 1 || reference.rayon > 1
		|| reference.brillance > 1 || reference.rotation > 1
		|| reference.specular > 1 || reference.diffuse > 1)
		return (parse_error(INVALID_OBJECT));
	if (reference.normal || reference.apex || reference.axis
		|| reference.angle || reference.from || reference.to || reference.size)
		return (parse_error(INVALID_OBJECT));
	return (1);
}

static int		check_sphere(t_env *env, t_obj *new,
		char *tmp, t_pars_object *index)
{
	int		n;
	int		i;

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

int				set_sphere(t_env *env)
{
	t_obj			new;
	char			*line;
	t_pars_object	reference;

	new = set_default_sphere(env);
	line = NULL;
	ft_bzero(&reference, sizeof(reference));
	while (get_next_line(env->fd, &line))
	{
		if (!ft_strcmp(line, ""))
			break ;
		if (!check_indent(line, 1))
			return (parse_error(BAD_INDENT));
		recycle(&line, ft_strtrim(line));
		if (!check_sphere(env, &new, line, &reference))
			return (0);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!check_reference(reference))
		return (0);
	ft_lstadd(&env->list, ft_lstnew(&new, (sizeof(t_obj))));
	return (1);
}
