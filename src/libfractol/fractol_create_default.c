#include"libfractol.h"
#include"libmlx.h"
#include"libiterator.h"

t_fractol	*fractol_create_default(void)
{
	t_camera	camera;
	t_fractol	*self;

	camera.size = (t_pt) {4, 4};
	camera.center = (t_pt) {0, 0};
	self = fractol_create_null();
	self->mlx = mlx_init();
	self->screen = screen_create((t_pt) {1800, 1200}, "Fract'ol", self->mlx);
	self->camera = camera;
	self->iterator = iterator_mandelbrot;
	iterator_init(&(self->iterator_data));
	self->update = 1;
	return (self);
}
