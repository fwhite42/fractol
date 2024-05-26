/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_set_hooks.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 18:11:31 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 14:27:57 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libmlx.h"

void	fractol_set_hooks(t_fractol *self)
{
	mlx_mouse_hook(self->screen->win, fractol_onzoom, self);
	mlx_key_hook(self->screen->win, fractol_onkeypress, self);
	mlx_loop_hook(self->mlx, fractol_onloop, self);
}
