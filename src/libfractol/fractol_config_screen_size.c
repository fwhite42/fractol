/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_config_screen_size.c                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 23:45:15 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/23 11:12:05 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libft.h"
#include"libft2.h"

void	fractol_config_screen_size(t_fractol *self, char *option)
{
	char	**split;
	t_pt	screen_size;

	if (option)
	{
		split = ft_split(option, 'x');
		screen_size.x = ft2_unsafe_strtod(split[0]);
		screen_size.y = ft2_unsafe_strtod(split[1]);
	}
	else if (!option || !screen_size.x || !screen_size.y)
	{
		screen_size.x = 800;
		screen_size.y = 800;
	}
	self->screen->size = screen_size;
}
