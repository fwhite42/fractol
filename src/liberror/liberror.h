#ifndef LIBERROR_H
# define LIBERROR_H
# define LIB_ERROR_HEADER "Error\n---\n"

typedef struct s_error
{
	int		value;
	char		*message;
}	t_error;

void	*error_create(char *message, int value);
void	error_print(void *self);
void	error_set_message(void *self, char *error_message);
void	error_set_value(void *self, int error_value);
void	error_log(char *message, int value);
void	error_fatal(char *message, int value);
#endif
