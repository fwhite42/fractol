/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libcplx.h                                               4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/21 08:20:37 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:13:50 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCPLX_H
# define LIBCPLX_H

typedef struct s_pt	t_pt;

struct s_pt
{
	double	x;
	double	y;
};

double	cplx_abs(t_pt z);
t_pt	cplx_square(t_pt z);

// Returns a point, somewhat easier than casting a literal struct
t_pt	cplx_pt(double re, double im);
t_pt	cplx_zero(void);

// Complex Conjugate
t_pt	cplx_conj(t_pt z);
// Complex Exp
t_pt	cplx_pow(t_pt z1, t_pt z2);
// Complex sum
t_pt	cplx_sum(t_pt z1, t_pt z2);
// Complex multiplication
t_pt	cplx_mul(t_pt z1, t_pt z2);
#endif
