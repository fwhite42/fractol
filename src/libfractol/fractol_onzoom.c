/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_onzoom.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 18:01:53 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/23 14:34:40 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libcplx.h"

int	fractol_onzoom(int cmd, int x, int y, void *this)
{
	t_fractol	*self;
	t_camera	*camera;
	t_screen	*screen;
	t_pt		pt;

	if (cmd != MOUSE_ZOOM_IN && cmd != MOUSE_ZOOM_OUT)
		return (1);
	self = this;
	camera = &(self->camera);
	screen = self->screen;
	pt = (t_pt) {(double) x, (double) y};
	pt = camera_rescale(camera, screen, pt);
	pt = camera_transform(camera, pt);
	pt = camera_translate(camera, pt);
	if (cmd == MOUSE_ZOOM_IN)
		camera_zoom(camera, screen, (t_pt) {x, y}, ZOOM_IN_FACTOR);
	else if (cmd == MOUSE_ZOOM_OUT)
		camera_zoom(camera, screen,  (t_pt) {x, y}, ZOOM_OUT_FACTOR);
	self->requires_image_update = 1;
	return (0);
}
