#include"libcollectible.h"

void	collectible_set_value(void *self, int value)
{
	((t_collectible *)self)->value = value;
}
