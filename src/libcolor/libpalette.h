// Color is a 4-dimensional point whose coordinates are doubles

struct s_rgbapt
{
	double	r;
	double	g;
	double	b;
	double	a;
};


t_rgbapt	color_to_rgbapt(int color);
int			color_from_rgbapt(int color);
int			color_interpolate(int color1, int color2, double t);
int			*color_palette_create(int size, int (*color_picker)(double x));
int			*color_palette_destroy(int *palette);
