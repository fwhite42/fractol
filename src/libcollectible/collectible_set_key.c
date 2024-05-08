#include"libcollectible.h"

void	collectible_set_key(void *self, int key)
{
	((t_collectible *)self)->key = key;
}
