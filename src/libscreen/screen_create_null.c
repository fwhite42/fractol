#include"libscreen.h"
#include"libft.h"

t_screen	*screen_create_null(void)
{
	t_screen	*self;

	self = ft_calloc(1, sizeof(t_screen));
	return (self);
}
