#include"libfractol.h"

t_pt	fractol_rescale(t_fractol *ctx, t_pt pt)
{
	t_pt ratio;

	ratio.x = ctx->camera_size.x / ctx->screen_size.x;
	ratio.y = ctx->camera_size.y / ctx->screen_size.y;
	pt.x *= ratio.x;
	pt.y *= ratio.y;
	return (pt);
}
