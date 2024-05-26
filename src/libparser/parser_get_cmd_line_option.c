#include"libparser.h"
#include"libft.h"

#include<stdio.h>

char	*parser_get_cmd_line_option(t_parser *self, char *key)
{
	int	i;

	i = 0;
	while (i < self->nbr_of_options)
	{
		if (self->options == NULL || self->options[i].key == NULL)
			break ;
		if (ft_strncmp(self->options[i].key, key, ft_strlen(key) + 1) == 0)
		{
			return (self->options[i].value);
		}
		i++;
	}
	return (NULL);
}
