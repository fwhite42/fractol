#ifndef LIBITERATOR_H
# define LIBITERATOR_H

# include"libcplx.h"

typedef struct s_iterator	t_iterator;
typedef void			(*t_iterator_fn)(t_iterator *self, t_pt);

int				iterator_run(t_iterator *self);
void				iterator_init(t_iterator *self);
void				iterator_julia(t_iterator *self, t_pt pt);
void				iterator_mandelbrot(t_iterator *self, t_pt pt);

struct s_iterator
{
	t_pt	z0;
	t_pt	c;
	double	r;
	double	n;
	t_pt	(*f)(t_pt pt);
	int	max_iteration;
};

#endif
