/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_configure.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 22:37:06 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 20:11:23 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libmlx.h"
#include"libftprintf.h"
#include"libscreen.h"
#include"liberror.h"
#include"libft.h"

void static	__configure_screen(t_fractol *self, t_screen *screen, t_parser *options)
{
	char	*option;

	if (!screen)
		error_fatal("Cannot configure fractol without a valid screen", -42);
	ft_bzero(screen, sizeof(t_screen));
	self->screen = screen;
	self->screen->title = "Fract'ol";
	option = parser_get_cmd_line_option(options, "screen_size");
	fractol_config_screen_size(self, option);
	screen_init(self->screen, self->mlx);
}

void static	__configure_camera(t_fractol *self, t_parser *options)
{
	char		*option;

	option = parser_get_cmd_line_option(options, "camera_size");
	fractol_config_camera_size(self, option);
	option = parser_get_cmd_line_option(options, "camera_center");
	fractol_config_camera_center(self, option);
	option = parser_get_cmd_line_option(options, "camera_size");
}

void static	__configure_iterator(t_fractol *self, t_parser * options)
{
	char	*option;

	option = parser_get_cmd_line_option(options, "iterator_fn");
	fractol_config_fractal_fn(self, option);
	iterator_init(&(self->iterator_data));
}

void	fractol_configure(t_fractol *self, t_screen *screen, int ac, char **av)
{
	t_parser	options;

	ft_bzero(self, sizeof(t_fractol));
	fractol_init_mlx(self);
	parser_parse_cmd_line_options(&options, ac, av);
	__configure_screen(self, screen, &options);
	__configure_camera(self, &options);
	__configure_iterator(self, &options);
	parser_destroy(&options);
}
