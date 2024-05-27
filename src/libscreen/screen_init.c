/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   screen_init.c                                           4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/20 15:39:27 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 03:29:58 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libscreen.h"
#include"libmlx.h"

void	screen_init(t_screen *self, void *mlx)
{
	self->win = mlx_new_window(mlx, self->size.x, self->size.y, self->title);
	self->img = mlx_new_image(mlx, self->size.x, self->size.y);
}
