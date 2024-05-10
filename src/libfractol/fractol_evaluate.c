#include"libfractol.h"
#include"libiterator.h"

int	fractol_evaluate(t_fractol *self, t_pt pt)
{
	t_iterator	iterator;

	iterator_init(&iterator);
	iterator.n = 4;
	self->iterator(&iterator, pt);
	return (iterator_run(&iterator));
}
