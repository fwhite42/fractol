#include"libfractol.h"

t_pt	fractol_transform(t_fractol *ctx, t_pt pt)
{
	pt.x -= ctx->camera_size.x / 2;
	pt.y -= ctx->camera_size.y / 2;
	pt.y *= -1;
	return (pt);
}
