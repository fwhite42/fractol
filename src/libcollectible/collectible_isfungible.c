#include"libcollectible.h"

int	collectible_isfungible(void *self)
{
	return (((t_collectible *)self)->isfungible);
}
