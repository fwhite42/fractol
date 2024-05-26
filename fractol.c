/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol.c                                               4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 12:06:59 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 20:06:51 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"

int	main(int ac, char **av)
{
	t_screen	screen;
	t_fractol	self;

	fractol_configure(&self, &screen, ac, av);
	fractol_set_hooks(&self);
	fractol_start(&self);
	return (0);
}
