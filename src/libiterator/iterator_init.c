#include"libiterator.h"
#include"libft.h"

static t_pt	id(t_pt pt)
{
	return (pt);
}

void	iterator_init(t_iterator *self)
{
	ft_bzero(self, sizeof(t_iterator));
	self->z0 = (t_pt) {0, 0};
	self->c = (t_pt) {1, 1};
	self->r = 2 * 2;
	self->n = 2;
	self->f = id;
	self->max_iteration = 64;
}
