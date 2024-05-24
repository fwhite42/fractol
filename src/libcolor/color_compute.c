/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   color_compute.c                                         4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 15:10:25 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/22 15:11:53 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include<math.h>

int	color_compute(int type, int src, double color_id)
{
	int	color;

	color = 0;
	if (type == 0)
		color = pow(color_id, 3) + (2 * color_id * src) + 1;
	else if (type == 1)
		color = pow(color_id, 2);
	else
		color = floor(color_id) + 42 * 42;
	return (color);
}
