/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_configure.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 22:37:06 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 11:27:21 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libparser.h"
#include"libmlx.h"
#include"libftprintf.h"
#include"libscreen.h"
#include"liberror.h"
#include"libft.h"

void static	_configure_screen(t_fractol *self, t_screen *screen, t_parser *opts)
{
	char	*option;

	if (!screen)
		error_fatal("Cannot configure fractol without a valid screen", -42);
	ft_bzero(screen, sizeof(t_screen));
	self->screen = screen;
	self->screen->title = "Fract'ol";
	option = parser_get_cmd_line_option(opts, "screen_size");
	fractol_config_screen_size(self, option);
	screen_init(self->screen, self->mlx);
}

void static	_configure_camera(t_fractol *self, t_parser *opts)
{
	char		*option;

	option = parser_get_cmd_line_option(opts, "camera_size");
	fractol_config_camera_size(self, option);
	option = parser_get_cmd_line_option(opts, "camera_center");
	fractol_config_camera_center(self, option);
	option = parser_get_cmd_line_option(opts, "camera_size");
}

void static	_configure_iterator(t_fractol *self, t_parser *opts)
{
	char	*option;

	option = parser_get_cmd_line_option(opts, "iterator_fn");
	fractol_config_fractal_fn(self, option);
	iterator_init(&(self->iterator_data));
}

void static _configure_colors(t_fractol *self, t_parser *opts)
{
	char	*option;

	option = parser_get_cmd_line_option(opts, "color_source");
	if (option)
		self->color_source = ft_atoi(option);
	else
		self->color_source = DFLT_COLOR_SOURCE;
	option = parser_get_cmd_line_option(opts, "color_type");
	if (option)
		self->color_type = ft_atoi(option);
	else
		self->color_type = 1;
}

void	fractol_configure(t_fractol *self, t_screen *screen, int ac, char **av)
{
	t_parser	opts;

	ft_bzero(self, sizeof(t_fractol));
	fractol_init_mlx(self);
	parser_parse_cmd_line_options(&opts, ac, av);
	_configure_screen(self, screen, &opts);
	_configure_camera(self, &opts);
	_configure_iterator(self, &opts);
	_configure_colors(self, &opts);
	parser_destroy(&opts);
}
