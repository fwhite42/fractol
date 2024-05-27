/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   iterator_mandelbrot.c                                   4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 01:27:05 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:27:56 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libiterator.h"

void	iterator_mandelbrot(t_iterator *self, t_pt pt)
{
	self->c = pt;
}
