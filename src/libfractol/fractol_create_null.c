/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_create_null.c                                   4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 02:05:32 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 02:05:39 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libft.h"

t_fractol	*fractol_create_null(void)
{
	void	*self;

	self = ft_calloc(1, sizeof(t_fractol));
	return (self);
}
