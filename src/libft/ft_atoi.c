/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_atoi.c                                               4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/05/11 19:50:58 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/05/18 13:43:02 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static inline int	ft_isspace(char c)
{
	if (c == 11 || c == 32 || c == 9 || c == 10 || c == 13 || c == 12)
		return (1);
	return (0);
}

static void	consume_digit(const char *digit, int *nbr, int *error)
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

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;
	int	error;

	nbr = 0;
	sign = 1;
	error = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_strlen(str) >= 11 && ft_strncmp("-2147483648", str, 11) == 0)
	{
		if (!ft_isdigit(str[11]))
			return (-2147483648);
	}
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (ft_isdigit(*str))
		consume_digit(str++, &nbr, &error);
	return (sign * nbr);
}
