/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_create.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 12:44:15 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/21 14:17:59 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libmlx.h"
#include"libfractol.h"
#include"libmlx.h"
#include"libiterator.h"

t_fractol	*fractol_create(t_pt screen_size)
{
	t_camera	camera;
	t_fractol	*self;

	camera.size = (t_pt) {4, 4};
	camera.center = (t_pt) {0, 0};
	self = fractol_create_null();
	self->mlx = mlx_init();
	self->screen = screen_create(screen_size, "Fract'ol", self->mlx);
	self->camera = camera;
	self->iterator = iterator_mandelbrot;
	iterator_init(&(self->iterator_data));
	self->update = 1;
	self->draw_console = 1; 
	self->color_type = 0;
	self->color_source = 0x000099cc;
	return (self);
}
