#ifndef LIBSCREEN_H
# define LIBSCREEN_H

# include"libcplx.h"

typedef struct s_screen	t_screen;

struct s_screen
{
	t_pt	size;
	char	*title;
	void	*win;
	void	*img;
	int	*imgbuff;
};

t_screen	*screen_create_null(void);

// Caller has to be a mlx instance
t_screen	*screen_create(t_pt size, char *title, void *caller);
void		screen_refresh(t_screen *self, void *caller);
void		screen_foreach_px(t_screen *self, void (*fn)(), void *caller);
// Draws a pixel on the img
void		screen_draw_px(t_screen *self, t_pt pos, int color);
// Deconstruct
void		screen_destroy(t_screen *self);
#endif
