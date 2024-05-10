#include"libfractol.h"

t_pt	camera_transform(t_camera *self, t_pt pt)
{
	pt.x -= self->size.x / 2;
	pt.y -= self->size.y / 2;
	pt.y *= -1;
	return (pt);
}
