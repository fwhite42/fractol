#include"libcollectible.h"

void	collectible_set_isfungible(void *self, int isfungible)
{
	((t_collectible *)self)->isfungible = isfungible;
}
