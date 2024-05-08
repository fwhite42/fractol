#include"liberror.h"
#include"libftprintf.h"

void error_print(void *self)
{
	t_error	*error;
	char	*itemsym;
	
	itemsym = " * ";
	error = (t_error *)self;
	ft_printf(ERROR_STYLE);
	ft_printf(ERROR_HEADER);
	ft_printf("%sValue\t-> %i\n", itemsym,error->value);
	ft_printf("%sMessage\t-> %s\n", itemsym,error->message);
	ft_printf(ERROR_FOOTER);

}
