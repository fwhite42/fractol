/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_print_camera_on_screen.c                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 19:01:20 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 10:42:08 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libmlxconsole.h"
#include"libft2.h"
#include<stdlib.h>

void	fractol_print_camera_on_screen(t_fractol *s, t_mlxconsole *cnsl)
{
	char	*data;

	mlxconsole_write_info_line(cnsl, "", "");
	mlxconsole_write_info_line(cnsl, "> Camera data", "");
	data = ft2_double_to_str(s->camera.center.x);
	mlxconsole_write_info_line(cnsl, " camera x          :=", data);
	free(data);
	data = ft2_double_to_str(s->camera.center.y);
	mlxconsole_write_info_line(cnsl, " camera y          :=", data);
	free(data);
	data = ft2_double_to_str(s->camera.size.x);
	mlxconsole_write_info_line(cnsl, " camera width      :=", data);
	free(data);
	data = ft2_double_to_str(s->camera.size.y);
	mlxconsole_write_info_line(cnsl, " camera height     :=", data);
	free(data);
}
