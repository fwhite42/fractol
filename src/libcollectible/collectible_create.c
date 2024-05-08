#include"libcollectible.h"

t_collectible	collectible_create(int isfungible, int key, int value)
{
	t_collectible	self;

	self.isfungible = isfungible;
	self.key = key;
	self.value = value;
	return (self);
}
