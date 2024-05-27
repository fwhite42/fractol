/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_onkeypress.c                                    4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/23 14:41:46 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 11:09:11 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libftprintf.h"

int	fractol_onkeypress(int cmd, void *self)
{
	int			success;
	t_fractol	*this;

	this = self;
	success = 0;
	if (fractol_move_camera(self, cmd))
		success = 1;
	else if (fractol_move_iterator_constant(self, cmd))
		success = 1;
	else if (fractol_toggle_antialias(self, cmd))
		success = 1;
	else if (fractol_toggle_console(self, cmd))
		success = 1;
	else if (fractol_change_max_iteration(self, cmd))
		success = 1;
	else if (fractol_change_iterator_power(self, cmd))
		success = 1;	
	if (success)
		this->requires_image_update = 1;
	else
		ft_printf("key: %#x\n", cmd);
	return (success);
}
