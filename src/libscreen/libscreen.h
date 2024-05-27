/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libscreen.h                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 03:27:29 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 03:27:31 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSCREEN_H
# define LIBSCREEN_H

# include"libcplx.h"

typedef struct s_screen	t_screen;

t_screen	*screen_create_null(void);
void		screen_init(t_screen *self, void *mlx);
void		screen_refresh(t_screen *self, void *caller);
void		screen_refresh_old(t_screen *self, void *caller);
void		screen_foreach_px(t_screen *self, void (*fn)(), void *caller);
void		screen_draw_px(t_screen *self, t_pt pos, int color);
void		screen_destroy(t_screen *self, void *mlx);

struct s_screen
{
	t_pt	size;
	char	*title;
	void	*win;
	void	*img;
	void	*old_img;
};

#endif
