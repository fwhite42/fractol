/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   error_register.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/02 03:39:14 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/02 03:39:15 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

void	error_register(void *self, int value, char *message)
{
	if (self)
	{
		((t_error *)self)->value ^= value;
		((t_error *)self)->message = message;
	}
}
