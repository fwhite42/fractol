/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser_parse_r2_pt.c                                    4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/18 13:29:24 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/21 19:11:49 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static inline int	ft_isspace(char c)
{
	if (c == 11 || c == 32 || c == 9 || c == 10 || c == 13 || c == 12)
		return (1);
	return (0);
}

static void	consume_digit(const char *digit, double *nbr, double *error)
{
	if (*error == 1)
		return ;
	if ((*nbr * 10) < *nbr)
	{
		*nbr = 0;
		*error = 1;
		return ;
	}
	*nbr *= 10;
	if (*nbr + (*digit - '0') < *nbr)
	{
		*nbr = 0;
		*error = 1;
		return ;
	}
	*nbr += *digit - '0';
}

static double ft_atol(const char *str)
{
	int			sign;
	double		nbr;
	double		error;

	nbr = 0;
	sign = 1;
	error = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (ft_isdigit(*str))
		consume_digit(str++, &nbr, &error);
	return (sign * nbr);
}


static double parser_parse_double(char *str)
{
	char	*long_int_str;
	char	**split;
	double	nbr;

	split = ft_split(str, '.');
	long_int_str = ft_strjoin(split[0], split[1]);
	nbr  = ft_atol(long_int_str);
	nbr /= ft_strlen(split[1]);
 	free(split[0]);
	free(split[1]);
	free(split);
	return (nbr);
}

#include"libcplx.h"

t_pt	parser_parse_r2_pt(char *data, char sep)
{
	char	**split;
	t_pt	pt;

	split = ft_split(data, sep);
	pt.x = parser_parse_double(split[0]);
	pt.y = parser_parse_double(split[1]);
	free(split[0]);
	free(split[1]);
	free(split);
	return (pt);
}
