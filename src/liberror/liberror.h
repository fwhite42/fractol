#ifndef LIBERROR_H
# define LIBERROR_H

#define ERROR_FOOTER	"\x1B[0m\n"
#define	ERROR_STYLE	"\x1B[31m\x1B[1m\x1B[5m"
#define	ERROR_HEADER	"Error\n"

typedef struct s_error
{
	int		value;
	char		*message;
}	t_error;

// Constructor

void	*error_create(char *message, int value);
// Printer
void	error_print(void *self);

// Getters
int	error_value(void *self);
char	*error_message(void *self);

// Setters
void	error_set_message(void *self, char *error_message);
void	error_set_value(void *self, int error_value);

// Error
void	error_log(char *message, int value);
void	error_fatal(char *message, int value);
#endif
