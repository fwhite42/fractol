/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_print_camera_data_on_screen.c                   4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 19:01:20 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 18:22:43 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libmlxconsole.h"
#include"libft2.h"
#include<stdlib.h>

void fractol_print_camera_data_on_screen(t_fractol *self, t_mlxconsole *console)
{
	char	*data;

	mlxconsole_write_info_line(console, "", "");
	mlxconsole_write_info_line(console, "> Camera data", "");
	data = ft2_double_to_str(self->camera.center.x);
	mlxconsole_write_info_line(console, " camera x          :=", data);
	free(data);
	data = ft2_double_to_str(self->camera.center.y);
	mlxconsole_write_info_line(console, " camera y          :=", data);
	free(data);
	data = ft2_double_to_str(self->camera.size.x);
	mlxconsole_write_info_line(console, " camera width      :=", data);
	free(data);
	data = ft2_double_to_str(self->camera.size.y);
	mlxconsole_write_info_line(console, " camera height     :=", data);
	free(data);
}