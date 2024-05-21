/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   camera_transform.c                                      4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/21 08:00:53 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/21 08:00:57 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"

t_pt	camera_transform(t_camera *self, t_pt pt)
{
	pt.x -= self->size.x / 2;
	pt.y -= self->size.y / 2;
	pt.y *= -1;
	return (pt);
}
