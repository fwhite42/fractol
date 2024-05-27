/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   error_set_message.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/02 03:36:59 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/02 03:44:44 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include "liberror.h"

void	error_set_message(void *self, char *message)
{
	if (self)
		((t_error *)self)->message = message;
}
