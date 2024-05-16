#include "liberror.h"

void	error_set_value(void *self, int value) {
	if (self)
		((t_error *)self)->value = value;
}
