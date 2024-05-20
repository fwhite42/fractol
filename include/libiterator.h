/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libiterator.h                                           4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 12:44:19 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/18 19:46:48 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBITERATOR_H
# define LIBITERATOR_H

# include"libcplx.h"

typedef struct s_iterator	t_iterator;
typedef void				(*t_iterator_fn)(t_iterator *self, t_pt);

// Sets the default iterator pre-config
void				iterator_init(t_iterator *self);

// Exectues the iterator
double				iterator_run(t_iterator *self);

// Sets the config for supported fractals
void				iterator_julia(t_iterator *self, t_pt pt);
void				iterator_mandelbrot(t_iterator *self, t_pt pt);
void				iterator_burning_ship(t_iterator *self, t_pt pt);

// Explict definition of the iterator structor
struct s_iterator
{
	t_pt	(*f)(t_pt pt);
	t_pt	z0;
	t_pt	c;
	double	r;
	double	n;
	int		max_iteration;
};

#endif
