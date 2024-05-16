#include"libmlx.h"
#include"libscreen.h"
#include<stdio.h>
void	screen_refresh(t_screen *self, void *caller)
{
	mlx_clear_window(caller, self->win);
	mlx_put_image_to_window(caller, self->win, self->img, 0, 0);
	mlx_destroy_image(caller, self->img);
	self->img = mlx_new_image(caller, self->size.x, self->size.y);
}
