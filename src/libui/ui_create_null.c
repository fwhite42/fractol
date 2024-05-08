#include"libui.h"
#include"libft.h"

t_ui	*ui_create_null(void)
{
	void	*self;

	self = ft_calloc(1, sizeof(t_ui));
	return (self);
}
