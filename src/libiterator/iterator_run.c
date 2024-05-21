#include"math.h"
#include"libiterator.h"
#include"libftprintf.h"
// computes z0^n + c, where n and c are read from the fields of self.
/*
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
*/
#include<stdio.h>
static void iterator_run_once(t_iterator *self, t_pt *z)
{
	t_pt	pt;

	pt.x = z->x * z->x - z->y * z->y;
	pt.y = 2 * z->x * z->y;
	pt.x += self->c.x;
	pt.y += self->c.y;
	*z = pt;
}

double	iterator_run(t_iterator *self)
{
	double	i;
	t_pt	z;

	z = self->z0;
	i = 0;
	while ((int) i < self->max_iteration)
	{
		//ft_printf("%i\n", (int) i);
		z = self->f(z);
		iterator_run_once(self, &z);
		if (z.x * z.x + z.y * z.y  > self->r) 
			break ;
		i += 1;
	}
	//printf("b4 %f\n", i);
	double abs_z = z.x * z.x + z.y * z.y;
	if ((int) i < self->max_iteration)
	{
		//double j = i;
		i = i + 1 - log(log(abs_z)) / log(2);
	//	printf("after %f\n", i);
	//	printf("diff %f\n", j - i);
	}
	return (i);
}
