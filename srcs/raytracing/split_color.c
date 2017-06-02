#include "../include/rtv1.h"

t_color	split_color(unsigned long color)
{
	t_color	color_split;

	color_split.red = (color & 0xFF0000) >> 16;
	color_split.green = (color & 0xFF00) >> 8;
	color_split.blue = (color & 0xFF);
	return (color_split);
}
