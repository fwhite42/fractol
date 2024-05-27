/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   screen_create_null.c                                    4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 09:44:09 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 09:44:11 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libscreen.h"
#include"libft.h"

t_screen	*screen_create_null(void)
{
	t_screen	*self;

	self = ft_calloc(1, sizeof(t_screen));
	return (self);
}
