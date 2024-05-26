/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_config_camera_size.c                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 23:45:15 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 15:46:11 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libft.h"
#include"libft2.h"

void	fractol_config_camera_size(t_fractol *self, char *option)
{
	char	**split;
	t_pt	camera_size;

	if (option)
	{
		split = ft_split(option, 'x');
		camera_size.x = ft2_unsafe_strtod(split[0]);
		camera_size.y = ft2_unsafe_strtod(split[1]);
	}
	else if (!option || !camera_size.x || !camera_size.y)
	{
		camera_size.x = 4;
		camera_size.y = 4;
	}
	self->camera.size = camera_size;
}
