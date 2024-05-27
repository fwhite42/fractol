/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   screen_destroy.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 03:32:05 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 03:32:12 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libscreen.h"
#include"libmlx.h"

void	screen_destroy(t_screen *self, void *mlx)
{
	mlx_destroy_window(mlx, self->win);
	mlx_destroy_image(mlx, self->old_img);
}
