/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   screen_refresh.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 03:28:28 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 03:28:35 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libmlx.h"
#include"libscreen.h"

void	screen_refresh(t_screen *self, void *caller)
{
	mlx_clear_window(caller, self->win);
	mlx_put_image_to_window(caller, self->win, self->img, 0, 0);
	if (self->old_img != NULL)
		mlx_destroy_image(caller, self->old_img);
	self->old_img = self->img;
	self->img = mlx_new_image(caller, self->size.x, self->size.y);
}
