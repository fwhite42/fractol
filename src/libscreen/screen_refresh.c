#include"libmlx.h"
#include"libscreen.h"

void	screen_refresh(t_screen *self, void *caller)
{
	mlx_clear_window(caller, self->win);
	mlx_put_image_to_window(caller, self->win, self->img, 0, 0);
}
