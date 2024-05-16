/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   error_print.c                                           4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/02/22 01:35:48 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/07 11:11:48 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"liberror.h"
#include"libftprintf.h"

void error_print(void *self)
{
	t_error	*error;
	
	error = (t_error *)self;
	ft_printf(LIB_ERROR_HEADER);
	ft_printf("Value:\t\t%i\n", error->value);
	ft_printf("Message:\t%s\n", error->message);
}
