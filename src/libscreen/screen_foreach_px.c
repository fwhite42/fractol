/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   screen_foreach_px.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 03:29:36 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 03:30:59 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libcplx.h"
#include"libscreen.h"
#include<stddef.h>
#include<stdio.h>

void	screen_foreach_px(t_screen *self, void (*fn)(), void *caller)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	while (x < self->size.x)
	{
		while (y < self->size.y)
		{
			if (caller == NULL)
				fn((t_pt){x, y});
			else
				fn(caller, (t_pt){x, y});
			y++;
		}
		y = 0;
		x++;
	}
}
