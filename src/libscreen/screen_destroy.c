#include"libscreen.h"
#include"libmlx.h"
#include<stdlib.h>

void	screen_destroy(t_screen *self, void *mlx)
{
	mlx_destroy_window(mlx, self->win);
	mlx_destroy_image(mlx, self->old_img);
}
