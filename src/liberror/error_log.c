/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   error_log.c                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/02 03:35:55 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/02 03:53:17 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"liberror.h"

void	error_log(char *message, int value)
{
	t_error	error;

	error_set_message(&error, message);
	error_set_value(&error, value);
	error_print(&error);
}
