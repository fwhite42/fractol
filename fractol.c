#include"libfractol.h"
#include"libftprintf.h"
#include"libmlx.h"
#include"libcplx.h"
#include"math.h"
#include<stdio.h>

t_pt	julia_next(t_pt z, t_pt c)
{
	z = cplx_square(z);
	c.y *= -1;
	c.x *= -1;
	z = cplx_sum(z, c);
	return (z);
}

t_pt	mandelbrot_next(t_pt z, t_pt c)
{
	z = cplx_square(z);
	z =  cplx_sum(z, c);
	return (z);
}

t_pt	burningship_next(t_pt z, t_pt c)
{
	z.x = fabs(z.x);
	z.y = fabs(z.y);
	return (mandelbrot_next(z, c));
}

void camera_zoom(t_fractol *ctx, t_pt screen_mouse, double zoom_factor)
{
	t_pt mouse;
	t_pt delta;

	mouse = fractol_rescale(ctx, screen_mouse);
	mouse = fractol_transform(ctx, mouse);
	mouse = fractol_translate(ctx, mouse);
	ctx->screen_size.x *= zoom_factor;
	ctx->screen_size.y *= zoom_factor;
	delta = fractol_rescale(ctx, screen_mouse);
	delta = fractol_transform(ctx, delta);
	ctx->camera_center.x = mouse.x - delta.x;
	ctx->camera_center.y = mouse.y - delta.y;
}
void	draw(t_fractol *self)
{

	int	i = 0;
	int	j = 0;
	
	while (i < 800)
	{
		int color = 0x0;
		while (j < 800)
		{
			t_pt pt = (t_pt) {(double) i, (double) j};
			pt = fractol_rescale(self, pt);
			pt = fractol_transform(self, pt);
			pt = fractol_translate(self, pt);
			double val = fractol_evaluate(pt, 1000, julia_next);
			if (val != 2)
			{
				//printf("Point (%i, %i) -> (%f, %f)\n", i, j, pt.x, pt.y);
				//printf("Evaluates to : %f\n", val);
			}
			val /= 2;
			val *= 10000;
			mlx_pixel_put(self->ui->mlx, self->ui->win, i, j, (int) val + color);
			j++;
		}
		j = 0;
		i++;
	}
}

int	mouse_hook(int button, int x, int y, void *self)
{
	t_pt	pt;

	pt = (t_pt) {(double) x, (double) y};
	pt = fractol_rescale(self, pt);
	pt = fractol_transform(self, pt);
	pt = fractol_translate(self, pt);
	printf("[%i] Point (%i, %i) -> (%f, %f)\n", button, x, y, pt.x, pt.y);
	double val = fractol_evaluate(pt, 60, mandelbrot_next);
	printf("Evaluates to : %f\n", val);
	if (button == 4)
	{
		camera_zoom(self, (t_pt) {x, y}, 0.9);
		//draw(self);
	}
	if (button == 5)
	{
		camera_zoom(self, (t_pt) {x, y}, 1.2);
		//draw(self);
	}
	return (0);
}

int	foo(void *this)
{
	t_fractol	*self;
	self = this;
	self->tick++;
	if (self->tick % 1000 == 0)
		draw(self);
	return (0);
}

int	main(void)
{
	t_fractol	*self;

	self = fractol_create(800, 800);
	mlx_mouse_hook(self->ui->win, mouse_hook, self);
	mlx_loop_hook(self->ui->mlx,foo,self);
	draw(self);
	fractol_start(self);
	return (0);
}
