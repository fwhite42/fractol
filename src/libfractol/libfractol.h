#ifndef LIBFRACTOL_H
# define LIBFRACTOL_H

# include"libcplx.h"
# include"libui.h"

typedef struct s_fractol	t_fractol;

struct s_fractol
{
	int	tick;
	t_pt camera_size;
	t_pt camera_center;
	t_pt screen_size;
	t_ui *ui;
};

t_fractol	*fractol_create_null(void);
t_fractol	*fractol_create(int width, int height);
void		fractol_start(t_fractol *self);
void		fractol_destroy(t_fractol *self);
t_pt		fractol_rescale(t_fractol *self, t_pt pt);
t_pt		fractol_transform(t_fractol *self, t_pt pt);
t_pt		fractol_translate(t_fractol *self, t_pt pt);
double		fractol_evaluate(t_pt pt, int th, t_pt (*next)(t_pt z, t_pt c));
#endif
