#include"libfractol.h"
#include"libft.h"

t_fractol	*fractol_create_null(void)
{
	void	*self;

	self = ft_calloc(1, sizeof(t_fractol));
	return (self);
}
