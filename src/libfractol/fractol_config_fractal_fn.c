/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_config_fractal_fn.c                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 23:36:25 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 16:23:33 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libft.h"
#include"liberror.h"

void	fractol_config_fractal_fn(t_fractol *self, char *option)
{
	if (option)
	{
		if (!ft_strncmp(option, "julia", 6))
			self->iterator_fn = iterator_julia;
		else if (!ft_strncmp(option, "mandelbrot", 11))
			self->iterator_fn = iterator_mandelbrot;
		else if (!ft_strncmp(option, "burning ship", 13))
			self->iterator_fn = iterator_burning_ship;
		else
			return (fractol_config_fractal_fn(self, NULL));
		self->fractal_name = option;
	}
	else if (!option)
	{
		self->fractal_name = "mandelbrot";
		self->iterator_fn = iterator_mandelbrot;
	}
}
