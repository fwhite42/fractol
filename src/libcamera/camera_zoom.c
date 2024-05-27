/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   camera_zoom.c                                           4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/21 08:01:27 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:23:49 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libcamera.h"
#include"libcplx.h"

void	camera_zoom(t_camera *self, t_screen *screen, t_pt spt, double zoom)
{
	t_pt	pt;
	t_pt	delta;

	pt = camera_rescale(self, screen, spt);
	pt = camera_transform(self, pt);
	pt = camera_translate(self, pt);
	self->size.x *= zoom;
	self->size.y *= zoom;
	delta = camera_rescale(self, screen, spt);
	delta = camera_transform(self, delta);
	self->center.x = pt.x - delta.x;
	self->center.y = pt.y - delta.y;
}
