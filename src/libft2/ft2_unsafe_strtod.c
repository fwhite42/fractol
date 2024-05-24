/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft2_unsafe_strtod.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/22 10:15:04 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/22 13:38:35 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

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
	{
		if (*str == '.' && decimal_switch == 0)
		{
			decimal_switch = 1;
		}
		else if (*str != '.')
		{
			integer_part *= 10;
			integer_part += *str - '0';
			if (decimal_switch == 1)
				decimal_part++;
		}
		str++;
	}
	return (sign * integer_part / pow(10, decimal_part));
}
