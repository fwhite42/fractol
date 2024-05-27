/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libcamera.h                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 01:23:19 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:23:22 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

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
