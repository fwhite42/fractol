/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_move_iterator_constant.c                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 18:26:45 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/23 16:35:42 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libft.h"

int	fractol_move_iterator_constant(t_fractol *self, int keycode)
{
	t_pt	*target;

	if (ft_strncmp(self->fractal_name, "julia", 6) == 0)
		target = &(self->iterator_data.c);
	else
		target = &(self->iterator_data.z0);
	if (keycode == KEY_XMOVE_UP)
			target->y += self->camera.size.y / KEYPRESS_DELTA;
	else if (keycode == KEY_XMOVE_DOWN)
			target->x -= self->camera.size.y / KEYPRESS_DELTA;
	else if (keycode == KEY_XMOVE_LEFT)
			target->x -= self->camera.size.x / KEYPRESS_DELTA;
	else if (keycode == KEY_XMOVE_RIGHT)
			target->x += self->camera.size.x / KEYPRESS_DELTA;
	else
		return (0);
	return (1);
}
