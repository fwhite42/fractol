/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   error_print.c                                           4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/02 03:41:09 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/13 14:39:43 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"liberror.h"
#include"libft.h"
#include"libftprintf.h"

void	error_print(void *self)
{
	t_error	*error;
	char	*itemsym;

	itemsym = "";
	error = (t_error *)self;
	ft_printf(ERROR_STYLE);
	ft_putstr_fd(ERROR_HEADER, 2);
	ft_printf("%s[  Value  ]\t %i\n", itemsym, error->value);
	ft_printf("%s[ Message ]\t %s\n", itemsym, error->message);
	ft_printf(ERROR_FOOTER);
}
