#include"libcollectible.h"
#include"libft.h"

void	*collectible_create_null(void)
{
	void	*self;

	self = ft_calloc(1, sizeof(t_collectible));
	return (self);
}
