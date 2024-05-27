/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   error_fatal.c                                           4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/02 03:43:25 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/02 03:45:47 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"liberror.h"
#include<stdlib.h>

void	error_fatal(char *message, int value)
{
	error_log(message, value);
	exit(value);
}
