#include"libui.h"
#include"libmlx.h"

t_ui	*ui_create(int width, int height)
{
	t_ui	*self;
	
	self = ui_create_null();
	self->mlx = mlx_init();
	self->win = mlx_new_window(self->mlx, width, height, "Fractol");
	self->img = mlx_new_image(self->mlx, width, height);
	return (self);
}
