/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libparser.h                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/16 14:31:51 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 02:42:48 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPARSER_H
# define LIBPARSER_H

# include"libcplx.h"

typedef struct s_cmd_line_option	t_cmd_line_option;
typedef struct s_parser				t_parser;

void	parser_parse_cmd_line_options(t_parser *self, int ac, char **av);
char	*parser_get_cmd_line_option(t_parser *self, char *key);
t_pt	parser_parse_r2_pt(char *str, char sep);
void	parser_print(t_parser *self);
void	parser_destroy(t_parser *self);

struct s_parser
{
	t_cmd_line_option	*options;
	int					nbr_of_options;
};

struct s_cmd_line_option
{	
	char	*key;
	char	*value;
};

#endif
