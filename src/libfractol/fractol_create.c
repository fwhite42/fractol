#include"libfractol.h"

t_fractol	*fractol_create(int width, int height)
{
	t_fractol	*self;

	self = fractol_create_null();
	self->camera_center = cplx_zero();
	self->camera_size.x = 4;
	self->camera_size.y = 4;
	self->screen_size.x = width;
	self->screen_size.y = height; 
	self->tick = 0;
	self->ui = ui_create(width, height);
	return (self);
}
