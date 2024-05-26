/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_config_camera_center.c                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 23:45:15 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 16:38:12 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libft.h"
#include"libft2.h"

void	fractol_config_camera_center(t_fractol *self, char *option)
{
	char	**split;
	t_pt	camera_center;

	if (option)
	{
		split = ft_split(option, 'x');
		camera_center.x = ft2_unsafe_strtod(split[0]);
		camera_center.y = ft2_unsafe_strtod(split[1]);
	}
	else
	{
		camera_center.x = 0;
		camera_center.y = 0;
	}
	self->camera.center = camera_center;
}
