/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser_destroy.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/26 20:05:59 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 20:06:49 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libparser.h"
#include<stdlib.h>

void	parser_destroy(t_parser *self)
{
	free(self->options);
}
