/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mlxconsole_draw.c                                       4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 13:50:21 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/22 13:50:54 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libmlxconsole.h"

void	mlxconsole_draw(t_mlxconsole *self)
{
	int		i;
	int		j;
	int		pos_x;
	int		pos_y;
	
	i = 0;
	while (i < self->size.x)
	{
		j = 0;
		while (j < self->size.y)
		{
			pos_x = i + self->offset.x;
			pos_y = j + self->offset.y;
			mlx_pixel_put(self->mlx, self->win, pos_x, pos_y, self->bg_color);
			j++;
		}
		i++;
	}
}
