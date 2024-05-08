#include"libfractol.h"

t_pt	fractol_translate(t_fractol *ctx, t_pt pt)
{
	pt.x += ctx->camera_center.x;
	pt.y += ctx->camera_center.y;
	return (pt);
}
