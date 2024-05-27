/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_destroy.c                                       4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 02:05:16 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 02:05:18 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"stdlib.h"

void	fractol_destroy(t_fractol *self)
{
	free(self);
}
