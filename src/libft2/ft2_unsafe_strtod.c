/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft2_unsafe_strtod.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 10:15:04 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/27 10:41:07 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

static void	_task(char **str, int *sw, long long *ipart, long long *dpart);

double	ft2_unsafe_strtod(char *str)
{
	long long	integer_part;
	long long	decimal_part;
	int			decimal_switch;
	int			sign;

	integer_part = 0;
	decimal_part = 0;
	decimal_switch = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != 0 && (isdigit(*str) || *str == '.'))
		_task(&str, &decimal_switch, &integer_part, &decimal_part);
	return (sign * integer_part / pow(10, decimal_part));
}

static void	_task(char **str, int *sw, long long *ipart, long long *dpart)
{
	if (**str == '.' && *sw == 0)
		*sw = 1;
	else if (**str != '.')
	{
		*ipart *= 10;
		*ipart += **str - '0';
		if (*sw == 1)
			(*dpart)++;
	}
	(*str)++;
}
