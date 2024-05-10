#include"libfractol.h"
#include"libcamera.h"
#include"libscreen.h"
#include<stdio.h>

static int	get_color(int x)
{
	int	dflt;

	dflt = 0x000099cc;
	return (x * ((x - 2) / 2) * 100 + dflt * x + dflt);
}

static void	fractol_draw_pt(t_fractol *self, t_pt screen_pt)
{
	t_pt	pt;
	int	color;
	
	pt = camera_rescale(&(self->camera), self->screen, screen_pt);
	pt = camera_transform(&(self->camera), pt);
	pt = camera_translate(&(self->camera), pt);
	printf("Drawing (%f, %f)\n",  pt.x, pt.y);
	color = get_color(fractol_evaluate(self, pt));
	printf("Color = %#x\n",  color);
	screen_draw_px(self->screen, screen_pt, color);
}

void	fractol_draw(t_fractol *self)
{
	screen_foreach_px(self->screen, fractol_draw_pt, self);
	screen_refresh(self->screen, self->mlx);	
}
