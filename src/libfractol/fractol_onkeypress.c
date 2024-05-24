/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_onkeypress.c                                    4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/23 14:41:46 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/23 16:45:03 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"

int	fractol_onkeypress(int cmd, void *self)
{
	int	success;

	success = 0;
	if (fractol_move_camera(self, cmd))
		success = 1;
	else if (fractol_move_iterator_constant(self, cmd))
		success = 1;
	if (success)
	{
		ft_printf("Received user command");
		((t_fractol *)self)->requires_image_update = 1;
	}
	return (success);
}
