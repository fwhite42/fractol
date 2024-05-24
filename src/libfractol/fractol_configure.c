/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_configure.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 22:37:06 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/23 11:36:14 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libftprintf.h"
#include<stddef.h>

void	fractol_configure(t_fractol *self, t_parser *parsed)
{
	char	*option;

	if (parsed->options == NULL)
	{
		ft_printf("No options provided. Using default Fract'ol config.\n");
		fractol_configure_default(self);
	}
	option = parser_get_cmd_line_option(parsed, "fractal");
	if (option)
		fractol_config_fractal_fn(self, option);
	option = parser_get_cmd_line_option(parsed, "screen_size");
	if (option)
		fractol_config_screen_size(self, option);
}
