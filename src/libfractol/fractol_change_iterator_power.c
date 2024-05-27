/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_change_iterator_power.c                         4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/26 16:28:48 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 11:09:10 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"

int	fractol_change_iterator_power(t_fractol *self, int cmd)
{
	if (cmd == KEY_INCREASE_ITER_POW)
		self->iterator_data.n += 1;
	else if (cmd == KEY_DECREASE_ITER_POW)
		self->iterator_data.n -= 1;
	else
		return (0);
	return (1);
}
