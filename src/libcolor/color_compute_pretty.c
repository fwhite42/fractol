/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   color_compute_pretty.c                                  4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 13:49:51 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:22:31 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libcolor.h"
#include<math.h>

int	color_compute_pretty(int type, int source, double id)
{
	double	t;
	int		color1;
	int		color2;

	if (id == -1)
		return (id);
	color1 = color_compute(type, source, floor(id));
	color2 = color_compute(type, source, floor(id) + 1);
	t = id - floor(id);
	if (color1 != color2)
		return (color_interpolate(color1, color2, t));
	else
		return (color1);
}
