/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libfractol.h                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/21 08:21:12 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/26 20:24:17 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFRACTOL_H
# define LIBFRACTOL_H

# include"libparser.h"
# include"libcplx.h"
# include"libiterator.h"
# include"libscreen.h"
# include"libcamera.h"
// Change camera position and size wrt to mouse position
# define MOUSE_ZOOM_IN				0x04
# define MOUSE_ZOOM_OUT				0x05
// Change camera position dynamically
# define KEY_MOVE_UP				0xd
# define KEY_MOVE_DOWN				0x1
# define KEY_MOVE_RIGHT				0x2
# define KEY_MOVE_LEFT				0x0
// Change max nbr of iterations dyncamically
# define KEY_MORE_ITER				0x45
# define KEY_LESS_ITER				0x4e
// Change iterator power dyncamically
# define KEY_INCREASE_ITER_POW		0x2d
# define KEY_DECREASE_ITER_POW		0x2e
// Change fractal constant value dynamically
# define KEY_XMOVE_UP				0x28		
# define KEY_XMOVE_DOWN				0x26
# define KEY_XMOVE_RIGHT			0x25
# define KEY_XMOVE_LEFT				0x04
// Change color source dynamically
# define KEY_CAMOVE_UP				0x56		
# define KEY_CRMOVE_UP				0x56		
# define KEY_CGMOVE_UP				0x56		
# define KEY_CBMOVE_UP				0x56		
# define KEY_CAMOVE_DOWN			0x56		
# define KEY_CRMOVE_DOWN			0x56		
# define KEY_CGMOVE_DOWN			0x56		
# define KEY_CBMOVE_DOWN			0x56		
// Change camera size wrt to the center of the camera
# define KEY_ZOOM_IN				0x22
# define KEY_ZOOM_OUT				0x1f
// (Un)gracefully close the program
# define KEY_ESC					0x35
// Shows/unshows program infromations
# define KEY_SPACE_BAR				0x31
// Toggles anti aliasing
# define KEY_ANTI_ALIAS				0x57
// Hard configuration
# define ZOOM_IN_FACTOR				0.8
# define ZOOM_OUT_FACTOR			1.4
# define KEYPRESS_DELTA				33
# define FRACTOL_REFRESH_RATE		1024
// Default configration
# define DFLT_CAMERA_WIDTH			4
# define DFLT_CAMERA_HEIGHT			4
# define DFLT_SCREEN_WIDTH			64 * 8
# define DFLT_SCREEN_HEIGHT			64 * 8
# define DFLT_CAMERA_CENTER_X		0
# define DFLT_CAMERA_CENTER_Y		0
# define DFLT_ITERATOR_FN			iterator_mandelbrot
# define DFLT_COLOR_SOURCE			0x000099cc
# define DFLT_COLOR_TYPE			0

typedef struct s_fractol	t_fractol;
typedef enum e_color_type	t_color_type;

void	fractol_config_fractal_fn(t_fractol *self, char *option);
void	fractol_config_screen_size(t_fractol *self, char *option);
void	fractol_config_camera_size(t_fractol *self, char *option);
void	fractol_config_camera_center(t_fractol *self, char *option);
void	fractol_config_constant_pt(t_fractol *self, char *option);

void	fractol_draw(t_fractol *self);
void	fractol_init_mlx(t_fractol *self);

#include"libmlxconsole.h"
void	fractol_print_camera_data_on_screen(t_fractol *selfi, t_mlxconsole *console);
void	fractol_print_iterator_data_on_screen(t_fractol *self, t_mlxconsole *console);

void	fractol_unshow_console(t_fractol *self);
void	fractol_show_console(t_fractol *self);

void	fractol_start(t_fractol *self);
void	fractol_exit(t_fractol *self);
void	fractol_destroy(t_fractol *self);
double	fractol_evaluate(t_fractol *self, t_pt pt);

void	fractol_configure(t_fractol *self, t_screen *screen, int ac, char **av);
void	fractol_configure_default(t_fractol *self);

void	fractol_set_hooks(t_fractol *self);

int		fractol_onzoom(int cmd, int x, int y, void *self);
int		fractol_onloop(void *self);

int		fractol_change_max_iteration(t_fractol *self, int cmd);
int		fractol_toggle_antialias(t_fractol *self, int cmd);
int		fractol_move_iterator_constant(t_fractol *self, int cmd);
int		fractol_move_camera(t_fractol *self, int cmd);
int		fractol_onkeypress(int cmd, void *self);

int		fractol_getcolor(t_fractol *self, t_pt spt);
enum e_color_type
{
	color_cubic_0,
	color_square_0
};

struct s_fractol
{
	char			*fractal_name;
	t_color_type	color_type;
	int				color_source;
	t_iterator_fn	iterator_fn;
	t_iterator		iterator_data;
	t_camera		camera;
	t_screen		*screen;
	void			*mlx;
	int				mlx_loop_counter;
	int				requires_image_update;
	int				draw_console_switch;
};

#endif
