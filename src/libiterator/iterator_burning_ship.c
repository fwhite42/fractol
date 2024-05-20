#include"libiterator.h"
#include"libcplx.h"

static t_pt bs(t_pt z)
{
	if (z.x < 0)
		z.x *= -1;
	if (z.y < 0)
   		z.y *= -1;	   
	return (z);
}

void iterator_burning_ship(t_iterator *self, t_pt pt)
{
	self->c = pt;
	self->f = bs;
}
