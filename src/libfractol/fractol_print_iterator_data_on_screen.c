/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fractol_print_iterator_data_on_screen.c                 4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 19:02:23 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:41:49 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libfractol.h"
#include"libmlxconsole.h"
#include"libft.h"
#include"libft2.h"

void	fractol_print_iterator_data_on_screen(t_fractol *s, t_mlxconsole *cnsl)
{
	char	*data;

	mlxconsole_write_info_line(cnsl, "", "");
	mlxconsole_write_info_line(cnsl, "> Iterator Data", "");
	data = s->fractal_name;
	mlxconsole_write_info_line(cnsl, " fractal name      :=", data);
	data = ft_itoa(s->iterator_data.max_iteration);
	mlxconsole_write_info_line(cnsl, " max iteration     :=", data);
	free(data);
	data = ft2_double_to_str(s->iterator_data.n);
	mlxconsole_write_info_line(cnsl, " iterator exponent :=", data);
	free(data);
	if (s->iterator_data.anti_alias)
		data = "active";
	else
		data = "inactive";
	mlxconsole_write_info_line(cnsl, " anti aliasing     :=", data);
}
