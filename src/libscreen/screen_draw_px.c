/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   screen_draw_px.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 17:55:22 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 03:33:59 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libscreen.h"
#include"libmlx.h"

void	screen_draw_px(t_screen *self, t_pt pos, int color)
{
	int	*img_buffer;
	int	tmp[3];

	img_buffer = (int *)mlx_get_data_addr(self->img, tmp, tmp + 1, tmp + 2);
	img_buffer[(int)(pos.y * self->size.x + pos.x)] = color;
}
