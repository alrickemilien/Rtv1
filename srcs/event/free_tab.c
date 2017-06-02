#include "../include/rtv1.h"

void	free_tab(char ***tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}
