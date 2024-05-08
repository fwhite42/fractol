#include"liberror.h"
#include"error.h"
#include<stdlib.h>

void error_fatal(char *message, int value)
{
	error_log(message, value);
	exit(value);
}
