/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_apply_zoom.c                                    4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 18:56:33 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/22 18:56:34 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

int	fractol_apply_zoom(t_fractol *self, int cmd)
{
	t_pt		ss;
	
	ss = self->screen->size;
	if (cmd == KEY_ZOOM_IN)
		fractol_onzoom(MOUSE_ZOOM_IN, ss.x / 2, ss.y / 2, self);
	else if (cmd == KEY_ZOOM_OUT)
		fractol_onzoom(MOUSE_ZOOM_OUT, ss.x / 2, ss.y / 2, self);
	return (0);
}
