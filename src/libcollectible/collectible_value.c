#include"libcollectible.h"

int	collectible_value(void *self)
{
	return (((t_collectible *)self)->value);
}
