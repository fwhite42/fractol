/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_toggle_console.c                                4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 01:46:53 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 03:21:20 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */
#include"libfractol.h"

int	fractol_toggle_console(t_fractol *self, int cmd)
{
	if (cmd == KEY_SPACE_BAR)
	{
		self->draw_console_switch = !self->draw_console_switch;
		if (!self->draw_console_switch)
			screen_refresh_old(self->screen, self->mlx);
		else
			fractol_show_console(self);
		return (0);
	}
	return (0);
}
