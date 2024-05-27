/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_exit.c                                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 01:44:02 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:44:04 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libmlx.h"
#include"libfractol.h"
#include"libscreen.h"
#include<stdlib.h>
#include"libftprintf.h"

void	fractol_exit(t_fractol *self)
{
	ft_printf("Ungracefully closing the program:\n");
	screen_destroy(self->screen, self->mlx);
	ft_printf("\tAdios 🖕\n");
	exit(0);
}
