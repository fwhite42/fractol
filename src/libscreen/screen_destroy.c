#include"libscreen.h"
#include<stdlib.h>

void	screen_destroy(t_screen *self)
{
	free(self);
}
