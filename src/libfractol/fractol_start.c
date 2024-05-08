#include"libfractol.h"
#include"libmlx.h"

void	fractol_start(t_fractol *self)
{
	mlx_loop(self->ui->mlx);
}
