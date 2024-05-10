#include"math.h"
#include"libiterator.h"

// computes z0^n + c, where n and c are read from the fields of self.
static t_pt	iterator_run_once(t_iterator *self, t_pt z0)
{
	double	x;
	double	y;

	x = 0;
	x += pow(z0.x, 2);
	x += pow(z0.y, 2);
	x = pow(x, self->n / 2);
	x *= cos(self->n * atan2(z0.y, z0.x));
	x += self->c.x;
	y = 0;
	y += pow(z0.x, 2);
	y += pow(z0.y, 2);
	y = pow(y, self->n / 2);
	y *= sin(self->n * atan2(z0.y, z0.x));
	y += self->c.y;
	return ((t_pt) {x, y});
}

int	iterator_run(t_iterator *self)
{
	int	i;
	t_pt	z;

	z = self->z0;
	i = 0;
	while (i < self->max_iteration)
	{
		z = iterator_run_once(self, self->f(z));
		if (cplx_abs(z) > self->r)
			break;
		else
			i++;
	}
	return (i);
}
