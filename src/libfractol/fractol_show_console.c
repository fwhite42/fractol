/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_show_console.c                                  4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 19:03:24 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 10:43:30 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libmlxconsole.h"
#include"libfractol.h"

void	fractol_show_console(t_fractol *self)
{
	t_mlxconsole	console;

	console = mlxconsole_default(self);
	mlxconsole_draw(&console);
	fractol_print_camera_on_screen(self, &console);
	fractol_print_iterator_on_screen(self, &console);
}
