#include "../include/rtv1.h"

void	recycle(char **old_ptr, char *new_ptr)
{
	char	*tmp;

	tmp = *old_ptr;
	*old_ptr = new_ptr;
	if (tmp)
		free(tmp);
}
