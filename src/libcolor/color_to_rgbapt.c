#include"libcolor.h"
#include<stdio.h>

t_rgbapt	color_to_rgbapt(int color)
{
	t_rgbapt	pt;
	pt.a = (double) ((color >> 24) & 0xff);
	pt.r = (double) ((color >> 16) & 0xff);
	pt.b = (double) ((color >> 8) & 0xff);
	pt.b = (double) ((color >> 0) & 0xff);
	return (pt);
}
