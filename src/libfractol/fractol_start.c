#include"libfractol.h"
#include"libftprintf.h"
#include"libmlx.h"
#include<stdio.h>

static int	fractol_onzoom(int cmd, int x, int y, void *this)
{
	t_fractol	*self;
	t_camera	*camera;
	t_screen	*screen;
	t_pt		pt;

	self = this;
	camera = &(self->camera);
	screen = self->screen;
	pt = (t_pt) {(double) x, (double) y};
	pt = camera_rescale(camera, screen, pt);
	pt = camera_transform(camera, pt);
	pt = camera_translate(camera, pt);
	if (cmd == MOUSE_ZOOM_IN)
		camera_zoom(camera, screen, (t_pt) {x, y}, ZOOM_IN_FACTOR);
	if (cmd == MOUSE_ZOOM_OUT)
		camera_zoom(camera, screen,  (t_pt) {x, y}, ZOOM_OUT_FACTOR);
	self->update = 1;
	return (0);
}

static int	fractol_onkeypress(int keycode, void *this)
{
	t_camera	camera;
	t_fractol	*self;

	self = this;
	camera = self->camera;
	if (keycode == KEY_ESC || keycode == KEY_SPACE_BAR)
		return (mlx_clear_window(self->mlx, self->screen->win));
	else if (keycode == KEY_MOVE_UP)
		self->camera.center.y += self->camera.size.y / KEYPRESS_DELTA;
	else if (keycode == KEY_MOVE_DOWN)
		self->camera.center.y -= self->camera.size.y / KEYPRESS_DELTA;
	else if (keycode == KEY_MOVE_LEFT)
		self->camera.center.x -= self->camera.size.x / KEYPRESS_DELTA;
	else if (keycode == KEY_MOVE_RIGHT)
		self->camera.center.x += self->camera.size.x / KEYPRESS_DELTA;
	else if (keycode == KEY_XMOVE_UP)
		self->iterator_data.c.y += self->camera.size.y / KEYPRESS_DELTA;
	else if (keycode == KEY_XMOVE_DOWN)
		self->iterator_data.c.y -= self->camera.size.y / KEYPRESS_DELTA;
	else if (keycode == KEY_XMOVE_LEFT)
		self->iterator_data.c.x -= self->camera.size.x / KEYPRESS_DELTA;
	else if (keycode == KEY_XMOVE_RIGHT)
		self->iterator_data.c.x += self->camera.size.x / KEYPRESS_DELTA;
	else if (keycode == KEY_ZOOM_IN)
		fractol_onzoom(4, camera.center.x, camera.center.y, self);
	else if (keycode == KEY_ZOOM_OUT)
		fractol_onzoom(5, camera.center.x, camera.center.y, self);
	else if (keycode == KEY_MORE_ITER)
		self->iterator_data.max_iteration *= 2;
	else if (keycode == KEY_LESS_ITER)
	{
		if (self->iterator_data.max_iteration > 1)
			self->iterator_data.max_iteration /= 2;
	}
	else
	{
		ft_printf("Keycode : %#x\n", keycode);
		return (1);
	}
	self->update = 1;
	return (0);
}

static int	fractol_onloop(void *self)
{
	t_fractol	*this;

	this = self;
	this->loop_counter++;
	if (this->update == 0)
		return (0);
	if (this->loop_counter > MLX_LOOPS_COUNTER_TH)
	{
		this->loop_counter = 0;
		ft_printf("Received user input, redrawing...\n");
		fractol_draw(self);
	}
	this->update = 0;
	return (0);
}

void	fractol_start(t_fractol *self)
{
	mlx_mouse_hook(self->screen->win, fractol_onzoom, self);
	mlx_key_hook(self->screen->win, fractol_onkeypress, self);
	mlx_loop_hook(self->mlx, fractol_onloop, self);
	mlx_loop(self->mlx);
}
