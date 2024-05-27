/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   error_set_value.c                                       4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/02 03:32:02 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/02 03:46:00 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include "liberror.h"

void	error_set_value(void *self, int value)
{
	if (self)
		((t_error *)self)->value = value;
}
