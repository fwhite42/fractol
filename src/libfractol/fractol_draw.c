#include"libfractol.h"
#include"libcamera.h"
#include"libscreen.h"
#include<math.h>
#include<stdio.h>



static int	get_color(double x)
{
	int	dflt;

	dflt = 0x000099cc;
	return (x * x  * x + 2 * x * dflt + 1);
}

static void	fractol_draw_pt(t_fractol *self, t_pt screen_pt)
{
	t_pt	pt;
	double	color;
	
	pt = camera_rescale(&(self->camera), self->screen, screen_pt);
	pt = camera_transform(&(self->camera), pt);
	pt = camera_translate(&(self->camera), pt);
	color = fractol_evaluate(self, pt);
	if (color == -1)
			return ;
	color = get_color(color);
	pt.x -= self->camera.center.x;
	pt.y -= self->camera.center.y;
	screen_draw_px(self->screen, screen_pt, (int) color);
}

void	fractol_draw(t_fractol *self)
{
	screen_foreach_px(self->screen, fractol_draw_pt, self);
	screen_refresh(self->screen, self->mlx);	
}
