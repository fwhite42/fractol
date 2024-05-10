#include"libfractol.h"
#include"stdlib.h"

void	fractol_destroy(t_fractol *self)
{
	free(self);
}
