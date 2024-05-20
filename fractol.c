/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol.c                                               4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 12:06:59 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/20 15:55:14 by fwhite42           _)/_\---/_\(_         */
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
	}
}

int	main(int ac, char **av)
{
	t_parser	parser;
	t_fractol	*fractol;

	parser_parse_cmd_line_options(&parser, ac, av);
	fractol = fractol_create_default();
	_load_iterator(fractol, &parser);
	fractol_draw(fractol);
	fractol_start(fractol);
	return (0);
}
