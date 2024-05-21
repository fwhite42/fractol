/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libfractol.h                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/21 08:21:12 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/21 14:18:00 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFRACTOL_H
# define LIBFRACTOL_H

# include"libcplx.h"
# include"libiterator.h"
# include"libscreen.h"
# include"libcamera.h"

// Zoom intensity
# define ZOOM_IN_FACTOR		0.8
# define ZOOM_OUT_FACTOR	1.4
# define KEYPRESS_DELTA		33

/* ************************************************************************** */
/*	MacOS key bindings														  */
/* ************************************************************************** */

// WheelDown ; WheelUp
# define MOUSE_ZOOM_IN				4
# define MOUSE_ZOOM_OUT				5

//W ; S ; D ; A
# define KEY_MOVE_UP				0xd
# define KEY_MOVE_DOWN				0x1
# define KEY_MOVE_RIGHT				0x2
# define KEY_MOVE_LEFT				0x0

//NumPad+, NumPad-
# define KEY_MORE_ITER				0x45
# define KEY_LESS_ITER				0x4e

//NumPad8 ; NumPad2 ; NumPad4 ; NumPad6
# define KEY_XMOVE_UP				0x56		
# define KEY_XMOVE_DOWN				0x5b
# define KEY_XMOVE_RIGHT			0x58
# define KEY_XMOVE_LEFT				0x54

// I ; O
# define KEY_ZOOM_IN				0x22
# define KEY_ZOOM_OUT				0x1f

# define KEY_ESC					0x35
# define KEY_SPACE_BAR				0x31

# define FRACTOL_REFRESH_RATE		1024
# define KEY_ANTI_ALIAS				0x57

typedef struct s_fractol	t_fractol;

t_fractol					*fractol_create_null(void);
t_fractol					*fractol_create_default(void);
t_fractol					*fractol_create_custom(int ac, char **av);
void						fractol_start(t_fractol *self);
void						fractol_draw(t_fractol *self);
void						fractol_exit(t_fractol *self);
void						fractol_destroy(t_fractol *self);
int							fractol_getcolor(t_fractol *self, t_pt spt);
double						fractol_evaluate(t_fractol *self, t_pt pt);

struct s_fractol
{
	int				color_type;
	int				color_source;
	int				draw_console;
	int				*palette;
	int				loop_counter;
	int				update;
	t_iterator_fn	iterator;
	t_iterator		iterator_data;
	t_camera		camera;
	t_screen		*screen;
	void			*mlx;
	char			*fractal_name;
};

#endif
