/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_init_mlx.c                                      4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 23:38:50 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 19:38:57 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */
#include"libfractol.h"
#include"libmlx.h"
#include"liberror.h"

void	fractol_init_mlx(t_fractol *self)
{
	self->mlx = mlx_init();
	if (!self->mlx)
		error_fatal("Cannot init mlx", -42);
}
