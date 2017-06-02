#include "libft.h"

int			ft_trim(int min, int max, int nb)
{
	if (min > nb)
		return (min);
	else if (max < nb)
		return (max);
	else
		return (nb);
}
