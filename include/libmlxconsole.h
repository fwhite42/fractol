/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libmlxconsole.h                                         4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 13:32:11 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 02:20:44 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLXCONSOLE_H
# define LIBMLXCONSOLE_H

typedef struct s_mlxconsole	t_mlxconsole;

#include"libcplx.h"
#include"libfractol.h"

struct s_mlxconsole
{
	void		*mlx;
	void		*win;
	int			bg_color;
	int			txt_color;
	t_pt		size;
	t_pt		offset;
	t_pt		cursor;
};

t_mlxconsole	mlxconsole_default(t_fractol *self);

void	mlxconsole_draw(t_mlxconsole *self);
void	mlxconsole_write(t_mlxconsole *self, char *str);
void	mlxconsole_write_info_line(t_mlxconsole *self, char *key, char *valye);
#endif
