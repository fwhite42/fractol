#include"libcollectible.h"
#include"libobject.h"
#include"libgame.h"
#include"libplayer.h"
#include"liberror.h"

void	collectible_collide(t_collision_data input)
{
	int	new_balance;

	if (object_type(input.caller) == PLAYER_TYPE)
	{
		new_balance = player_balance(input.caller) + 1;
		player_set_balance(input.caller, new_balance);	
	}
	else
		error_fatal("Invalid coin callision caller", 0);
}
