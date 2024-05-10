#include"libmlx.h"
#include"libfractol.h"
#include"libscreen.h"

void	fractol_exit(t_fractol *self)
{
	screen_destroy(self->screen);
	mlx_loop_end(self->mlx);	
	free(self);
}
