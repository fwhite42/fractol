/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mlxconsole_default.c                                    4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 13:43:02 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 18:32:08 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libmlxconsole.h"

t_mlxconsole	mlxconsole_default(t_fractol *self)
{
	t_mlxconsole	console;

	console.mlx = self->mlx;
	console.win = self->screen->win;
	console.size.x = self->screen->size.x / 4;	
	console.size.y = self->screen->size.y / 4;	
	if (console.size.y < 256)
		console.size.y = 256;
	if (console.size.x < 40 * 8)
		console.size.x = 40 * 8;
	console.offset.x = self->screen->size.x / 128;
	console.offset.y = self->screen->size.y / 128;
	console.bg_color = 0x9b9b9b00;
	console.txt_color = 0x00ffffff;
	console.cursor.x = console.offset.x * 2;
	console.cursor.y = 8 + console.offset.y * 2;
	return (console);
}
