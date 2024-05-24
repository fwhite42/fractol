/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_move_camera.c                                   4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 18:39:38 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/23 15:02:25 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"

int	fractol_move_camera(t_fractol *this, int keycode)
{
	if (keycode == KEY_ESC)
		fractol_exit(this);
	else if (keycode == KEY_MOVE_UP)
		this->camera.center.y += this->camera.size.y / KEYPRESS_DELTA;
	else if (keycode == KEY_MOVE_DOWN)
		this->camera.center.y -= this->camera.size.y / KEYPRESS_DELTA;
	else if (keycode == KEY_MOVE_LEFT)
		this->camera.center.x -= this->camera.size.x / KEYPRESS_DELTA;
	else if (keycode == KEY_MOVE_RIGHT)
		this->camera.center.x += this->camera.size.x / KEYPRESS_DELTA;
	else
		return (0);
	return (1);
}
