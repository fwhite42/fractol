#include"libcollectible.h"

int	collectible_key(void *self)
{
	return (((t_collectible *)self)->key);
}
