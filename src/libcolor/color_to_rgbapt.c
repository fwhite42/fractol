/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   color_to_rgbapt.c                                       4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 01:16:49 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:18:35 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libcolor.h"
#include<stdio.h>

t_rgbapt	color_to_rgbapt(int color)
{
	t_rgbapt	pt;

	pt.a = (double)((color >> 24) & 0xff);
	pt.r = (double)((color >> 16) & 0xff);
	pt.g = (double)((color >> 8) & 0xff);
	pt.b = (double)((color >> 0) & 0xff);
	return (pt);
}
