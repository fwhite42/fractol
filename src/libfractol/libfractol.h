#ifndef LIBFRACTOL_H
# define LIBFRACTOL_H

# include"libcplx.h"
# include"libiterator.h"
# include"libscreen.h"
# include"libcamera.h"

// Zoom intensity
# define ZOOM_IN_FACTOR		0.8
# define ZOOM_OUT_FACTOR	1.4
# define KEYPRESS_DELTA		100

// Mouse bindings for : zoom
# define MOUSE_ZOOM_IN		4
# define MOUSE_ZOOM_OUT		5

// Keyboard bindings for: translate
# define KEY_MOVE_UP		0x1
# define KEY_MOVE_DOWN		0xd
# define KEY_MOVE_RIGHT		0x2
# define KEY_MOVE_LEFT		0x0

// Keyboard bindings for: zoom
# define KEY_ZOOM_IN		1111
# define KEY_ZOOM_OUT		1111

// Keybord binding for: quit the app
# define KEY_ESC			0x35
# define KEY_SPACE_BAR		1111

// Program Threasholds
# define MLX_LOOPS_COUNTER_TH	1024
# define FRACTAL_ITERATION_TH	256

typedef struct s_fractol	t_fractol;

t_fractol					*fractol_create_null(void);
t_fractol					*fractol_create_default(void);
t_fractol					*fractol_create_custom(int ac, char **av);
void						fractol_start(t_fractol *self);
void						fractol_draw(t_fractol *self);
void						fractol_exit(t_fractol *self);
void						fractol_destroy(t_fractol *self);
int							fractol_getcolor(t_fractol *self, t_pt spt);
int							fractol_evaluate(t_fractol *self, t_pt pt);

struct s_fractol
{
	int				*palette;
	int				loop_counter;
	int				update;
	t_iterator_fn	iterator;
	t_camera		camera;
	t_screen		*screen;
	void			*mlx;
};

#endif
