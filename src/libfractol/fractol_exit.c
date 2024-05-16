#include"libmlx.h"
#include"libfractol.h"
#include"libscreen.h"
#include<stdlib.h>

void	fractol_exit(t_fractol *self)
{
	screen_destroy(self->screen);
	free(self);
}
