#include"libcollectible.h"
#include"stdlib.h"

void	collectible_destroy(void *self)
{
	free(self);
}
