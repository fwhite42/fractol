#include"libfractol.h"
#include"stdlib.h"

void	fractol_destroy(t_fractol *self)
{
	ui_destroy(self->ui);
	free(self);
}
