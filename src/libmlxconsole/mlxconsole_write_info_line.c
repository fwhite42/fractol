/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mlxconsole_write_info_line.c                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 13:44:14 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/22 13:44:38 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libmlxconsole.h"

void	mlxconsole_write_info_line(t_mlxconsole *self, char *key, char *valye)
{
	mlxconsole_write(self, key);
	self->cursor.x += 24 * 8;
	mlxconsole_write(self, valye);
	self->cursor.x -= 24 * 8;
	self->cursor.y += 16;
}
