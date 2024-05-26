/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_print_iterator_data_on_screen.c                 4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 19:02:23 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 18:20:50 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libmlxconsole.h"
#include"libft.h"
#include"libft2.h"

void fractol_print_iterator_data_on_screen(t_fractol *self, t_mlxconsole *console)
{
	char	*data;

	mlxconsole_write_info_line(console, "", "");
	mlxconsole_write_info_line(console, "> Iterator Data", "");
	data = self->fractal_name;
	mlxconsole_write_info_line(console, " fractal name      :=", data);
	data = ft_itoa(self->iterator_data.max_iteration);
	mlxconsole_write_info_line(console, " max iteration     :=", data);
	free(data);
	data = ft2_double_to_str(self->iterator_data.n);
	mlxconsole_write_info_line(console, " iterator exponent :=", data);
	free(data);
	if (self->iterator_data.anti_alias)
		data = "active";
	else
		data = "inactive";
	mlxconsole_write_info_line(console, " anti aliasing     :=", data);
}
