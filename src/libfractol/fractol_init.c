/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_init.c                                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 23:38:50 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/23 11:12:01 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */
#include"libfractol.h"
#include"libscreen.h"
#include"libmlx.h"

void	fractol_init(t_fractol *self)
{
	self->screen = screen_create_null();
	self->mlx = mlx_init();
}
