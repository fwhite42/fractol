/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   iterator_burning_ship.c                                 4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 01:29:13 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:31:55 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libiterator.h"
#include"libcplx.h"

static t_pt	bs(t_pt z)
{
	if (z.x < 0)
		z.x *= -1;
	if (z.y < 0)
		z.y *= -1;
	return (z);
}

void	iterator_burning_ship(t_iterator *self, t_pt pt)
{
	self->c = pt;
	self->f = bs;
}
