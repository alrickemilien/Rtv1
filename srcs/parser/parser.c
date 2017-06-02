#include "../include/rtv1.h"

/*
	*{							{
	*	0 --> "sphere"				0 --> set_sphere
	*	1 --> "cone"				1 --> set_cone
	*	2 --> "cylinder"			2 --> set_cylinder
	*	3 --> "plan"				3 --> set_plan
	*	...							...
	*}							{
*/

int		parser(t_env *env)
{
	char	*line;
	int		i;

	line = 0;
	while (get_next_line(env->fd, &line))
	{
		if (!check_indent(line, 0))
			return (parse_error(BAD_INDENT));
		recycle(&line, ft_strtrim(line));
		i = -1;
		while (++i < 6)
			if (!ft_strcmp(line, env->tab_str_object[i]))
				break ;
		if (ft_strcmp(line, ""))
		{
			if (i == 6)
				return (parse_error(INVALID_FORMAT_FILE));
			if (!env->set_object[i](env))
				return (0);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}
