#include"liberror.h"

void	error_log(char *message, int value)
{
	t_error error;
	
	error_set_message(&error, message);
	error_set_value(&error, value);
	error_print(&error);
}
