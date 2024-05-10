#ifndef LIBCAMERA_H
# define LIBCAMERA_H
# include"libscreen.h"
# include"libcplx.h"

typedef struct s_camera	t_camera;

t_pt	camera_rescale(t_camera *self, t_screen *screen, t_pt pt);
t_pt	camera_transform(t_camera *self, t_pt pt);
t_pt	camera_translate(t_camera *self, t_pt pt);
void	camera_zoom(t_camera *self, t_screen *screen, t_pt spt, double zoom);

struct s_camera
{
	t_pt		size;
	t_pt		center;
};
#endif
