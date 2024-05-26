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
