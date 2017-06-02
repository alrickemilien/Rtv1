#include "../include/rtv1.h"

void	mlx_put_pixel_to_image(t_env *env, int x, int y, t_color color)
{
	int		tmp;

	tmp = (x * (env->bpp / 8)) + (y * env->sizeline);
	env->data[tmp] = color.blue;
	env->data[tmp + 1] = color.green;
	env->data[tmp + 2] = color.red;
}
