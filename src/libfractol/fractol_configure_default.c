/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_configure_default.c                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 13:49:58 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/23 16:35:34 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libmlx.h"
#include"libiterator.h"
#include"liberror.h"
#include<stddef.h>

void	fractol_configure_default(t_fractol *self)
{
	t_pt		camera_size;
	t_pt		screen_size;
	t_pt		camera_center;

	camera_size = (t_pt) {DFLT_CAMERA_WIDTH, DFLT_CAMERA_HEIGHT};
	camera_center = (t_pt) {DFLT_CAMERA_CENTER_X, DFLT_CAMERA_CENTER_Y};
	screen_size = (t_pt) {DFLT_SCREEN_WIDTH, DFLT_SCREEN_HEIGHT};
	self->camera.size = camera_size;
	self->camera.center = camera_center;
	self->mlx = mlx_init();
	if (self->mlx == NULL)
		error_fatal("Cannot init mlx.", -42);
	self->screen->size = screen_size;
	screen_init(self->screen, self->mlx);
	iterator_init(&(self->iterator_data)); 
	self->fractal_name = "mandelbrot";
	self->iterator_fn = DFLT_ITERATOR_FN;
	self->requires_image_update = 1;
	self->draw_console_switch = 1; 
	self->color_type = DFLT_COLOR_TYPE;
	self->color_source = DFLT_COLOR_SOURCE;
}
