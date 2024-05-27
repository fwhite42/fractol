/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   camera_rescale.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/21 08:00:37 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:28:01 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"

t_pt	camera_rescale(t_camera *self, t_screen *screen, t_pt pt)
{
	t_pt	ratio;

	ratio.x = self->size.y / screen->size.y;
	ratio.y = self->size.y / screen->size.y;
	pt.x *= ratio.x;
	pt.y *= ratio.y;
	return (pt);
}
