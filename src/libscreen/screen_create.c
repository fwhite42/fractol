#include"libscreen.h"
#include"libmlx.h"

t_screen	*screen_create(t_pt size, char *title, void *caller)
{
	int		info[3];
	char		*buff;
	t_screen	*self;

	self = screen_create_null();
	self->size = size;
	self->title = title;
	self->win = mlx_new_window(caller, size.x, size.y, title);
	self->img = mlx_new_image(caller, size.x, size.y);
	buff =  mlx_get_data_addr(self->img, info, info + 1, info + 2);
	self->imgbuff = (int *)buff;
	return (self);
}

