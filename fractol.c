#include"libfractol.h"

int	main(void)
{
	t_fractol	*self;

	self = fractol_create_default();
	fractol_draw(self);
	fractol_start(self);
	return (0);
}
