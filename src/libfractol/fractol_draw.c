#include"libfractol.h"
#include"libcamera.h"
#include"libscreen.h"
#include"libcolor.h"
#include<math.h>
#include<stdio.h>
#include"libmlx.h"
#include"libft.h"
#include"libftprintf.h"
#include"liberror.h"

static void	_draw_pt(t_fractol *self, t_pt screen_pt)
{
	t_pt	pt;
	double	clr_id;
	int		clr;
	
	pt = camera_rescale(&(self->camera), self->screen, screen_pt);
	pt = camera_transform(&(self->camera), pt);
	pt = camera_translate(&(self->camera), pt);
	clr_id = fractol_evaluate(self, pt);
	if (clr_id == -1)
		return ;
	clr = color_compute_pretty(self->color_type, self->color_source, clr_id);
	screen_draw_px(self->screen, screen_pt, clr);
}

void	fractol_draw(t_fractol *self)
{
	ft_printf("Generating picture...");
	screen_foreach_px(self->screen, _draw_pt, self);
	ft_printf("done.\n");
	screen_refresh(self->screen, self->mlx);	
	if (self->draw_console_switch == 1)
		fractol_show_console(self);
}
