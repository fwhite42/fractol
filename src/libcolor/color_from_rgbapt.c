/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   color_from_rgbapt.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 01:20:30 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:28:04 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libcolor.h"
#include<stdio.h>

int	color_from_rgbapt(t_rgbapt pt)
{
	int	color;

	color = 0;
	color += (unsigned int)(pt.a * (1 << 24));
	color += (unsigned int)(pt.r * (1 << 16));
	color += (unsigned int)(pt.g * (1 << 8));
	color += (unsigned int)(pt.b * (1 << 0));
	return (color);
}
