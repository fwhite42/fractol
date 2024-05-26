#include"libmlx.h"
#include"libscreen.h"
#include<stdio.h>
void	screen_refresh_old(t_screen *self, void *caller)
{
	mlx_clear_window(caller, self->win);
	mlx_put_image_to_window(caller, self->win, self->old_img, 0, 0);
}
