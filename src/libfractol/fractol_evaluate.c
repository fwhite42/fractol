#include"libfractol.h"
#include"libiterator.h"

int	fractol_evaluate(t_fractol *self, t_pt pt)
{
	t_iterator	iterator;
	int			iterations;

	iterator_init(&iterator);
	iterator.max_iteration = 16 * 16 / (self->camera.size.x / 4);
	self->iterator(&iterator, pt);
	iterations = iterator_run(&iterator);
	if (iterations == iterator.max_iteration)
		return (-1);
	else
		return (iterations);
}
