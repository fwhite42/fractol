/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libcolor.h                                              4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/18 22:27:30 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/22 19:10:44 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCOLOR_H
# define LIBCOLOR_H

// An RGBA-pt is a 4-dimensional point (x0;x1;x2;x3) where:
// -	xi < 255 and
// -	xi > 0

typedef struct s_rgbapt	t_rgbapt;

// Colors are typically stored inside an int (4-bytes, one byte for each xi)
// Conversions are made with the two functions below. Of course an RGBA - point
// stores more information than a single int
t_rgbapt	color_to_rgbapt(int color);
int			color_from_rgbapt(t_rgbapt color);

// RGBA-points can be used to compute interpolations of colors
int			color_interpolate(int color1, int color2, double t);
int			color_compute(int type, int source, double param);
int			color_compute_pretty(int type, int source, double param);

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
