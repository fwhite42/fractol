#include"libfractol.h"
#include"libiterator.h"
#include"math.h"

double	fractol_evaluate(t_fractol *self, t_pt pt)
{
	double			iterations;
	double		scale;

	scale = self->camera.size.x / self->screen->size.x;
	//iterator_init(&(self->iterator_data));
	self->iterator(&(self->iterator_data), pt);
	iterations = iterator_run(&self->iterator_data);
	if (iterations == self->iterator_data.max_iteration)
		return (-1);
	else
		return (iterations);
}
