/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_onloop.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 18:06:23 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 14:32:01 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libftprintf.h"

int	fractol_onloop(void *self)
{
	t_fractol	*this;

	this = self;
	this->mlx_loop_counter++;
	if (!this->requires_image_update)
		return (1);
	if (this->mlx_loop_counter > FRACTOL_REFRESH_RATE)
	{
		fractol_draw(self);
		this->mlx_loop_counter = 0;
		this->requires_image_update = 0;
		return (0);
	}
	return (1);
}
