#include"libfractol.h"
#include"libcamera.h"
#include"libscreen.h"
#include"libcolor.h"
#include<math.h>
#include<stdio.h>
#include"libmlx.h"
#include"libft.h"

static int	get_color0(double x)
{
	return (pow(x, 3) + (2 * x * 0x000099cc) + 1);
}
/*
static int	get_color0(double x)
{
	if (x < 0)
		return (0x00000000);
	return (0x000099cc);
}
*/

/*
static int get_color0(double x)
{
	return (pow(x, 2));
}
*/
static void	fractol_draw_pt(t_fractol *self, t_pt screen_pt)
{
	t_pt	pt;
	double	color;
	double	color1;
	double	color2;
	double	t;
	
	pt = camera_rescale(&(self->camera), self->screen, screen_pt);
	pt = camera_transform(&(self->camera), pt);
	pt = camera_translate(&(self->camera), pt);
	color = fractol_evaluate(self, pt);
	if (color == -1)
			return ;
	color1 = get_color0(floor(color));
	color2 = get_color0(floor(color) + 1);
	t = color - floor(color);
	if (color1 != color2)
		color = color_interpolate(color1, color2, t);
	else
	{
		printf("Nothin to do\n");
		color = color1;
	}
//	printf("c : %#010x, \n",(int) color);
//	color = get_color((int) color);
	pt.x -= self->camera.center.x;
	pt.y -= self->camera.center.y;
	screen_draw_px(self->screen, screen_pt, (int) color);
}

char	*double_to_str(double x)
{
	char	*nbr;
	char	*tmp[2];
	int		integer_part;
	double	decimal_part;

	integer_part = floor(x);
	decimal_part = floor(fabs((x - integer_part)) * 1000000);
	tmp[1] = ft_itoa(integer_part);
	tmp[0] = ft_strjoin(tmp[1], ".");
	free(tmp[1]);
	tmp[1] = ft_itoa(floor(decimal_part));
	nbr = ft_strjoin(tmp[0], tmp[1]);
	free(tmp[0]);
	free(tmp[1]);
	return (nbr);
}

void	fractol_draw(t_fractol *self)
{
	screen_foreach_px(self->screen, fractol_draw_pt, self);
	screen_refresh(self->screen, self->mlx);	
	t_pt	offset;

	offset.x = self->screen->size.x / 128;
	offset.y = self->screen->size.y / 128;
	int		bg_color = 0x9b9b9b00;
	int		txt_color = 0x00cccccc;
	void	*win;
	void	*mlx;
	int		current_line;
	win = self->screen->win;
	mlx = self->mlx;
	int i = 0;
	while (i < self->screen->size.x / 4)
	{
		int	j = 0;
		while (j < self->screen->size.y / 4)
		{
			mlx_pixel_put(mlx, win, i + offset.x, j + offset.y, bg_color);
			j++;
		}
		i++;
	}
	current_line = 8 + offset.y * 2;
	int	left_margin = offset.x * 2;
	mlx_string_put(self->mlx, self->screen->win, left_margin, current_line, txt_color, double_to_str(self->camera.center.x));
	current_line += 16;
	mlx_string_put(self->mlx, self->screen->win, left_margin, current_line, txt_color, ft_itoa(self->iterator_data.max_iteration));
	current_line += 16;

}
