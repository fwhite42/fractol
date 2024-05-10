#include"libscreen.h"

void	screen_draw_px(t_screen *self, t_pt pos, int color)
{
	int	*buff;

	buff = (int *) self->imgbuff;
	buff[(int) (pos.y * self->size.x + pos.x)] = color;
}
