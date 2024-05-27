/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   color_interpolate.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/19 01:32:37 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:28:06 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */
#include"libcolor.h"
#include"liberror.h"

int	color_interpolate(int color1, int color2, double t)
{
	int			color;
	t_rgbapt	color_pt;
	t_rgbapt	p1;
	t_rgbapt	p2;

	if (t < 0 && t > -1)
		t = 1 + t;
	if (t < -1 || t > 1)
		error_fatal("Wront value of t while interpolating colors", -42);
	p1 = color_to_rgbapt(color1);
	p2 = color_to_rgbapt(color2);
	color_pt.r = t * p1.r + (1 - t) * p2.r;
	color_pt.g = t * p1.g + (1 - t) * p2.g;
	color_pt.b = t * p1.b + (1 - t) * p2.b;
	color_pt.a = t * p1.a + (1 - t) * p2.a;
	color = color_from_rgbapt(color_pt);
	return (color);
}
