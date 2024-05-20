/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser_parse_cmd_line_options.c                         4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 14:41:46 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/16 18:25:10 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libparser.h"
#include"libft.h"
#include"stddef.h"
#include"liberror.h"
#include"libftprintf.h"

static t_cmd_line_option _parse_one_option(char *option)
{
	t_cmd_line_option	cmd_line_option;
	char				**split;

	cmd_line_option.key = NULL;
	cmd_line_option.value = NULL;
	if (option == NULL)
		return (cmd_line_option);
	if (option[0] == '-' && option[1] == '-')
	{
		split = ft_split(option + 2, '=');
		cmd_line_option.key = split[0];
		cmd_line_option.value = split[1];
		free(split);
	}
	return (cmd_line_option);
}

void	parser_parse_cmd_line_options(t_parser *self, int ac, char **av)
{
	int	i;
	t_cmd_line_option	*options;

	self->nbr_of_options = 0;
	if (ac < 2)
	{
		self->options = NULL;
		return ;
	}
	options = ft_calloc(ac - 1, sizeof (t_cmd_line_option));
	if (options == NULL)
		error_fatal("Out of memory", -42);
	i = 1;
	while (i < ac)
	{
		options[i - 1] = _parse_one_option(av[i]);
		self->nbr_of_options++;
		i++;
	}
	self->options = options;
}
