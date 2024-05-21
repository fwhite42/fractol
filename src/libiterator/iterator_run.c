/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   iterator_run.c                                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/21 12:12:31 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/21 12:32:29 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"math.h"
#include"libiterator.h"
#include"libftprintf.h"

static void	iterator_run_once_general(t_iterator *self, t_pt *z0)
{
	double	x;
	double	y;

	x = 0;
	x += pow(z0->x, 2);
	x += pow(z0->y, 2);
	x = pow(x, self->n / 2);
	x *= cos(self->n * atan2(z0->y, z0->x));
	x += self->c.x;
	y = 0;
	y += pow(z0->x, 2);
	y += pow(z0->y, 2);
	y = pow(y, self->n / 2);
	y *= sin(self->n * atan2(z0->y, z0->x));
	y += self->c.y;
	*z0 = (t_pt) {x, y};
}

static void iterator_run_once(t_iterator *self, t_pt *z)
{
	t_pt	pt;

	if (self->n > 2)
		return iterator_run_once_general(self, z);
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
		z = self->f(z);
		iterator_run_once(self, &z);
		if (z.x * z.x + z.y * z.y  > self->r) 
			break ;
		i += 1;
	}
	if ((int) i < self->max_iteration && self->anti_alias == 1)
	{
		i = i + 1 - log(log(z.x * z.x + z.y * z.y)) / log(2);
	}
	return (i);
}
