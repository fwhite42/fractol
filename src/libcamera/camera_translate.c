#include"libfractol.h"

t_pt	camera_translate(t_camera *self, t_pt pt)
{
	pt.x += self->center.x;
	pt.y += self->center.y;
	return (pt);
}
