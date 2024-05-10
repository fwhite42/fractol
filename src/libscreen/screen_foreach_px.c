#include"libcplx.h"
#include"libscreen.h"
#include<stddef.h>
#include<stdio.h>

void	screen_foreach_px(t_screen *self, void (*fn)(), void *caller)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	while (x < self->size.x)
	{
		while (y < self->size.y)
		{
			printf("Iter (%f, %f)\n", x, y);
			if (caller == NULL)
				fn((t_pt) {x, y});
			else 
				fn(caller, (t_pt) {x, y});
			y++;
		}
		y = 0;
		x++;
	}
}
