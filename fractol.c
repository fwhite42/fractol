/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol.c                                               4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 12:06:59 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 15:41:35 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libparser.h"
#include"libft.h"
#include"libft2.h"

#include<stdio.h>

int	main(int ac, char **av)
{
	t_screen	screen;
	t_parser	options;
	t_fractol	self;

	ft_bzero(&options, sizeof(t_parser));
	ft_bzero(&self, sizeof(t_fractol));
	ft_bzero(&screen, sizeof(t_screen));

	self.screen = &screen;
	self.screen->title = "Fract'ol";
	parser_parse_cmd_line_options(&options, ac, av);
	printf("ok\n");
	fractol_configure(&self, &options);
	fractol_set_hooks(&self);
	fractol_start(&self);
	return (0);
}
