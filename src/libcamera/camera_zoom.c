#include"libcamera.h"
#include"libcplx.h"

void	camera_zoom(t_camera *self, t_screen *screen, t_pt spt, double zoom)
{
	t_pt pt;
	t_pt delta;

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
