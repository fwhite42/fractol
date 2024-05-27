/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_change_max_iteration.c                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 18:46:43 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 02:18:50 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"

int	fractol_change_max_iteration(t_fractol *self, int cmd)
{
	if (cmd == KEY_MORE_ITER)
		self->iterator_data.max_iteration *= 2;
	else if (cmd == KEY_LESS_ITER)
		self->iterator_data.max_iteration /= 2;
	else
		return (0);
	if (self->iterator_data.max_iteration < 1)
		self->iterator_data.max_iteration = 1;
	if (self->iterator_data.max_iteration > 1 << 16)
		self->iterator_data.max_iteration = 1 << 16;
	return (1);
}
