#include"libui.h"
#include"libmlx.h"
#include<stdlib.h>

void	ui_destroy(t_ui *self)
{
	mlx_destroy_image(self->mlx, self->img);
	mlx_destroy_window(self->mlx, self->win);
	mlx_loop_end(self->mlx);
	free(self);
}
