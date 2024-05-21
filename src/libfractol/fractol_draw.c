#include"libfractol.h"
#include"libcamera.h"
#include"libscreen.h"
#include"libcolor.h"
#include<math.h>
#include<stdio.h>
#include"libmlx.h"
#include"libft.h"
#include"liberror.h"

static int	compute_color(int color_type, int color_source, double color_id)
{
	int	color;

	color = 0;
	if (color_type == 0)
		color = pow(color_id, 3) + (2 * color_id * color_source) + 1;
	else if (color_type == 1)
		color = pow(color_id, 2);
	else
		error_fatal("Invalid color type", -42);
	return (color);
}

static int compute_pretty_color(int type, int source, double id)
{
	double	t;
	int		color1;
	int		color2;

	if (id == -1)
		return (id);
	color1 = compute_color(type, source, floor(id));
	color2 = compute_color(type, source, floor(id) + 1);
	t = id - floor(id);
	if (color1 != color2)
		return (color_interpolate(color1, color2, t));
	else
		return (color1);
}


static void	fractol_draw_pt(t_fractol *self, t_pt screen_pt)
{
	t_pt	pt;
	double	color_id;
	int		color;
	
	pt = camera_rescale(&(self->camera), self->screen, screen_pt);
	pt = camera_transform(&(self->camera), pt);
	pt = camera_translate(&(self->camera), pt);
	color_id = fractol_evaluate(self, pt);
	if (color_id == -1)
			return ;
	color = compute_pretty_color(self->color_type, self->color_source, color_id);
	pt.x -= self->camera.center.x;
	pt.y -= self->camera.center.y;
	screen_draw_px(self->screen, screen_pt, color);
}

char	*double_to_str(double x)
{
	char	*nbr;
	char	*tmp[2];
	int		integer_part;
	double	decimal_part;
	int		is_neg;

	printf("center.x = %f\n", x);
	is_neg = 0;
	if (x < 0)
	{
		is_neg = 1;
		x = -x;
	}
	integer_part = floor(x);
	decimal_part = floor(fabs((x - integer_part)) * 1000000000);
	tmp[1] = ft_itoa(integer_part);
	tmp[0] = ft_strjoin(tmp[1], ".");
	free(tmp[1]);
	tmp[1] = ft_itoa(floor(decimal_part));
	nbr = ft_strjoin(tmp[0], tmp[1]);
	free(tmp[1]);
	free(tmp[0]);
	if (is_neg)
	{
		tmp[0] = ft_strjoin("-", nbr);
		free(nbr);
		nbr = tmp[0];
	}
	return (nbr);
}

typedef struct s_mlxconsole	t_mlxconsole;

struct s_mlxconsole
{
	void		*mlx;
	void		*win;
	int			bg_color;
	int			txt_color;
	t_pt		size;
	t_pt		offset;
	t_pt		cursor;
};

t_mlxconsole	mlxconsole_default(t_fractol *self)
{
	t_mlxconsole	console;

	console.mlx = self->mlx;
	console.win = self->screen->win;
	console.size.x = self->screen->size.x / 4;	
	console.size.y = self->screen->size.y / 4;	
	if (console.size.y < 150)
		console.size.y = 150;
	console.offset.x = self->screen->size.x / 128;
	console.offset.y = self->screen->size.y / 128;
	console.bg_color = 0x9b9b9b00;
	console.txt_color = 0x00ffffff;
	console.cursor.x = console.offset.x * 2;
	console.cursor.y = 8 + console.offset.y * 2;
	return (console);
}

void	mlxconsole_draw(t_mlxconsole *self)
{
	int		i;
	int		j;
	int		pos_x;
	int		pos_y;
	
	i = 0;
	while (i < self->size.x)
	{
		j = 0;
		while (j < self->size.y)
		{
			pos_x = i + self->offset.x;
			pos_y = j + self->offset.y;
			mlx_pixel_put(self->mlx, self->win, pos_x, pos_y, self->bg_color);
			j++;
		}
		i++;
	}
}

void	mlxconsole_write(t_mlxconsole *self, char *str)
{
	t_pt	pos;

	pos = self->cursor;
	mlx_string_put(self->mlx, self->win, pos.x, pos.y, self->txt_color, str);
}

void	mlxconsole_write_info_line(t_mlxconsole *self, char *key, char *valye)
{
	mlxconsole_write(self, key);
	self->cursor.x += 24 * 8;
	mlxconsole_write(self, valye);
	self->cursor.x -= 24 * 8;
	self->cursor.y += 16;
}

void	fractol_draw(t_fractol *self)
{
	t_mlxconsole	console;
	char			*data;

	console = mlxconsole_default(self);
	screen_foreach_px(self->screen, fractol_draw_pt, self);
	screen_refresh(self->screen, self->mlx);	
	mlxconsole_draw(&console);
	mlxconsole_write_info_line(&console, "> Camera Information", "");
	data = double_to_str(self->camera.center.x);
	mlxconsole_write_info_line(&console, " camera x          :=", data);
	free(data);
	data = double_to_str(self->camera.center.y);
	mlxconsole_write_info_line(&console, " camera y          :=", data);
	free(data);
	data = double_to_str(self->camera.size.x);
	mlxconsole_write_info_line(&console, " camera width      :=", data);
	free(data);
	data = double_to_str(self->camera.size.y);
	mlxconsole_write_info_line(&console, " camera height     :=", data);
	free(data);
	mlxconsole_write_info_line(&console, "", "");
	mlxconsole_write_info_line(&console, "> Iterator Data", "");
	data = self->fractal_name;
	mlxconsole_write_info_line(&console, " fractal name      :=", data);
	data = ft_itoa(self->iterator_data.max_iteration);
	mlxconsole_write_info_line(&console, " max iteration     :=", data);
	free(data);
	data = double_to_str(self->iterator_data.n);
	mlxconsole_write_info_line(&console, " iterator exponent :=", data);
	free(data);
	if (self->iterator_data.anti_alias)
		data = "active";
	else
		data = "inactive";
	mlxconsole_write_info_line(&console, " anti alias        :=", data);
}
