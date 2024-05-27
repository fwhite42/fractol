/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   screen_refresh_old.c                                    4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 03:28:03 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 03:28:18 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libmlx.h"
#include"libscreen.h"

void	screen_refresh_old(t_screen *self, void *caller)
{
	mlx_clear_window(caller, self->win);
	mlx_put_image_to_window(caller, self->win, self->old_img, 0, 0);
}
