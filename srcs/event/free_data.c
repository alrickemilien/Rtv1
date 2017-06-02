#include "../include/rtv1.h"

void	free_data(void *content, size_t size)
{
	(void)size;
	free(content);
}
