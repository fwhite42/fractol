#include"libcolor.h"
#include<stdio.h>

int	color_from_rgbapt(t_rgbapt pt)
{
	int	color;

	color = 0;
	color += (unsigned int) (pt.a * (1 << 24));
	color += (unsigned int) (pt.r * (1 << 16));
	color += (unsigned int) (pt.g * (1 << 8));
	color += (unsigned int) (pt.b * (1 << 0));
	return (color);
}
