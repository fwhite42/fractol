#include"libfractol.h"

t_pt	camera_rescale(t_camera *self, t_screen *screen, t_pt pt)
{
	t_pt ratio;

	ratio.x = self->size.x / screen->size.x;
	ratio.y = self->size.y / screen->size.y;
	pt.x *= ratio.x;
	pt.y *= ratio.y;
	return (pt);
}
