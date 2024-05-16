#include"liberror.h"
#include"libft.h"
#include<stdlib.h>

void *error_create(char *error_message, int error_value)
{
	void	*this;

	this = ft_calloc(1, sizeof(t_error));
	if (this != NULL)
	{	error_set_message(this, error_message);
		error_set_value(this, error_value);
	}
	return (this);
}
