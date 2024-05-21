/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   camera_translate.c                                      4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/21 08:01:08 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/21 08:02:25 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"

t_pt	camera_translate(t_camera *self, t_pt pt)
{
	pt.x += self->center.x;
	pt.y += self->center.y;
	return (pt);
}
