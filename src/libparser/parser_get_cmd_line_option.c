/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser_get_cmd_line_option.c                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/27 02:42:13 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 02:42:25 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libparser.h"
#include"libft.h"

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
