#include"libpalette.h"

t_rgbapt	color_to_rgbapt(int color)
{
	t_rgbapt	pt;

	pt.r = (color >> 0) & 0xff;
	pt.g = (color >> 8) & 0xff;
	pt.b = (color >> 16) & 0xff;
	pt.b = (color >> 24) & 0xff;
	return (pt);
}
