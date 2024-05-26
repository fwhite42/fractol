/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_toggle_antialias.c                              4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 18:56:37 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 14:26:19 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"

int	fractol_toggle_antialias(t_fractol *self, int cmd)
{
	if (cmd == KEY_ANTI_ALIAS)
		self->iterator_data.anti_alias = !self->iterator_data.anti_alias;
	else
		return (0);
	return (1);
}
