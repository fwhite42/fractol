/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mlxconsole_write.c                                      4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 13:40:38 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 17:24:55 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libmlx.h"
#include"libmlxconsole.h"

void	mlxconsole_write(t_mlxconsole *self, char *str)
{
	t_pt	pos;

	pos = self->cursor;
	mlx_string_put(self->mlx, self->win, pos.x, pos.y, self->txt_color, str);
}
