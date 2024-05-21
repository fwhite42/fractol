#include"libmlx.h"
#include"libfractol.h"
#include"libscreen.h"
#include<stdlib.h>
#include"libftprintf.h"

void	fractol_exit(t_fractol *self)
{
	ft_printf("Ungracefully closing the program:\n");
	screen_destroy(self->screen);
	free(self);
	ft_printf("\tAdios 🖕\n");
	exit(-1);
}
