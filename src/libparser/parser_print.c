/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser_print.c                                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 16:09:51 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/16 17:57:48 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libparser.h"
#include"libftprintf.h"

void	_print_option(t_cmd_line_option option)
{
	ft_printf("\t%s:\t%s;\n", option.key, option.value);
}

void	parser_print(t_parser *self)
{
	int	i;

	i = 0;
	ft_printf("{");
	if (self->nbr_of_options < 2)
		ft_printf("\n");
	while (i < self->nbr_of_options)
		_print_option(self->options[i++]);
	ft_printf("}\n");
}
