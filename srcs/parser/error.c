#include "../include/rtv1.h"

int		error(t_env *env, char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	end_program(env);
	return (0);
}

int		parse_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (0);
}

int		error_file(char *file)
{
	ft_putstr_fd("Error : ", 2);
	perror(file);
	ft_putendl_fd(USAGE, 2);
	exit(-1);
	return (0);
}

int		merror(void)
{
	perror("");
	exit(0);
	return (0);
}
