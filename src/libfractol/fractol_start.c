/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_start.c                                         4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 18:54:11 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 19:52:11 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libmlx.h"

void	fractol_start(t_fractol *self)
{
	self->requires_image_update = 1;
	mlx_loop(self->mlx);
}
