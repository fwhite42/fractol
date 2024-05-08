#ifndef LIBUI_H
# define LIBUI_H

typedef	struct s_ui
{
	void		*mlx;
	void		*win;
	void		*img;
}	t_ui;

t_ui	*ui_create_null(void);
t_ui	*ui_create(int width, int height);
void	ui_destroy(t_ui *self);
#endif
