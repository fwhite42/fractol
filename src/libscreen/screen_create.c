/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   screen_create.c                                         4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/20 15:39:27 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/20 15:51:54 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libscreen.h"
#include"libmlx.h"

void	_draw_info_screen_background(t_screen *self, t_pt pos)
{
	int	*buff;

	buff = self->info_screen_buff;
	buff[(int) (pos.y * self->size.x + pos.x)] = 0x9b9b9b00;
}

t_screen	*screen_create(t_pt size, char *title, void *caller)
{
	int			info[3];
	char		*buff;
	t_screen	*self;

	self = screen_create_null();
	self->size = size;
	self->title = title;
	self->win = mlx_new_window(caller, size.x, size.y, title);
	self->info_screen = mlx_new_image(caller, size.x / 4, size.y / 4);
	self->img = mlx_new_image(caller, size.x, size.y);
	buff =  mlx_get_data_addr(self->img, info, info + 1, info + 2);
	self->imgbuff = (int *)buff;
	buff =  mlx_get_data_addr(self->info_screen, info, info + 1, info + 2);
	self->info_screen_buff = (int *)buff;
	return (self);
}

