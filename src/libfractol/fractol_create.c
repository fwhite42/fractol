/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_create.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 12:44:15 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/18 16:18:22 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libmlx.h"

t_fractol	*fractol_create(t_pt cs, t_pt cc, t_pt ss, t_iterator_fn fn);
{
	t_camera	camera;
	t_fractol	*self;

	self = fractol_create_null();
	self->mlx = mlx_init();
	self->camera.size = cs;
	self->camera.center = cc;
	self->iterator = fn;
	self->update = 1;
	self->screen = screen_create(ss, "Fract'ol", self->mlx);
	return (self);
}
