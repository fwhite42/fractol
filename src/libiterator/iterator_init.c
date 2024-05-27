/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   iterator_init.c                                         4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 01:27:45 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 01:42:07 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libiterator.h"
#include"libft.h"

static t_pt	id(t_pt pt)
{
	return (pt);
}

void	iterator_init(t_iterator *self)
{
	ft_bzero(self, sizeof(t_iterator));
	self->z0 = cplx_zero();
	self->c = (t_pt){1, 1};
	self->r = 2 * 2;
	self->n = 2;
	self->f = id;
	self->max_iteration = 64;
	self->anti_alias = 1;
}
