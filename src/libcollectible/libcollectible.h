#ifndef LIBCOLLECTIBLE_H
# define LIBCOLLECTIBLE_H

typedef enum e_collectible_subtype
{
	COIN,
}	t_collectible_subtype;

// Struct
typedef struct s_collectible
{
	int	isfungible;
	int	key;
	int	value;
}	t_collectible;

// Getters
int		collectible_key(void *self);
int		collectible_value(void *self);
int		collectible_isfungible(void *self);

// Setters
void		collectible_set_key(void *self, int key);
void		collectible_set_value(void *self, int value);
void		collectible_set_isfungible(void *self, int isfungible);

#include"libobject.h"

// Collider
void		collectible_collide(t_collision_data input);

// Execution
// No - Execution
#endif
