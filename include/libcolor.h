/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libcolor.h                                              4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/18 22:27:30 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/20 11:51:21 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCOLOR_H
# define LIBCOLOR_H

typedef struct s_rgbapt	t_rgbapt;

t_rgbapt	color_to_rgbapt(int color);
int			color_from_rgbapt(t_rgbapt color);
int			color_interpolate(int color1, int color2, double t);
int			*color_palette_create(int *a, int *b, int c);
int			*color_palette_destroy(int *palette);

struct s_rgbapt
{
	double	r;
	double	g;
	double	b;
	double	a;
};
#endif
