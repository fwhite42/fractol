/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol.c                                               4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 12:06:59 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/16 17:57:05 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libparser.h"

int	main(int ac, char **av)
{
	t_parser	parser;

	parser_parse_cmd_line_options(&parser, ac, av);
	parser_print(&parser);
	return (0);
}
