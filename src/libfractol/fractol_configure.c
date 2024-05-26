/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_configure.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 22:37:06 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 18:32:58 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libftprintf.h"
#include"libmlx.h"
#include"liberror.h"
#include<stddef.h>
#include"libft.h"
#include"libft2.h"

#include<stdio.h>
void	fractol_configure(t_fractol *self, t_parser *parsed)
{
	char	*option;


	self->mlx = mlx_init();
	if (self->mlx == NULL)
	{
		error_fatal("Cannot init mlx", -42);
	}
	if (parsed == NULL || parsed->options == NULL)
	{
		ft_printf("No options provided. Using default Fract'ol config.\n");
		fractol_configure_default(self);
		return ;
	}
	option = parser_get_cmd_line_option(parsed, "iterator_fn");
	fractol_config_fractal_fn(self, option);
	option = parser_get_cmd_line_option(parsed, "screen_size");
	fractol_config_screen_size(self, option);
	option = parser_get_cmd_line_option(parsed, "camera_size");
	fractol_config_camera_size(self, option);
	option = parser_get_cmd_line_option(parsed, "camera_center");
	fractol_config_camera_center(self, option);
	option = parser_get_cmd_line_option(parsed, "camera_size");
	screen_init(self->screen, self->mlx);
	iterator_init(&(self->iterator_data));
	self->requires_image_update = 1;
}
