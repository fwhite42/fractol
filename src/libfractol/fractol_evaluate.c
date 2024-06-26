/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_evaluate.c                                      4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 22:40:57 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/22 22:41:07 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libiterator.h"
#include<math.h>

double	fractol_evaluate(t_fractol *self, t_pt pt)
{
	double			iterations;

	self->iterator_fn(&(self->iterator_data), pt);
	iterations = iterator_run(&self->iterator_data);
	if (iterations == self->iterator_data.max_iteration)
		return (-1);
	else
		return (iterations);
}
