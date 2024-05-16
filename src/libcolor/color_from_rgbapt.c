#include"libpalette.h"

int	color_from_rgbapt(t_rgbapt pt)
{
	int	color;

	color += (pt.a << 24);
	color += (pt.b << 16);
	color += (pt.g << 8);
	color += (pt.r << 0);
	return (color);
}
