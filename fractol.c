/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol.c                                               4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 12:06:59 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/21 15:31:38 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libparser.h"
#include"libftprintf.h"
#include"libft.h"
#include"liberror.h"
#include"libcolor.h"

static void	_load_iterator(t_fractol *fractol, t_parser *parser)
{
	char	*option;

	option = parser_get_cmd_line_option(parser, "fractal");
	if (option != NULL)
	{
		if (!ft_strncmp(option, "julia", 6))
			fractol->iterator = iterator_julia;
		else if (!ft_strncmp(option, "mandelbrot", 11))
			fractol->iterator = iterator_mandelbrot;
		else if (!ft_strncmp(option, "burning ship", 13))
			fractol->iterator = iterator_burning_ship;
		else
			error_fatal("Found unknown fractal in cmd line args", -42);
		fractol->fractal_name = option;
	}
	fractol->fractal_name = "mandelbrot";
}

static void _init(t_parser *parser)
{
	char	*option;
	double	screen_size[2];

	option = parser_get_cmd_line_option(parser, "screen_size");
	screen_size = parser_parse_r2_point(option, "x");
	printf("size(%f, %f)\n", screen_size[0], screen_size[1]);
}

int	main(int ac, char **av)
{
	t_parser	parser;
	t_fractol	*fractol;

	parser_parse_cmd_line_options(&parser, ac, av);
	_init(&parser);
	fractol = fractol_create_default();
	_load_iterator(fractol, &parser);
	fractol_draw(fractol);
	fractol_start(fractol);
	return (0);
}
